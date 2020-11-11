#include <xtd/xtd.strings>
#include <xtd/xtd.tunit>

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_wstring_boolean_format) {
  public:
    void test_method_(format_false_with_default_argument) {
      assert::are_equal(L"false", xtd::strings::format(L"{0}", false));
    }

    void test_method_(format_true_with_default_argument) {
      assert::are_equal(L"true", xtd::strings::format(L"{0}", true));
    }

    void test_method_(format_false_with_left_alignment) {
      assert::are_equal(L"     false", strings::format(L"{0,10}", false));
    }
    
    void test_method_(format_true_with_left_alignment) {
      assert::are_equal(L"      true", strings::format(L"{0,10}", true));
    }
    
    void test_method_(format_false_with_right_alignment) {
      assert::are_equal(L"false     ", strings::format(L"{0, -10}", false));
    }
    
    void test_method_(format_true_with_right_alignment) {
      assert::are_equal(L"true      ", strings::format(L"{0, -10}", true));
    }
    
    void test_method_(format_false_with_zero_alignment) {
      assert::are_equal(L"false", strings::format(L"{0,0}", false));
    }
    
    void test_method_(formatn_true_with_zer_alignment) {
      assert::are_equal(L"true", strings::format(L"{0,0}", true));
    }
    
    void test_method_(format_false_with_binary_argument) {
      assert::are_equal(L"0", xtd::strings::format(L"{0:b}", false));
    }
    
    void test_method_(format_true_with_binaryl_argument) {
      assert::are_equal(L"1", xtd::strings::format(L"{0:B}", true));
    }
    
    void test_method_(format_false_with_decimal_argument) {
      assert::are_equal(L"0", xtd::strings::format(L"{0:d}", false));
    }
    
    void test_method_(format_true_with_decimal_argument) {
      assert::are_equal(L"1", xtd::strings::format(L"{0:D}", true));
    }
    
    void test_method_(format_false_with_general_argument) {
      assert::are_equal(L"false", xtd::strings::format(L"{0:g}", false));
    }
    
    void test_method_(format_true_with_general_argument) {
      assert::are_equal(L"true", xtd::strings::format(L"{0:G}", true));
    }

    void test_method_(format_false_with_octal_argument) {
      assert::are_equal(L"0", xtd::strings::format(L"{0:o}", false));
    }
    
    void test_method_(format_true_with_octal_argument) {
      assert::are_equal(L"1", xtd::strings::format(L"{0:O}", true));
    }
    
    void test_method_(format_false_with_hexadecimal_argument) {
      assert::are_equal(L"0", xtd::strings::format(L"{0:x}", false));
    }
    
    void test_method_(format_true_with_hexadecimal_argument) {
      assert::are_equal(L"1", xtd::strings::format(L"{0:X}", true));
    }
    
    void test_method_(format_false_with_invalid_argument) {
      assert::throws<std::invalid_argument>([]{xtd::strings::format(L"{0:e}", true);});
    }
    
    void test_method_(format_true_with_invalid_argument) {
      assert::throws<std::invalid_argument>([]{xtd::strings::format(L"{0:z1}", true);});
    }
  };
}
