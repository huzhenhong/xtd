#include "../../../include/xtd/threading/mutex.h"
#include "../../../include/xtd/argument_out_of_range_exception.h"
#include "../../../include/xtd/object_closed_exception.h"
#include "../../../include/xtd/invalid_operation_exception.h"
#include "../../../include/xtd/io//io_exception.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/named_mutex.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <mutex>

using namespace xtd;
using namespace xtd::threading;

class mutex::mutex_base {
public:
  virtual ~mutex_base() = default;
  
  virtual intptr_t handle() const noexcept = 0;
  virtual void handle(intptr_t value) = 0;
  virtual bool create() = 0;
  virtual bool create(const ustring& name, bool& create_new) = 0;
  virtual void destroy() = 0;
  virtual bool signal(bool& io_error) = 0;
  virtual bool wait(int32_t milliseconds_timeout, bool& io_error) = 0;
};

class mutex::named_mutex : public mutex_base {
public:
  ~named_mutex() {destroy();}

  intptr_t handle() const noexcept override {
    return handle_;
  }
  
  void handle(intptr_t value) override {
    handle_ = value;
  }
  
  bool create() override {
    throw invalid_operation_exception {csf_};
  }
  
  bool create(const ustring& name, bool& create_new) override {
    name_ = name;
    handle_ = native::named_mutex::create(name, create_new);
    return handle_ != invalid_handle;
  }
  
  void destroy() override {
    if (handle_ == invalid_handle) return;
    native::named_mutex::destroy(handle_, name_);
    handle_ = invalid_handle;
  }
  
  bool signal(bool& io_error) override {
    io_error = false;
    return native::named_mutex::signal(handle_, io_error);
  }
  
  bool wait(int32_t milliseconds_timeout, bool& io_error) override {
    io_error = false;
    return native::named_mutex::wait(handle_, milliseconds_timeout, io_error);
  }
  
private:
  intptr_t handle_ = invalid_handle;
  ustring name_;
};

class mutex::unnamed_mutex : public mutex_base {
public:
  ~unnamed_mutex() {destroy();}

  intptr_t handle() const noexcept override {
    return reinterpret_cast<intptr_t>(handle_.get());
  }
  
  void handle(intptr_t value) override {
    handle_.reset(reinterpret_cast<std::recursive_timed_mutex*>(value));
  }

  bool create() override {
    handle_ = std::make_shared<std::recursive_timed_mutex>();
    return true;
  }
  
  bool create(const ustring& name, bool& create_new) override {
    throw invalid_operation_exception {csf_};
  }

  void destroy() override {
    if (!handle_) return;
    handle_.reset();
  }

  bool signal(bool& io_error) override {
    io_error = false;
    handle_->unlock();
    return true;
  }

  bool wait(int32_t milliseconds_timeout, bool& io_error) override {
    io_error = false;
    if (milliseconds_timeout != timeout::infinite) return handle_->try_lock_for(std::chrono::milliseconds {milliseconds_timeout});
    handle_->lock();
    return true;
  }
  
private:
  std::shared_ptr<std::recursive_timed_mutex> handle_;
};

mutex::mutex() : mutex(false) {
}

mutex::mutex(bool initially_owned) {
  bool created_new = false;
  create(initially_owned, created_new);
}

mutex::mutex(bool initially_owned, const ustring& name) : name_(name) {
  bool created_new = false;
  create(initially_owned, created_new);
}

mutex::mutex(bool initially_owned, const ustring& name, bool created_new) : name_(name) {
  create(initially_owned, created_new);
}

mutex::~mutex() {
  close();
}

intptr_t mutex::handle() const noexcept {
  return mutex_ ? mutex_->handle() : invalid_handle;
}

void mutex::handle(intptr_t value) {
  mutex_->handle(value);
}

void mutex::close() {
  if (mutex_.use_count() == 1) {
    mutex_->destroy();
    mutex_.reset();
  }
}

mutex mutex::open_existing(const ustring& name) {
  auto result = mutex{};
  if (!try_open_existing(name, result)) throw argument_exception {csf_};
  return result;
}

void mutex::release_mutex() {
  if (!signal()) throw io::io_exception {csf_};
}

bool mutex::try_open_existing(const ustring& name, mutex& result) noexcept {
  if (ustring::is_empty(name)) return false;
  auto new_mutex = mutex {};
  new_mutex.name_ = name;
  new_mutex.mutex_ = std::make_shared<mutex::named_mutex>();
  bool created_new = true;
  if (new_mutex.mutex_->create(new_mutex.name_, created_new)) return false;
  if (created_new) return false;
  result = new_mutex;
  return true;
}

bool mutex::signal() {
  if (!mutex_) throw object_closed_exception {csf_};
  bool io_error = false;
  auto result = mutex_->signal(io_error);
  if (io_error) throw io::io_exception {csf_};
  return result;
}

bool mutex::wait(int32_t milliseconds_timeout) {
  if (!mutex_) throw object_closed_exception {csf_};
  if (milliseconds_timeout < -1) throw argument_out_of_range_exception {csf_};
  bool io_error = false;
  auto result = mutex_->wait(milliseconds_timeout, io_error);
  if (io_error) throw io::io_exception {csf_};
  return result;
}

void mutex::create(bool initially_owned, bool& created_new) {
  created_new = true;
  if (name_.empty()) {
    mutex_ = std::make_shared<mutex::unnamed_mutex>();
    if (!mutex_->create()) throw io::io_exception(csf_);
  } else {
    mutex_ = std::make_shared<mutex::named_mutex>();
    if (!mutex_->create(name_, created_new)) throw io::io_exception(csf_);
  }
  if (initially_owned) wait_one();
}
