#include <xtd/diagnostics/process>
#include <xtd/drawing/bitmap>
#include <xtd/drawing/brushes>
#include <xtd/drawing/graphics>
#include <xtd/drawing/system_fonts>
#include <xtd/io/path>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::drawing;
using namespace xtd::io;

auto main()->int {
  auto hello_world_bitmap = bitmap {300, 300};
  auto graphics = graphics::from_image(hello_world_bitmap);
  graphics.draw_string("Hello World!", {system_fonts::default_font(), 32, font_style::bold | font_style::italic}, solid_brush {color::dark(color::spring_green, 2.0 / 3)}, rectangle::offset({{0, 0}, hello_world_bitmap.size()}, {2, 2}), string_format {}.alignment(string_alignment::center).line_alignment(string_alignment::center));
  graphics.draw_string("Hello World!", {system_fonts::default_font(), 32, font_style::bold | font_style::italic}, brushes::spring_green(), rectangle::inflate({{0, 0}, hello_world_bitmap.size()}, {-2, -2}), string_format {}.alignment(string_alignment::center).line_alignment(string_alignment::center));
  auto hello_world_png_path = path::combine(path::get_temp_path(), "hello_world_png.png");
  hello_world_bitmap.save(hello_world_png_path);
  process::start(hello_world_png_path);
}
