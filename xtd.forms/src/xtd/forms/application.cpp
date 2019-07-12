#include <chrono>
#include <xtd/xtd.io.hpp>
#include <xtd/environment.hpp>
#include "../../../include/xtd/forms/application.hpp"
#include "../../native/application_api.hpp"

bool xtd::forms::application::allow_quit() {
  return native::application_api::allow_quit();
}

std::string xtd::forms::application::common_app_data_path() {
  //std::string common_app_data_path = xtd::io::combine(xtd::environment::get_folder_path(xtd::environment::special_folder::common_application_data), company_name(), product_name(), product_version());
  //if (!xtd::io:directory::exists(common_app_data_path))
  //  xtd::io::directory::create_directory(common_app_data_path);
  //return commonApp_data_path;
  return "";
}

/*
xtd::microsoft::win32::registry_key xtd::forms::application::common_app_data_registry() {
  return xtd::microsoft::win32::registry::local_machine().create_sub_key("Software").create_sub_key(company_name()).create_sub_key(product_name()).create_sub_key(product_version());
}
 */

std::string xtd::forms::application::company_name() {
  if (!xtd::strings::is_empty(xtd::forms::application_informations::company_name())) return xtd::forms::application_informations::company_name();
  return xtd::io::path::get_file_name_without_extension(executable_path());
}

std::string xtd::forms::application::executable_path() {
  return xtd::environment::get_command_line_args()[0];
}

std::string xtd::forms::application::product_name() {
  if (!xtd::strings::is_empty(xtd::forms::application_informations::product_name())) return xtd::forms::application_informations::product_name();
  return xtd::io::path::get_file_name_without_extension(executable_path());
}

void xtd::forms::application::do_events() {
  native::application_api::do_events();
}

void xtd::forms::application::enable_visual_styles() {
  native::application_api::enable_visual_style();
}

void xtd::forms::application::exit() {
  native::application_api::exit();
}

void xtd::forms::application::run() {
  native::application_api::run();
}

void xtd::forms::application::run(const form& form) {
  native::application_api::main_form(form.__get_handle__());
  native::application_api::register_idle(application::on_idle);
  run();
}

xtd::delegate<void(const xtd::event_args&)> xtd::forms::application::idle;

void xtd::forms::application::on_idle() {
  using namespace std::chrono_literals;
  static std::chrono::high_resolution_clock::time_point lastIdleTime;
  if (std::chrono::high_resolution_clock::now() - lastIdleTime >= 100ms) {
    lastIdleTime = std::chrono::high_resolution_clock::now();
    xtd::forms::application::idle(xtd::event_args::empty);
  }
  if (!xtd::forms::application::idle.is_empty())
    native::application_api::do_idle();
}
