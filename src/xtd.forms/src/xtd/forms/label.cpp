#include <xtd/drawing/pens.h>
#include <xtd/drawing/solid_brush.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/drawing/string_format.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/label.h>
#include <xtd/forms/native/static_styles.h>
#include <xtd/forms/native/toolkit.h>
#include <xtd/forms/native/window_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/control_paint.h"
#include "../../../include/xtd/forms/label.h"
#include "../../../include/xtd/forms/label_renderer.h"
#include "../../../include/xtd/forms/screen.h"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

label::label() {
  if (application::use_system_controls()) data_->flat_style = xtd::forms::flat_style::system;
  double_buffered(true);
  set_can_focus(false);
  set_style(control_styles::user_paint | control_styles::supports_transparent_back_color | control_styles::optimized_double_buffer, control::control_appearance() == forms::control_appearance::standard);
  set_style(control_styles::fixed_height | control_styles::selectable, false);
  set_style(control_styles::resize_redraw, true);
}

bool label::auto_ellipsis() const noexcept {
  return data_->auto_ellipsis;
}

label& label::auto_ellipsis(bool value) {
  if (data_->auto_ellipsis != value) {
    data_->auto_ellipsis = value;
    if (flat_style() == forms::flat_style::system) post_recreate_handle();
    else invalidate();
  }
  return *this;
}

forms::border_sides label::border_sides() const noexcept {
  return data_->border_sides;
}

label& label::border_sides(forms::border_sides border_sides) {
  if (data_->border_sides != border_sides) {
    data_->border_sides = border_sides;
    if (control_appearance() == forms::control_appearance::standard) invalidate();
  }
  return *this;
}

xtd::forms::border_style label::border_style() const noexcept {
  return data_->border_style.value_or(xtd::forms::border_style::none);
}

label& label::border_style(xtd::forms::border_style border_style) {
  if (data_->border_style != border_style) {
    data_->border_style = border_style;
    if (flat_style() == forms::flat_style::system) post_recreate_handle();
    else invalidate();
  }
  return *this;
}

label& label::border_style(std::nullptr_t) {
  if (data_->border_style) {
    data_->border_style.reset();
    if (flat_style() == forms::flat_style::system) post_recreate_handle();
    else invalidate();
  }
  return *this;
}

control& label::control_appearance(forms::control_appearance value) {
  control::control_appearance(value);
  if (value == forms::control_appearance::system && data_->flat_style != xtd::forms::flat_style::system)
    flat_style(xtd::forms::flat_style::system);
  else if (value == forms::control_appearance::standard && data_->flat_style == xtd::forms::flat_style::system)
    flat_style(xtd::forms::flat_style::standard);
  return *this;
}

xtd::forms::flat_style label::flat_style() const noexcept {
  return data_->flat_style;
}

label& label::flat_style(xtd::forms::flat_style flat_style) {
  if (data_->flat_style != flat_style) {
    data_->flat_style = flat_style;
    control_appearance(data_->flat_style == xtd::forms::flat_style::system ? forms::control_appearance::system : forms::control_appearance::standard);
    recreate_handle();
  }
  return *this;
}

const drawing::image& label::image() const noexcept {
  return data_->image;
}

label& label::image(const drawing::image& value) {
  if (data_->image != value) {
    data_->image = value;
    data_->image_list = forms::image_list();
    data_->image_index = -1;
    if (data_->flat_style != xtd::forms::flat_style::system) invalidate();
    on_image_changed(xtd::event_args::empty);
  }
  return *this;
}

xtd::forms::content_alignment label::image_align() const noexcept {
  return data_->image_align;
}

label& label::image_align(content_alignment value) {
  if (data_->image_align != value) {
    data_->image_align = value;
    if (data_->flat_style != xtd::forms::flat_style::system) invalidate();
  }
  return *this;
}

int32_t label::image_index() const noexcept {
  return data_->image_index;
}

label& label::image_index(int32_t value) {
  if (data_->image_index != value) {
    if (value < -1 || static_cast<size_t>(value) >= data_->image_list.images().size()) throw argument_out_of_range_exception(current_stack_frame_);
    data_->image_index = value;
    if (data_->flat_style != xtd::forms::flat_style::system) invalidate();
    if (value != -1) data_->image = xtd::drawing::image::empty;
  }
  return *this;
}

const forms::image_list& label::image_list() const noexcept {
  return data_->image_list;
}

forms::image_list& label::image_list() noexcept {
  return data_->image_list;
}

label& label::image_list(const forms::image_list& value) {
  if (data_->image_list != value) {
    data_->image_list = value;
    data_->image = drawing::image::empty;
    post_recreate_handle();
  }
  return *this;
}

bool label::shadow() const noexcept {
  return data_->shadow;
}

label& label::shadow(bool value) {
  if (data_->shadow != value) {
    data_->shadow = value;
    if (control_appearance() == forms::control_appearance::standard) invalidate();
  }
  return *this;
}

xtd::forms::content_alignment label::text_align() const noexcept {
  return data_->text_align;
}

label& label::text_align(content_alignment text_align) {
  if (data_->text_align != text_align) {
    data_->text_align = text_align;
    post_recreate_handle();
    on_text_align_changed(event_args::empty);
  }
  return *this;
}

forms::create_params label::create_params() const noexcept {
  forms::create_params create_params = control::create_params();
  
  create_params.class_name("label");
  create_params.style(create_params.style() | SS_LEFT);
  
  if (data_->flat_style == xtd::forms::flat_style::system) {
    if (data_->border_style.value_or(xtd::forms::border_style::none) == xtd::forms::border_style::solid) create_params.style(create_params.style() | WS_BORDER);
    else if (data_->border_style.value_or(xtd::forms::border_style::none) != xtd::forms::border_style::none) create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);
  } else create_params.style(create_params.style() | SS_OWNERDRAW);
  
  if (data_->auto_ellipsis) create_params.style(create_params.style() | SS_ENDELLIPSIS);
  
  switch (data_->text_align) {
    case content_alignment::top_left: create_params.style(create_params.style() | SS_TOP | SS_LEFT); break;
    case content_alignment::top_center: create_params.style(create_params.style() | SS_TOP  | SS_CENTER); break;
    case content_alignment::top_right: create_params.style(create_params.style() | SS_TOP  | SS_RIGHT); break;
    case content_alignment::middle_left: create_params.style(create_params.style() | SS_VCENTER  | SS_LEFT); break;
    case content_alignment::middle_center: create_params.style(create_params.style() | SS_VCENTER | SS_CENTER); break;
    case content_alignment::middle_right: create_params.style(create_params.style() | SS_VCENTER | SS_RIGHT); break;
    case content_alignment::bottom_left: create_params.style(create_params.style() | SS_BOTTOM | SS_LEFT); break;
    case content_alignment::bottom_center: create_params.style(create_params.style() | SS_BOTTOM | SS_CENTER); break;
    case content_alignment::bottom_right: create_params.style(create_params.style() | SS_BOTTOM | SS_RIGHT); break;
    default: break;
  }
  
  return create_params;
}

drawing::size label::measure_control() const noexcept {
  return control::measure_text() + drawing::size(data_->border_style == border_style::none ? 0 : 4, data_->border_style == border_style::none ? 0 : 4);
}

void label::on_font_changed(const xtd::event_args& e) {
  control::on_font_changed(e);
  if (data_->flat_style != xtd::forms::flat_style::system) invalidate();
}

void label::on_image_changed(const xtd::event_args& e) {
  if (data_->flat_style != xtd::forms::flat_style::system) invalidate();
  if (can_raise_events()) image_changed(*this, e);
}

void label::on_paint(paint_event_args& e) {
  control::on_paint(e);
  if (data_->flat_style != xtd::forms::flat_style::system) {
    auto style = style_sheet() != style_sheets::style_sheet::empty ? style_sheet() : style_sheets::style_sheet::current_style_sheet();
    label_renderer::draw_label(style, e.graphics(), e.clip_rectangle(), control_state(), back_color() != default_back_color() ? std::optional<drawing::color> {back_color()} : std::nullopt, text(), text_align(), fore_color() != default_fore_color() ? std::optional<drawing::color> {fore_color()} : std::nullopt, font() != default_font() ? std::optional<drawing::font> {font()} : std::nullopt, image(), image_align(), data_->border_style, data_->border_sides, shadow(), auto_ellipsis());
  }
}

void label::on_text_align_changed(const xtd::event_args& e) {
  text_align_changed(*this, e);
}

void label::on_text_changed(const xtd::event_args& e) {
  control::on_text_changed(e);
  if (data_->flat_style != xtd::forms::flat_style::system) invalidate();
}

void label::on_resize(const xtd::event_args& e) {
  control::on_resize(e);
  if (data_->flat_style != xtd::forms::flat_style::system) invalidate();
}
