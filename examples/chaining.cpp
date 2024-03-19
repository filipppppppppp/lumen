#include <lumen.hpp>

// connect to LED at pin 3
lumen::led::pwm_led first_led(3);
lumen::led::basic_led second_led(4);

// create a chain of LEDs
lumen::led::vectored_chain chain;

void setup() {
  // setting the brightness to 100%
  first_led.set_brightness(100);

  // setting the fade in speed to 5 ms
  first_led.set_fade_in_speed(5);

  // setting the fade out speed to 5 ms
  first_led.set_fade_out_speed(5);

  // chaining together the two LEDs
  chain.add(first_led);
  chain.add(second_led);
}

void loop() {
  // iterating through the chained LEDs
  chain.iterate([](lumen::unit::led& led) {
    // toggling the LED!
    led.toggle();
  });

  delay(1000);
}
