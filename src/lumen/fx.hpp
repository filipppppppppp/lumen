#pragma once

#include "unit/led.hpp"

namespace lumen {

namespace fx {

class effect {
 public:
  virtual void apply(unit::led& led) = 0;

  virtual ~effect() = default;
};

} // namespace fx

} // namespace lumen