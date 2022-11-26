#include "../../../include/xtd/forms/list_control.h"

using namespace xtd;
using namespace xtd::forms;

list_control::item::item(const xtd::ustring& value) : value_(value) {
}

list_control::item::item(const xtd::ustring& value, const std::any& tag) : value_(value), tag_(tag) {
}

list_control::item::item(const char* value) : value_(value) {
}

bool list_control::item::operator ==(const item& value) const noexcept {
  return value_ == value.value_;
}

bool list_control::item::operator !=(const item& value) const noexcept {
  return !operator ==(value);
}

bool list_control::item::operator <(const item& value) const noexcept {
  return value_ < value.value_;
}

bool list_control::item::operator <=(const item& value) const noexcept {
  return value_ <= value.value_;
}

bool list_control::item::operator >(const item& value) const noexcept {
  return value_ > value.value_;
}

bool list_control::item::operator >=(const item& value) const noexcept {
  return value_ >= value.value_;
}

const xtd::ustring& list_control::item::value() const noexcept {
  return value_;
}

std::any list_control::item::tag() const noexcept {
  return tag_;
}

xtd::ustring list_control::item::to_string() const noexcept {
  return value_;
}

list_control::list_control() {
  //back_color_ = default_back_color();
  //fore_color_ = default_fore_color();
}

size_t list_control::selected_index() const noexcept {
  return data_->selected_index;
}

drawing::color list_control::default_back_color() const noexcept {
  return xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().window();
}

drawing::color list_control::default_fore_color() const noexcept {
  return xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().window_text();
}

bool list_control::allow_selection() const noexcept {
  return true;
}

void list_control::on_selected_index_changed(const event_args& e) {
  selected_index_changed(*this, e);
}

void list_control::on_selected_value_changed(const event_args& e) {
  selected_value_changed(*this, e);
}

void list_control::set_selected_index(size_t value) {
  data_->selected_index = value;
}
