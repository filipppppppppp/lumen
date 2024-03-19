#pragma once

#include "../detail/memory.hpp"
#include "../fx.hpp"

namespace lumen {

namespace fx {

class blinking : public effect {
 public:
  explicit blinking(uint32_t milliseconds);

  void apply(unit::led &led) override;

  inline void set_delay(uint32_t milliseconds);

  inline uint32_t get_delay() const;

 private:
  uint32_t milliseconds_;
};

blinking::blinking(uint32_t milliseconds)
    : milliseconds_(milliseconds) {}

void blinking::apply(unit::led &led) {
  auto &pin = led.get_pin();

  pin.write(true);
  delay(milliseconds_);

  pin.write(false);
  delay(milliseconds_);
}

void blinking::set_delay(uint32_t milliseconds) {
  milliseconds_ = milliseconds;
}

uint32_t blinking::get_delay() const {
  return milliseconds_;
}

} // namespace fx

} // namespace lumen