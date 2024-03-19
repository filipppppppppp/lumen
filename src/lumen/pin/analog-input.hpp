#pragma once

#include "../pin.hpp"

namespace lumen {

namespace pin {

class analog_input : public input_pin {
 public:
  explicit analog_input(uint8_t number);

  inline uint32_t read() override;

  inline bool is_pwm() override;

  inline uint8_t get_number() const;

 private:
  uint8_t number_;
};

analog_input::analog_input(uint8_t number) : number_(number) {
  pinMode(number_, INPUT);
}

uint32_t analog_input::read() {
  return analogRead(number_);
}

bool analog_input::is_pwm() {
  return true;
}

uint8_t analog_input::get_number() const {
  return number_;
}

} // namespace pin

} // namespace lumen