#pragma once

#include "../pin/digital-output.hpp"
#include "../unit/led.hpp"

namespace lumen {

namespace led {

class basic_led : public unit::led {
 public:
  basic_led(uint8_t pin_number, bool logic = true);

  inline void turn_on();

  inline void turn_off();

  inline void toggle() override;

  inline bool is_on() const override;

  inline pin::output_pin &get_pin() override;

 private:
  bool logic_;
  bool is_on_;

  pin::digital_output pin_;
};

basic_led::basic_led(uint8_t pin_number, bool logic)
    : pin_(pin_number), logic_(logic), is_on_(!logic) {}

void basic_led::turn_on() {
  pin_.write(logic_);
  is_on_ = true;
}

void basic_led::turn_off() {
  pin_.write(!logic_);
  is_on_ = false;
}

void basic_led::toggle() {
  logic_ = !logic_;
  pin_.write(!logic_);

  is_on_ = !is_on_;
}

bool basic_led::is_on() const {
  return is_on_;
}

pin::output_pin &basic_led::get_pin() {
  return pin_;
}

} // namespace led

} // namespace lumen