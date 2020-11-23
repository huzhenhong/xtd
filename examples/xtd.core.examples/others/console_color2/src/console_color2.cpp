#include <xtd/xtd>
#include <vector>

using namespace std;
using namespace xtd;

int main() {
  const vector logo = {
    u8"████████████████████████████████████████████████████████████",
    u8"██████████████████████████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████",
    u8"██████████████████████████████░░░░░░░░░░░░░░░░░░░░░░████░░████████",
    u8"██████████████████████████████░░░░░░░░░░░░░░░░░░░░░░████░░██████████",
    u8"██████████████████████████████░░░░░░░░░░░░░░░░░░░░░░████░░████████████",
    u8"██████████████████████████████░░░░░░░░░░░░░░░░░░░░░░████░░████████████",
    u8"██████████████████████████████░░░░░░░░░░░░░░░░░░░░░░████░░████████████",
    u8"███████████████████████████████░░░░░░░░░░░░░░░░░░░░░░░░░░█████████████",
    u8"██████████████████████████████████████████████████████████████████████",
    u8"██████████████████████████████████████████████████████████████████████",
    u8"██████████████████████████▀▄▄▄▄▀███████▀▄▄▄▄▀█████████████████████████",
    u8"███████████████████████████▀▀▀▀███████▀▀▀▀▀███████████████████████████",
    u8"██████████████████████████      ▀████       ▀█████████████████████████",
    u8"███████████             ▐         ▀▀         ▐              ██████████",
    u8"█████████               ▐   ███   ▌▐   ███   ▐               █████████",
    u8"█████████               ▐   █▄▄▌  ▌▐  ▐▄▄█   ▐               █████████",
    u8"█████████                ▐▄  ▀▀ ▄▀  ▀▄ ▀▀  ▄▀                █████████",
    u8"█████████                  ▀▀▄▄▀      ▀▀▄▄▀                  █████████",
    u8"█████████                                                    █████████",
    u8"█████████                 █▄                ▌                █████████",
    u8"█████████                  ▌▀▀▄          ▄██                 █████████",
    u8"█████████                  ▐   ▀▀▄▄▄▄▄▄█▀ █▌                 █████████",
    u8"█████████                   ▐            ▄█                  █████████",
    u8"█████████                    █          ▄█                   █████████",
    u8"█████████                     ▀▄       █▀                    █████████",
    u8"█████████                       ▀▄▄▄▄██▀                     █████████",
    u8"█████████                                                    █████████",
    u8"█████████                                                    █████████",
    u8"█████████                                                    █████████",
    u8"█████████                                                    █████████",
    u8"█████████                                                    █████████",
    u8"██████████████████████████████████████████████████████████████████",
  };
  
  console::output_code_page(65001);
  
  for (size_t index = 0; index < logo.size(); ++index) {
    console::write(index == 0 || index == logo.size() - 1 ? "       " : "     ");
    console::background_color(console_color::white);
    console::foreground_color(console_color::dark_blue);
    console::write(logo[index]);
    console::reset_color();
    console::write_line();
  }
  
  console::foreground_color(console_color::dark_blue);
  console::write_line(u8"                                    Gammasoft                                   ");
  console::foreground_color(console_color::dark_gray);
  console::write_line(u8" More than thirty years of passion for high technology especially in development");
  console::write_line(u8" (c++, c#, objective-c, ...).");
  console::reset_color();
}

// This code produces the following output with colors:
//
//        ████████████████████████████████████████████████████████████
//      ██████████████████████████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████
//      ██████████████████████████████░░░░░░░░░░░░░░░░░░░░░░████░░████████
//      ██████████████████████████████░░░░░░░░░░░░░░░░░░░░░░████░░██████████
//      ██████████████████████████████░░░░░░░░░░░░░░░░░░░░░░████░░████████████
//      ██████████████████████████████░░░░░░░░░░░░░░░░░░░░░░████░░████████████
//      ██████████████████████████████░░░░░░░░░░░░░░░░░░░░░░████░░████████████
//      ███████████████████████████████░░░░░░░░░░░░░░░░░░░░░░░░░░█████████████
//      ██████████████████████████████████████████████████████████████████████
//      ██████████████████████████████████████████████████████████████████████
//      ██████████████████████████▀▄▄▄▄▀███████▀▄▄▄▄▀█████████████████████████
//      ███████████████████████████▀▀▀▀███████▀▀▀▀▀███████████████████████████
//      ██████████████████████████      ▀████       ▀█████████████████████████
//      ███████████             ▐         ▀▀         ▐              ██████████
//      █████████               ▐   ███   ▌▐   ███   ▐               █████████
//      █████████               ▐   █▄▄▌  ▌▐  ▐▄▄█   ▐               █████████
//      █████████                ▐▄  ▀▀ ▄▀  ▀▄ ▀▀  ▄▀                █████████
//      █████████                  ▀▀▄▄▀      ▀▀▄▄▀                  █████████
//      █████████                                                    █████████
//      █████████                 █▄                ▌                █████████
//      █████████                  ▌▀▀▄          ▄██                 █████████
//      █████████                  ▐   ▀▀▄▄▄▄▄▄█▀ █▌                 █████████
//      █████████                   ▐            ▄█                  █████████
//      █████████                    █          ▄█                   █████████
//      █████████                     ▀▄       █▀                    █████████
//      █████████                       ▀▄▄▄▄██▀                     █████████
//      █████████                                                    █████████
//      █████████                                                    █████████
//      █████████                                                    █████████
//      █████████                                                    █████████
//      █████████                                                    █████████
//        ██████████████████████████████████████████████████████████████████
//                                    Gammasoft
// More than thirty years of passion for high technology especially in development
// (c++, c#, objective-c, ...).
