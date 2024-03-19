#pragma once

#include "unit/led.hpp"

namespace lumen {

namespace led {

using chain_cb_t = void (*)(unit::led &led);

class chain {
 public:
  virtual void iterate(const chain_cb_t &cb) = 0;

  virtual ~chain() = default;
};

} // namespace led

} // namespace lumen