# ✨ Lumen library
An arduino library that makes LED usage simple and flexible.

![lumen-arch](/images/lumen.png)

## Non-PWM Support
```cpp
#include <lumen.hpp>

// connect to LED at pin 4
lumen::led::basic_led my_led(4);

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

// connect to LED at pin 3
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

## Inverted Logic Support
```cpp
#include <lumen.hpp>

// connect to LED at pin 4 with inverted logic
lumen::led::basic_led my_led(4, false);
```

## Chaining Support
```cpp
#include <lumen.hpp>

// connect to the LEDs
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
```

## Effects Support
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