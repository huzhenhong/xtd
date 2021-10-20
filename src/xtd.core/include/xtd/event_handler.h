/// @file
/// @brief Contains xtd::event_handler event handler.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include "delegate.h"
#include "event.h"
#include "event_args.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {

  /// @brief Represents the method that will handle an event when the event provides data.
  /// @tparam event_args_t The type of the event data generated by the event.
  /// @param sender The source of the event.
  /// @param e An object that contains the event data.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core events
  template<typename event_args_t = const xtd::event_args&>
  using generic_event_handler = xtd::delegate<void(xtd::object& sender, event_args_t e)>;
  
  /// @brief Represents the method that will handle an event that has no event data.
  /// @param sender The source of the event.
  /// @param e An object that contains no event data.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core events
  using event_handler = generic_event_handler<>;
}
