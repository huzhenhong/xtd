/// @file
/// @brief Contains unit test application main entry point.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <xtd/startup.h>
#include "../tunit_export.h"

/// @cond
class tunit_export_ __tunit_main final {
public:
  __tunit_main() = delete;
  static int main(int argc, char* argv[]);
};
class tunit_export_ __tunit_main_with_gtest_compatibility final {
public:
  __tunit_main_with_gtest_compatibility() = delete;
  static int main(int argc, char* argv[]);
};
/// @endcond

/// @brief Defines the entry point to be called with #startup_ for unit test application.
/// @par Library
/// xtd.tunit
/// @ingroup xtd_tunit tunit
/// @remarks The #tunit_main_ contains a main method and launch xtd::tunit::console_unit_test::run.
/// @par Examples
/// The followng code shows ho to use #tunit_main_.
/// @code
/// #include <xtd/xtd.tunit>
///
/// using namespace xtd::tunit;
///
/// namespace unit_tests {
///   test_class_(class_to_test) {
///   public:
///     void test_method_(test1) {
///       // Do test...
///     }
///   };
/// }
///
/// startup_(tunit_main_);
/// @endcode
#define tunit_main_ \
  __tunit_main

/// @brief Defines the entry point to be called with #startup_ for unit test application with Google test compatibility.
/// @par Library
/// xtd.tunit
/// @ingroup xtd_tunit tunit
/// @remarks The #tunit_main_  contains main method, launch xtd::tunit::console_unit_test::run and set xtd::tunit::settings::gtest_compatibility to true.
/// @par Examples
/// The followng code shows ho to use #tunit_main_with_gtest_compatibility_.
/// @code
/// #include <xtd/xtd.tunit>
///
/// using namespace xtd::tunit;
///
/// namespace unit_tests {
///   test_class_(class_to_test) {
///   public:
///     void test_method_(test1) {
///       // Do test...
///     }
///   };
/// }
///
/// startup_(tunit_main_with_gtest_compatibility_);
/// @endcode
#define tunit_main_with_gtest_compatibility_ \
  __tunit_main_with_gtest_compatibility
