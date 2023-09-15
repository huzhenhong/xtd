#include <xtd/tunit/directory_valid>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../assert_unit_tests/assert_unit_tests.h"

namespace xtd::tunit::tests {
  class test_class_(directory_valid_does_not_exist_string_succeed_tests) {
  public:
    void test_method_(test_case_succeed) {
      auto d = io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data), "__xtd_test_directory_not_found__");
      xtd::tunit::directory_valid::does_not_exist(d);
    }
  };
}

void test_(directory_valid_does_not_exist_string_succeed_tests, test_output) {
  auto [output, result] = run_test_("directory_valid_does_not_exist_string_succeed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  SUCCEED directory_valid_does_not_exist_string_succeed_tests.test_case_succeed\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(directory_valid_does_not_exist_string_succeed_tests, test_result) {
  auto [output, result] = run_test_("directory_valid_does_not_exist_string_succeed_tests.*");
  assert_value_(0, result);
}
