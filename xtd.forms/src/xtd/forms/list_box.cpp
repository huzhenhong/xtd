#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/list_box.hpp>
#include <xtd/forms/native/window_styles.hpp>
#include <xtd/forms/native/window_list_box.hpp>
#include "../../../include/xtd/forms/list_box.hpp"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

list_box::list_box() {
  this->back_color_ = this->default_back_color();
  this->fore_color_ = this->default_fore_color();
  this->items_.item_added += [&](size_t pos, const std::string& item) {
    native::list_box::insert_item(this->handle_, pos, item);
    if (this->sorted_) std::sort(this->items_.begin(), this->items_.end());
    string selected_item;
    if (this->selected_index_ != -1 && this->selected_index_ < this->items_.size()) selected_item = this->items_[this->selected_index_];
    this->selected_item(selected_item);
  };
  
  this->items_.item_erased += [&](size_t pos, const std::string& item) {
    native::list_box::delete_item(this->handle_, pos);

    string selected_item;
    if (this->selected_index_ != -1 && this->selected_index_ < this->items_.size()) selected_item = this->items_[this->selected_index_];
    this->selected_item(selected_item);
  };
}

list_box& list_box::border_style(forms::border_style border_style) {
  if (this->border_style_ != border_style) {
    this->border_style_ = border_style;
    this->recreate_handle();
  }
  return *this;
}

color list_box::default_back_color() const {
  return native::list_box::default_back_color();
}

color list_box::default_fore_color() const {
  return native::list_box::default_fore_color();
}

list_box& list_box::selected_index(size_t selected_index) {
  if (this->selected_index_ != selected_index) {
    if (selected_index != -1 && selected_index > this->items_.size()) throw invalid_argument("out of range index");
    this->selected_index_ = selected_index;
    native::list_box::selected_index(this->handle_, this->selected_index_);

    string selected_item;
    if (this->selected_index_ != -1) selected_item = this->items_[this->selected_index_];
    this->selected_item(selected_item);

    this->on_selected_index_changed(event_args::empty);
  }
  return *this;
}

vector<size_t> list_box::selected_indices() const {
  return native::list_box::selected_indices(this->handle_);
}

list_box& list_box::selected_item(const string& selected_item) {
  if (this->selected_item_ != selected_item) {
    this->selected_item_ = selected_item;
    auto it = std::find(this->items_.begin(), this->items_.end(), selected_item);
    size_t index = -1;
    if (it != this->items_.end()) index = it - this->items_.begin();
    this->selected_index(index);
    if (index == -1) this->selected_item_= "";
    this->on_selected_value_changed(event_args::empty);
  }
  return *this;
}


vector<string> list_box::selected_items() const {
  vector<string> items;
  for (size_t index : this->selected_indices())
    items.push_back(this->items_[index]);
  return items;
}

list_box& list_box::selection_mode(forms::selection_mode selection_mode) {
  if (this->selection_mode_ != selection_mode) {
    this->selection_mode_ = selection_mode;
    this->recreate_handle();
  }
  return *this;
}

list_box& list_box::sorted(bool sorted) {
  if (this->sorted_ != sorted) {
    this->sorted_ = sorted;
    if (this->sorted_) std::sort(this->items_.begin(), this->items_.end());
    this->recreate_handle();
  }
  return *this;
}

void list_box::create_handle() {
  size_t styles = 0;
  size_t ex_styles = 0;
  switch (this->selection_mode_) {
    case selection_mode::none: styles |= LBS_NOSEL; break;
    case selection_mode::one:  break;
    case selection_mode::multi_simple: styles |= LBS_MULTIPLESEL; break;
    case selection_mode::multi_extended: styles |= LBS_MULTIPLESEL | LBS_EXTENDEDSEL; break;
    default: break;
  }
  if (this->sorted_) styles |= LBS_SORT;
  if (this->border_style_ == forms::border_style::fixed_single) styles |= WS_BORDER;
  else if (this->border_style_ == forms::border_style::fixed_3d) ex_styles |= WS_EX_CLIENTEDGE;
  this->handle_ = native::list_box::create(this->parent_->__get_handle__(), this->default_size(), styles, ex_styles);
  this->control::create_handle();
  for (size_t index = 0; index < this->items_.size(); ++index)
    native::list_box::insert_item(this->handle_, index, this->items_[index]);
  if (this->selection_mode_ == forms::selection_mode::none) this->selected_index(-1);
  native::list_box::selected_index(this->handle_, this->selected_index_);
  if (this->selected_index_ != -1) this->selected_item_ = this->items_[this->selected_index_];
}

void list_box::wnd_proc(message &message) {
  switch (message.msg()) {
    case WM_LBUTTONDOWN: this->wm_mouse_down(message); break;
    case WM_LBUTTONDBLCLK: this->wm_mouse_double_click(message); break;
    case WM_REFLECT + WM_COMMAND: wm_reflect_command(message); break;
    default: this->control::wnd_proc(message);
  }
}

void list_box::wm_mouse_double_click(message &message) {
  if (this->selection_mode() != forms::selection_mode::none)
    this->control::wnd_proc(message);
}

void list_box::wm_mouse_down(message &message) {
  if (this->selection_mode() != forms::selection_mode::none)
    this->control::wnd_proc(message);
  else
    this->on_selected_index_changed(event_args::empty);
}

void list_box::wm_reflect_command(message &message) {
  this->def_wnd_proc(message);
  this->selected_index(native::list_box::selected_index(this->handle_));
}
