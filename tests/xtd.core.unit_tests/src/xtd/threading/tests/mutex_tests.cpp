#include <xtd/threading/mutex.h>
#include <xtd/xtd.tunit>
#include <utility>

using namespace xtd::threading;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(mutex_tests) {
  public:
    void test_method_(constructor) {
      auto m = mutex {};
      assert::are_not_equal(mutex::invalid_handle, m.handle(), csf_);
    }
    
    void test_method_(constructor_with_initially_owned_to_false_and_name) {
      auto m = mutex {false, "xtd_mutex_test"};
      assert::are_not_equal(mutex::invalid_handle, m.handle(), csf_);
    }
    
    void test_method_(copy_constructor) {
      auto m1 = mutex {};
      auto m2 = m1;
      assert::are_equal(m2.handle(), m1.handle(), csf_);
    }
    
    void test_method_(copy_constructor_with_initially_owned_to_false_and_name) {
      auto m1 = mutex {false, "xtd_mutex_test"};
      auto m2 = m1;
      assert::are_equal(m2.handle(), m1.handle(), csf_);
    }

    void test_method_(wait_one) {
      auto m = mutex {};
      assert::is_true(m.wait_one(), csf_);
    }

    void test_method_(wait_one_and_release_mutex) {
      auto m = mutex {};
      assert::is_true(m.wait_one(), csf_);
      assert::does_not_throw([&] {m.release_mutex();}, csf_);
    }

    void test_method_(wait_one_and_release_mutex_and_release_mutex) {
      auto m = mutex {};
      assert::is_true(m.wait_one(), csf_);
      assert::does_not_throw([&] {m.release_mutex();}, csf_);
      assert::does_not_throw([&] {m.release_mutex();}, csf_);
    }

    void test_method_(wait_one_and_wait_one_and_release_mutex) {
      auto m = mutex {};
      assert::is_true(m.wait_one(), csf_);
      assert::is_true(m.wait_one(), csf_);
      assert::does_not_throw([&] {m.release_mutex();}, csf_);
    }

    void test_method_(close_and_wait_one) {
      auto m = mutex {};
      m.close();
      assert::throws<object_closed_exception>([&] {m.wait_one();}, csf_);
    }

    void test_method_(close_and_release_mutex) {
      auto m = mutex {};
      m.close();
      assert::are_equal(mutex::invalid_handle, m.handle(), csf_);
      assert::throws<object_closed_exception>([&] {m.release_mutex();}, csf_);
    }
    
    void test_method_(signal_and_wait) {
      auto m1 = mutex {};
      auto m2 = mutex {};
      m1.wait_one();
      mutex::signal_and_wait(m1, m2);
    }
    
    void test_method_(wait_all) {
      auto m1 = mutex {};
      auto m2 = mutex {};
      auto m3 = mutex {};
      assert::is_true(mutex::wait_all({m1, m2, m3}), csf_);
    }
    
    void test_method_(wait_any) {
      auto m1 = mutex {};
      auto m2 = mutex {};
      auto m3 = mutex {};
      assert::are_equal(0ul, mutex::wait_any({m1, m2, m3}), csf_);
    }
  };
}