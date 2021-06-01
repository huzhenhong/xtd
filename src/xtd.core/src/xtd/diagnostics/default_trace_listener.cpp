#include "../../../include/xtd/diagnostics/default_trace_listener.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/debug.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/io/file.h>

using namespace std;
using namespace xtd::diagnostics;

default_trace_listener::default_trace_listener() : trace_listener("default") {
}

default_trace_listener::~default_trace_listener() {
  flush();
}

std::string default_trace_listener::log_file_name() const {
  return log_file_name_;
}

void default_trace_listener::log_file_name(const std::string log_file_name) {
  log_file_name_ = log_file_name;
}

void default_trace_listener::close() {
}

void default_trace_listener::flush_() {
  if (!message_line_.empty()) write_line("");
}

void default_trace_listener::write_(const std::string& message) {
  if (need_indent()) write_indent();
  message_line_ += message;
  if (!log_file_name_.empty()) xtd::io::file::append_all_text(log_file_name_, message);
}

void default_trace_listener::write_line_(const std::string& message) {
  write(message + "\n");
  native::debug::write_to_output(message_line_);
  message_line_ = "";
  need_indent(true);
}
