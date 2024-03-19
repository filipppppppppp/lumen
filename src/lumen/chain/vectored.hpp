#pragma once

#include "../chain.hpp"
#include "../unit/led.hpp"

#include "../detail/vector.hpp"

namespace lumen {

namespace led {

class vectored_chain : public chain {
 public:
  void add(unit::led &led);

  void iterate(const chain_cb_t &cb) override;

 private:
  detail::vector<unit::led *> leds_;
};

void vectored_chain::add(unit::led &led) {
  for (int i = 0; i < leds_.size(); i++)
    if (leds_[i] == &led) return;

  leds_.push_back(&led);
}

void vectored_chain::iterate(const chain_cb_t &cb) {
  for (int i = 0; i < leds_.size(); i++)
    cb(*leds_[i]);
}

} // namespace led

} // namespace lumen