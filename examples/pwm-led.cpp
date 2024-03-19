#include <lumen.hpp>

// connect to led at pin 3
lumen::led::pwm_led my_led(3);

void setup() {
  // setting the brightness to 100%
  my_led.set_brightness(100);

  // setting the fade in speed to 5 ms
  my_led.set_fade_in_speed(5);

  // setting the fade out speed to 5 ms
  my_led.set_fade_out_speed(5);
}

void loop() {
  // toggling it!
  my_led.toggle();

  delay(1000);
}
