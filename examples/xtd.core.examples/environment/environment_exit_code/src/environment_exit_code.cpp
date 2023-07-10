#include <xtd/environment>
#include <xtd/startup>
#include <vector>

using namespace std;
using namespace xtd;

namespace environment_exit_code_example {
  class program {
  public:
    // The main entry point for the application.
    static auto main() {
      vector<ustring> args = environment::get_command_line_args();
      if (args.size() == 1)
        environment::exit_code(ECANCELED);
      else {
        long long value = 0;
        if (try_parse(args[1], value))
          if (value <= numeric_limits<int>::min() || value >= numeric_limits<int>::max())
            environment::exit_code(ERANGE);
          else
            console::write_line("Result: {0}", value * 2);
        else
          environment::exit_code(EINVAL);
      }
    }
  };
}

startup_(environment_exit_code_example::program);

// This code produces the following output :
//
