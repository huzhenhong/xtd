#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(directory_valid_exists_string_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      auto d = io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data), "__xtd_test_directory_not_found__");
      xtd::tunit::directory_valid::exists(d);
    }
  };
}

void test_(directory_valid_exists_string_failed_tests, test_output) {
  auto [output, result] = run_test_("directory_valid_exists_string_failed_tests.*");
  #if defined (_WIN32)
  assert_value_("Start 1 test from 1 test case\n"
    "  FAILED  directory_valid_exists_string_failed_tests.test_case_failed\n"
    "    Expected: directory exists\n"
    "    But was:  \"C:\\ProgramData\\__xtd_test_directory_not_found__\"\n"
    "End 1 test from 1 test case ran.\n", output);
  #else
  assert_value_("Start 1 test from 1 test case\n"
    "  FAILED  directory_valid_exists_string_failed_tests.test_case_failed\n"
    "    Expected: directory exists\n"
    "    But was:  \"/usr/share/__xtd_test_directory_not_found__\"\n"
    "End 1 test from 1 test case ran.\n", output);
  #endif
}

void test_(directory_valid_exists_string_failed_tests, test_result) {
  auto [output, result] = run_test_("directory_valid_exists_string_failed_tests.*");
  assert_value_(1, result);
}