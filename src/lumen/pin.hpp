#pragma once

namespace lumen {

namespace pin {

class input_pin {
 public:
  virtual uint32_t read() = 0;

  virtual bool is_pwm() = 0;

  virtual ~input_pin() = default;
};

class output_pin {
 public:
  virtual void write(uint32_t value) = 0;

  virtual bool is_pwm() = 0;

  virtual ~output_pin() = default;
};

} // namespace pin

} // namespace lumen