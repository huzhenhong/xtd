#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(collection_valid_is_empty_vector_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      std::vector<int> a = {1, 2, 3, 4};
      xtd::tunit::collection_valid::is_empty(a);
    }
  };
}

void test_(collection_valid_is_empty_vector_failed_tests, test_output) {
  auto [output, result] = run_test_("collection_valid_is_empty_vector_failed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  FAILED  collection_valid_is_empty_vector_failed_tests.test_case_failed\n"
    "    Expected: <empty>\n"
    "    But was:  < 1, 2, 3, 4 >\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(collection_valid_is_empty_vector_failed_tests, test_result) {
  auto [output, result] = run_test_("collection_valid_is_empty_vector_failed_tests.*");
  assert_value_(1, result);
}