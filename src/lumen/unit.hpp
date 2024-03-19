#pragma once

#include "pin.hpp"

namespace lumen {

namespace unit {

class input_unit {
 public:
  virtual pin::input_pin &get_pin() = 0;

  virtual ~input_unit() = default;
};

class output_unit {
 public:
  virtual pin::output_pin &get_pin() = 0;

  virtual ~output_unit() = default;
};

} // namespace unit

} // namespace lumen