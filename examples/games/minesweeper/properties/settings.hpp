#pragma region xtd generated code
// This code was generated by CMake script.
//
// Changes to this file may cause incorrect behavior and will be lost if the code is regenerated.

#pragma once

#include <xtd/xtd>

namespace minesweeper::properties {
  class settings : public xtd::forms::component {
  public:
    settings() : ::minesweeper::properties::settings(true) {}

    static ::minesweeper::properties::settings& default_settings() {
      static ::minesweeper::properties::settings default_settings;
      return default_settings;
    }

    bool original_color() const {return original_color_;}
    void original_color(bool value) {original_color_ = value;}

    int level() const {return level_;}
    void level(int value) {level_ = value;}

    int custom_height() const {return custom_height_;}
    void custom_height(int value) {custom_height_ = value;}

    int custom_width() const {return custom_width_;}
    void custom_width(int value) {custom_width_ = value;}

    int custom_mines() const {return custom_mines_;}
    void custom_mines(int value) {custom_mines_ = value;}

    int beginner_high_scores_value() const {return beginner_high_scores_value_;}
    void beginner_high_scores_value(int value) {beginner_high_scores_value_ = value;}

    std::string beginner_high_scores_names() const {return beginner_high_scores_names_;}
    void beginner_high_scores_names(std::string value) {beginner_high_scores_names_ = value;}

    int intermediate_high_scores_value() const {return intermediate_high_scores_value_;}
    void intermediate_high_scores_value(int value) {intermediate_high_scores_value_ = value;}

    std::string intermediate_high_scores_names() const {return intermediate_high_scores_names_;}
    void intermediate_high_scores_names(std::string value) {intermediate_high_scores_names_ = value;}

    int expert_high_scores_value() const {return expert_high_scores_value_;}
    void expert_high_scores_value(int value) {expert_high_scores_value_ = value;}

    std::string expert_high_scores_names() const {return expert_high_scores_names_;}
    void expert_high_scores_names(std::string value) {expert_high_scores_names_ = value;}

    void reload() {
      original_color_ = settings_.read("original_color", original_color_);
      level_ = settings_.read("level", level_);
      custom_height_ = settings_.read("custom_height", custom_height_);
      custom_width_ = settings_.read("custom_width", custom_width_);
      custom_mines_ = settings_.read("custom_mines", custom_mines_);
      beginner_high_scores_value_ = settings_.read("beginner_high_scores_value", beginner_high_scores_value_);
      beginner_high_scores_names_ = settings_.read("beginner_high_scores_names", beginner_high_scores_names_);
      intermediate_high_scores_value_ = settings_.read("intermediate_high_scores_value", intermediate_high_scores_value_);
      intermediate_high_scores_names_ = settings_.read("intermediate_high_scores_names", intermediate_high_scores_names_);
      expert_high_scores_value_ = settings_.read("expert_high_scores_value", expert_high_scores_value_);
      expert_high_scores_names_ = settings_.read("expert_high_scores_names", expert_high_scores_names_);
    }

    void reset() {
      settings_.reset();
      *this = settings(false);
      reload();
    }

    void save() {
      settings_.write("original_color", original_color_);
      settings_.write("level", level_);
      settings_.write("custom_height", custom_height_);
      settings_.write("custom_width", custom_width_);
      settings_.write("custom_mines", custom_mines_);
      settings_.write("beginner_high_scores_value", beginner_high_scores_value_);
      settings_.write("beginner_high_scores_names", beginner_high_scores_names_);
      settings_.write("intermediate_high_scores_value", intermediate_high_scores_value_);
      settings_.write("intermediate_high_scores_names", intermediate_high_scores_names_);
      settings_.write("expert_high_scores_value", expert_high_scores_value_);
      settings_.write("expert_high_scores_names", expert_high_scores_names_);
      settings_.save();
    }

  private:
    settings(bool load) {if (load) reload();}
    xtd::forms::settings settings_;
    bool original_color_ {true};
    int level_ {0};
    int custom_height_ {16};
    int custom_width_ {30};
    int custom_mines_ {99};
    int beginner_high_scores_value_ {999};
    std::string beginner_high_scores_names_ {"Anonymous"};
    int intermediate_high_scores_value_ {999};
    std::string intermediate_high_scores_names_ {"Anonymous"};
    int expert_high_scores_value_ {999};
    std::string expert_high_scores_names_ {"Anonymous"};
  };
}

#pragma endregion
