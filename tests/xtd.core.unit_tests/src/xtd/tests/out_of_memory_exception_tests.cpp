#include <xtd/out_of_memory_exception.h>
#include <xtd/tunit/assert.h>
#include <xtd/tunit/test_class_attribute.h>
#include <xtd/tunit/test_method_attribute.h>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(out_of_memory_exception_tests) {
    inline static bool stack_trace_enabled = false;
    inline static std::locale previous_locale;
  public:
    static void test_initialize_(test_initialize) {
      previous_locale = std::locale::global(std::locale("en_US.UTF-8"));
      stack_trace_enabled = system_exception::enable_stack_trace();
      system_exception::enable_stack_trace(false);
    }
    
    static void test_cleanup_(test_cleanup) {
      std::locale::global(previous_locale);
      system_exception::enable_stack_trace(stack_trace_enabled);
    }
    
    void test_method_(default_creator) {
      out_of_memory_exception e;
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::is_empty(e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(0, e.error_code().value(), csf_);
      assert::are_equal(0U, e.line_number(), csf_);
      assert::is_empty(e.member_name(), csf_);
      assert::are_equal("Insufficient memory to continue the execution of the program", e.message(), csf_);
      assert::are_equal("xtd::out_of_memory_exception", e.name(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::are_equal("xtd::out_of_memory_exception : Insufficient memory to continue the execution of the program", e.to_string(), csf_);
      assert::are_equal("Insufficient memory to continue the execution of the program", e.what(), csf_);
    }
    
    void test_method_(default_creator_with_current_stack_frame) {
      auto info = current_stack_frame_;
      out_of_memory_exception e(info);
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(0, e.error_code().value(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Insufficient memory to continue the execution of the program", e.message(), csf_);
      assert::are_equal("xtd::out_of_memory_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::out_of_memory_exception : Insufficient memory to continue the execution of the program\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Insufficient memory to continue the execution of the program", e.what(), csf_);
    }
    
    void test_method_(creator_with_empty_message) {
      out_of_memory_exception e("");
      assert::are_equal(0, e.error_code().value(), csf_);
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::is_empty(e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(0U, e.line_number(), csf_);
      assert::is_empty(e.member_name(), csf_);
      assert::is_empty(e.message(), csf_);
      assert::are_equal("xtd::out_of_memory_exception", e.name(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::are_equal("xtd::out_of_memory_exception", e.to_string(), csf_);
      assert::are_equal("xtd::out_of_memory_exception", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_empty_and_stack_frame) {
      auto info = current_stack_frame_;
      out_of_memory_exception e("", info);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(0, e.error_code().value(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::is_empty(e.message(), csf_);
      assert::are_equal("xtd::out_of_memory_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::out_of_memory_exception\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("xtd::out_of_memory_exception", e.what(), csf_);
    }
    
    void test_method_(creator_with_message) {
      out_of_memory_exception e("Test excpetion message.");
      assert::are_equal(0, e.error_code().value(), csf_);
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::is_empty(e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(0U, e.line_number(), csf_);
      assert::is_empty(e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::out_of_memory_exception", e.name(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::are_equal("xtd::out_of_memory_exception : Test excpetion message.", e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_and_stack_frame) {
      auto info = current_stack_frame_;
      out_of_memory_exception e("Test excpetion message.", info);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(0, e.error_code().value(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::out_of_memory_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::out_of_memory_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_error_and_stack_frame) {
      auto info = current_stack_frame_;
      out_of_memory_exception e("Test excpetion message.", std::error_code(EBUSY, std::generic_category()), info);
      assert::are_equal(EBUSY, e.error_code().value(), csf_);
      assert::are_equal(std::generic_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::out_of_memory_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::out_of_memory_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_help_link_and_stack_frame) {
      auto info = current_stack_frame_;
      out_of_memory_exception e("Test excpetion message.", "https://gammasoft71.github.io/xtd/reference_guides/latest/", info);
      assert::are_equal(0, e.error_code().value(), csf_);
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::are_equal("https://gammasoft71.github.io/xtd/reference_guides/latest/", e.help_link(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::out_of_memory_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::out_of_memory_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_error_help_link_and_stack_frame) {
      auto info = current_stack_frame_;
      out_of_memory_exception e("Test excpetion message.", std::error_code(EBUSY, std::generic_category()), "https://gammasoft71.github.io/xtd/reference_guides/latest/", info);
      assert::are_equal(EBUSY, e.error_code().value(), csf_);
      assert::are_equal(std::generic_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::are_equal("https://gammasoft71.github.io/xtd/reference_guides/latest/", e.help_link(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::out_of_memory_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::out_of_memory_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_and_inner_exception) {
      system_exception inner_exception;
      out_of_memory_exception e("Test excpetion message.", inner_exception);
      assert::are_equal(0, e.error_code().value(), csf_);
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::is_empty(e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(0U, e.line_number(), csf_);
      assert::is_empty(e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::out_of_memory_exception", e.name(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::are_equal("xtd::out_of_memory_exception : Test excpetion message.", e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_inner_exception_and_stack_frame) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      out_of_memory_exception e("Test excpetion message.", inner_exception, info);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(0, e.error_code().value(), csf_);
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::out_of_memory_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::out_of_memory_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_inner_exception_error_and_stack_frame) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      out_of_memory_exception e("Test excpetion message.", inner_exception, std::error_code(EBUSY, std::generic_category()), info);
      assert::are_equal(EBUSY, e.error_code().value(), csf_);
      assert::are_equal(std::generic_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::out_of_memory_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::out_of_memory_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_inner_exception_help_link_and_stack_frame) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      out_of_memory_exception e("Test excpetion message.", inner_exception, "https://gammasoft71.github.io/xtd/reference_guides/latest/", info);
      assert::are_equal(0, e.error_code().value(), csf_);
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::are_equal("https://gammasoft71.github.io/xtd/reference_guides/latest/", e.help_link(), csf_);
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::out_of_memory_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::out_of_memory_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_inner_exception_error_help_link_and_stack_frame) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      out_of_memory_exception e("Test excpetion message.", inner_exception, std::error_code(EBUSY, std::generic_category()), "https://gammasoft71.github.io/xtd/reference_guides/latest/", info);
      assert::are_equal(EBUSY, e.error_code().value(), csf_);
      assert::are_equal(std::generic_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::are_equal("https://gammasoft71.github.io/xtd/reference_guides/latest/", e.help_link(), csf_);
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::out_of_memory_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::out_of_memory_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(copy_constructor) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      out_of_memory_exception e = out_of_memory_exception("Test excpetion message.", inner_exception, std::error_code(EBUSY, std::generic_category()), "https://gammasoft71.github.io/xtd/reference_guides/latest/", info);
      assert::are_equal(EBUSY, e.error_code().value(), csf_);
      assert::are_equal(std::generic_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::are_equal("https://gammasoft71.github.io/xtd/reference_guides/latest/", e.help_link(), csf_);
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::out_of_memory_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::out_of_memory_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(copy_operator) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      out_of_memory_exception e;
      e = out_of_memory_exception("Test excpetion message.", inner_exception, std::error_code(EBUSY, std::generic_category()), "https://gammasoft71.github.io/xtd/reference_guides/latest/", info);
      assert::are_equal(EBUSY, e.error_code().value(), csf_);
      assert::are_equal(std::generic_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::are_equal("https://gammasoft71.github.io/xtd/reference_guides/latest/", e.help_link(), csf_);
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::out_of_memory_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::out_of_memory_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
  };
}