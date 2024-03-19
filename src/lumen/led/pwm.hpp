#pragma once

#include "../pin/analog-output.hpp"
#include "../unit/led.hpp"

namespace lumen {

namespace led {

class pwm_led : public unit::led {
 public:
  pwm_led(uint8_t pin_number, bool logic = true);

  void turn_on();

  void turn_off();

  inline void toggle() override;

  inline bool is_on() const override;

  inline pin::output_pin &get_pin() override;

  inline void set_brightness(uint32_t percentage);

  inline void set_fade_in_speed(uint32_t ms);

  inline void set_fade_out_speed(uint32_t ms);

  inline uint32_t get_brightness() const;

  inline uint32_t get_fade_in_speed() const;

  inline uint32_t get_fade_out_speed() const;

 private:
  bool logic_;
  bool is_on_;

  uint32_t brightness_;
  uint32_t fade_in_speed_;
  uint32_t fade_out_speed_;

  pin::analog_output pin_;
};

pwm_led::pwm_led(uint8_t pin_number, bool logic)
    : pin_(pin_number), is_on_(!logic), brightness_(255),
      fade_in_speed_(0), fade_out_speed_(0) {}

void pwm_led::turn_on() {
  for (int i = 0; i < brightness_; i++) {
    pin_.write(i);

    delay(fade_in_speed_);
  }

  is_on_ = true;
}

void pwm_led::turn_off() {
  for (int i = brightness_; i > 0; i--) {
    pin_.write(i);

    delay(fade_out_speed_);
  }

  is_on_ = false;
}

void pwm_led::toggle() {
  is_on_ = !is_on_;
  return is_on_ ? turn_on() : turn_off();
}

bool pwm_led::is_on() const {
  return is_on_;
}

pin::output_pin &pwm_led::get_pin() {
  return pin_;
}

void pwm_led::set_brightness(uint32_t percentage) {
  const auto constrained = constrain(percentage, 0, 100);
  brightness_ = map(percentage, 0, 100, 0, 255);
}

void pwm_led::set_fade_in_speed(uint32_t ms) {
  fade_in_speed_ = ms;
}

void pwm_led::set_fade_out_speed(uint32_t ms) {
  fade_out_speed_ = ms;
}

uint32_t pwm_led::get_brightness() const {
  return brightness_;
}

uint32_t pwm_led::get_fade_in_speed() const {
  return fade_in_speed_;
}

uint32_t pwm_led::get_fade_out_speed() const {
  return fade_out_speed_;
}

} // namespace led

} // namespace lumen