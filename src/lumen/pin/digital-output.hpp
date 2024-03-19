#pragma once

#include "../pin.hpp"

namespace lumen {

namespace pin {

class digital_output : public output_pin {
 public:
  explicit digital_output(uint8_t number);

  inline void write(uint32_t value) override;

  inline bool is_pwm() override;

  inline uint8_t get_number() const;

 private:
  uint8_t number_;
};

digital_output::digital_output(uint8_t number) : number_(number) {
  pinMode(number_, OUTPUT);
}

void digital_output::write(uint32_t value) {
  return digitalWrite(number_, value);
}

bool digital_output::is_pwm() {
  return false;
}

uint8_t digital_output::get_number() const {
  return number_;
}

} // namespace pin

} // namespace lumen