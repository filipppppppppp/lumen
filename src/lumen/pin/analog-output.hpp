#pragma once

#include "../pin.hpp"

namespace lumen {

namespace pin {

class analog_output : public output_pin {
 public:
  explicit analog_output(uint8_t number);

  inline void write(uint32_t value) override;

  inline bool is_pwm() override;

  inline uint8_t get_number() const;

 private:
  uint8_t number_;
};

analog_output::analog_output(uint8_t number) : number_(number) {
  pinMode(number_, OUTPUT);
}

void analog_output::write(uint32_t value) {
  return analogWrite(number_, value);
}

bool analog_output::is_pwm() {
  return true;
}

uint8_t analog_output::get_number() const {
  return number_;
}

} // namespace pin

} // namespace lumen