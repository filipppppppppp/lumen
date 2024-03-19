#pragma once

#include "../unit.hpp"

namespace lumen {

namespace unit {

class led : public output_unit {
 public:
  virtual void toggle() = 0;

  virtual bool is_on() const = 0;

  virtual ~led() = default;
};

} // namespace unit

} // namespace lumen