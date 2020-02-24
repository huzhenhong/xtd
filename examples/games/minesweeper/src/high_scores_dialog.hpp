#pragma once
#include "level.hpp"
#include "../properties/settings.hpp"
#include <xtd/xtd.forms>

namespace minesweeper {
  class high_scores_dialog : public xtd::forms::form {
  public:
    high_scores_dialog() {
      using namespace xtd::forms;
      start_position(form_start_position::center_parent);
      minimize_box(false);
      maximize_box(false);
      close_box(false);
      control_box(false);
      form_border_style(xtd::forms::form_border_style::none);
      client_size({360, 170});

      beginner_level_label_.parent(*this);
      beginner_level_label_.location({10, 25});
      beginner_level_label_.auto_size(true);
      beginner_level_label_.text("Beginner");
      
      intermediate_level_label_.parent(*this);
      intermediate_level_label_.location({10, 55});
      intermediate_level_label_.auto_size(true);
      intermediate_level_label_.text("Intermediate");
      
      expert_level_label_.parent(*this);
      expert_level_label_.location({10, 85});
      expert_level_label_.auto_size(true);
      expert_level_label_.text("Expert");

      beginner_score_label_.parent(*this);
      beginner_score_label_.location({130, 25});
      beginner_score_label_.auto_size(true);
      
      intermediate_score_label_.parent(*this);
      intermediate_score_label_.location({130, 55});
      intermediate_score_label_.auto_size(true);
      
      expert_score_label_.parent(*this);
      expert_score_label_.location({130, 85});
      expert_score_label_.auto_size(true);

      beginner_name_label_.parent(*this);
      beginner_name_label_.location({250, 25});
      beginner_name_label_.auto_size(true);
      
      intermediate_name_label_.parent(*this);
      intermediate_name_label_.location({250, 55});
      intermediate_name_label_.auto_size(true);
      
      expert_name_label_.parent(*this);
      expert_name_label_.location({250, 85});
      expert_name_label_.auto_size(true);

      reset_scores_button_.parent(*this);
      reset_scores_button_.location({70, 120});
      reset_scores_button_.width(100);
      reset_scores_button_.text("&Reset Scores");
      reset_scores_button_.click += [&] {
        properties::settings::default_settings().reset();
        read_and_update_settings();
      };

      ok_button_.parent(*this);
      ok_button_.location({190, 120});
      ok_button_.width(100);
      ok_button_.text(xtd::forms::texts::ok);
      ok_button_.dialog_result(dialog_result::ok);
      accept_button(ok_button_);

      read_and_update_settings();
    }
    
  private:
    void read_and_update_settings() {
      using namespace xtd;
      beginner_score_label_.text(strings::format("{} seconds", properties::settings::default_settings().beginner_high_scores_value()));
      intermediate_score_label_.text(strings::format("{} seconds", properties::settings::default_settings().intermediate_high_scores_value()));
      expert_score_label_.text(strings::format("{} seconds", properties::settings::default_settings().expert_high_scores_value()));

      beginner_name_label_.text(properties::settings::default_settings().beginner_high_scores_name());
      intermediate_name_label_.text(properties::settings::default_settings().intermediate_high_scores_name());
      expert_name_label_.text(properties::settings::default_settings().expert_high_scores_name());
    }
    
    xtd::forms::label beginner_level_label_;
    xtd::forms::label intermediate_level_label_;
    xtd::forms::label expert_level_label_;
    xtd::forms::label beginner_score_label_;
    xtd::forms::label intermediate_score_label_;
    xtd::forms::label expert_score_label_;
    xtd::forms::label beginner_name_label_;
    xtd::forms::label intermediate_name_label_;
    xtd::forms::label expert_name_label_;
    xtd::forms::button reset_scores_button_;
    xtd::forms::button ok_button_;
  };
}
