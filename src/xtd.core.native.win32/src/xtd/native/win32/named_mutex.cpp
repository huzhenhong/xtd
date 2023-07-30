#define UNICODE
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/named_mutex.h>
#include "../../../../include/xtd/native/win32/strings.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <Windows.h>
#undef max
#undef min

using namespace xtd::native;

intmax_t named_mutex::create(bool initially_owned, const std::string& name) {
  auto handle = CreateMutex(nullptr, initially_owned, win32::strings::to_wstring(name).c_str());
  return reinterpret_cast<intmax_t>(handle);
}

void named_mutex::destroy(intmax_t handle, const std::string& name) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) return;
  CloseHandle(reinterpret_cast<HANDLE>(handle));
}

intmax_t named_mutex::open(const std::string& name) {
  auto handle = OpenMutex(MUTEX_ALL_ACCESS, FALSE, win32::strings::to_wstring(name).c_str());
  return reinterpret_cast<intmax_t>(handle);
}

bool named_mutex::signal(intmax_t handle, bool& io_error) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) return !(io_error = true);
  io_error = ReleaseMutex(reinterpret_cast<HANDLE>(handle)) == FALSE;
  return !io_error;
}

bool named_mutex::wait(intmax_t handle, int_least32_t milliseconds_timeout, bool& io_error) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) return !(io_error = true);
  io_error = WaitForSingleObject(reinterpret_cast<HANDLE>(handle), milliseconds_timeout) == FALSE;
  return !io_error;
}