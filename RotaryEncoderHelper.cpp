#include "RotaryEncoderHelper.h"

// Read Rotary Encoder Chip with clckPin, dataPin, swPin
void RotaryEncoder::read(TCA9555 &chip, byte _clckPin, byte _dataPin, byte _swPin){
  clckPin = _clckPin;
  dataPin = _dataPin;
  swPin = _swPin;    
  if (chip.digitalRead(swPin)== false){
    pressed=true;
  }
  else {
    pressed = false;
  }
  
  clkPinCurrent = chip.digitalRead(clckPin);

  if ((clkPinLast == LOW) && (clkPinCurrent == HIGH)) {
    if (chip.digitalRead(dataPin) == HIGH) {
      down = true;
      up = false;
    }
    else {
      up = true;
      down = false;
    }
  }
  clkPinLast = clkPinCurrent;
}

// Read Rotary Encoder Chip with clckPin, dataPin
void RotaryEncoder::read(TCA9555 &chip, byte _clckPin, byte _dataPin){
  clckPin = _clckPin;
  dataPin = _dataPin;
    
  clkPinCurrent = chip.digitalRead(clckPin);

  if ((clkPinLast == LOW) && (clkPinCurrent == HIGH)) {
    if (chip.digitalRead(dataPin) == HIGH) {
      down = true;
      up = false;
    }
    else {
      up = true;
      down = false;
    }
  }
  clkPinLast = clkPinCurrent;
}

// Read Rotary Encoder Chip with only swPin
void RotaryEncoder::read(TCA9555 &chip, byte _swPin){
  swPin = _swPin;    
  if (chip.digitalRead(swPin)== false){
    pressed=true;
  }
  else {
    pressed = false;
  }
}
