#ifndef ROTARYENCODER_H
#define ROTARYENCODER_H
#include "TCA9555.h"

class RotaryEncoder {
  private:
    volatile int clkPinLast = LOW;
    volatile int clkPinCurrent = LOW;
    byte dataPin;
    byte clckPin;
    byte swPin;

  public:
    volatile bool down;
    volatile bool up;
    volatile bool pressed;

    // read 3 values from one chip
    void read(TCA9555 &chip, byte _clckPin, byte _dataPin, byte _swPin);
    // read only up and down values
    void read(TCA9555 &chip, byte _clckPin, byte _dataPin);
    // read only switch value
    void read(TCA9555 &chip, byte _swPin);
};

#endif