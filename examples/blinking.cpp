#include <lumen.hpp>

// connect to LED at pin 3
lumen::led::pwm_led my_led(3);

// blink every second effect
lumen::fx::blinking my_effect(1000);

void setup() {
  // setting the brightness to 100%
  my_led.set_brightness(100);
}

void loop() {
  // applying the chosen effect
  my_effect.apply(my_led);
}
