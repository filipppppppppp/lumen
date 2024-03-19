# ✨ Lumen library
An arduino library that makes LED usage simple and flexible.

## Non-PWM Support
```cpp
#include <lumen.hpp>

// connect to led at pin 4
lumen::led::basic_led second_led(4);

void setup() {}

void loop() {
  // toggling it!
  my_led.toggle();

  delay(1000);
}
```

## PWM Support
```cpp
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
```

## Effects Support
Creating effects for your LEDs becomes simple with Lumen, all you need to do is just implement the lumen::fx::effect interface.
```cpp
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
```