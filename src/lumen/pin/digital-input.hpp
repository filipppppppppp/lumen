#pragma once

#include "../pin.hpp"

namespace lumen {

namespace pin {

class digital_input : public input_pin {
 public:
  explicit digital_input(uint8_t number);

  inline uint32_t read() override;

  inline bool is_pwm() override;

  inline uint8_t get_number() const;

 private:
  uint8_t number_;
};

digital_input::digital_input(uint8_t number) : number_(number) {
  pinMode(number_, INPUT);
}

uint32_t digital_input::read() {
  return digitalRead(number_);
}

bool digital_input::is_pwm() {
  return false;
}

uint8_t digital_input::get_number() const {
  return number_;
}

} // namespace pin

} // namespace lumen