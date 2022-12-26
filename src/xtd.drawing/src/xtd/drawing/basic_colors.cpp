#include "../../../include/xtd/drawing/basic_colors.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

color basic_colors::aqua() {
  return color::from_known_color(known_color::aqua);
}

color basic_colors::black() {
  return color::from_known_color(known_color::black);
}

color basic_colors::blue() {
  return color::from_known_color(known_color::blue);
}

color basic_colors::fuchsia() {
  return color::from_known_color(known_color::fuchsia);
}

color basic_colors::gray() {
  return color::from_known_color(known_color::gray);
}

color basic_colors::green() {
  return color::from_known_color(known_color::green);
}

color basic_colors::lime() {
  return color::from_known_color(known_color::lime);
}

color basic_colors::maroon() {
  return color::from_known_color(known_color::maroon);
}

color basic_colors::navy() {
  return color::from_known_color(known_color::navy);
}

color basic_colors::olive() {
  return color::from_known_color(known_color::olive);
}

color basic_colors::purple() {
  return color::from_known_color(known_color::purple);
}

color basic_colors::red() {
  return color::from_known_color(known_color::red);
}

color basic_colors::silver() {
  return color::from_known_color(known_color::silver);
}

color basic_colors::teal() {
  return color::from_known_color(known_color::teal);
}

color basic_colors::white() {
  return color::from_known_color(known_color::white);
}

color basic_colors::yellow() {
  return color::from_known_color(known_color::yellow);
}

const vector<color>& basic_colors::get_colors() {
  static vector<color> colors {basic_colors::white(), basic_colors::silver(), basic_colors::gray(), basic_colors::black(), basic_colors::red(), basic_colors::maroon(), basic_colors::yellow(), basic_colors::olive(), basic_colors::lime(), basic_colors::green(), basic_colors::aqua(), basic_colors::teal(), basic_colors::blue(), basic_colors::navy(), basic_colors::fuchsia(), basic_colors::purple()};
  return colors;
}

const vector<ustring>& basic_colors::get_color_names() {
  static vector<ustring> color_names {basic_colors::white().name(), basic_colors::silver().name(), basic_colors::gray().name(), basic_colors::black().name(), basic_colors::red().name(), basic_colors::maroon().name(), basic_colors::yellow().name(), basic_colors::olive().name(), basic_colors::lime().name(), basic_colors::green().name(), basic_colors::aqua().name(), basic_colors::teal().name(), basic_colors::blue().name(), basic_colors::navy().name(), basic_colors::fuchsia().name(), basic_colors::purple().name()};
  return color_names;
}
