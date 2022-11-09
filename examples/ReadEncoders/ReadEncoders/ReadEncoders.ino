// Example for handling 5 Rotary encoders over 2 TCA9555 bus expanders with one common interrupt
// Encoders can be splittet over two chips, function overloading is used to read also less than all pins all together

#include "RotaryEncoder.h"

// define interrupt pin of i2c bus expanders (TCA9555)
#define interruptPin 10

// create new Bus encoder objects (address)
TCA9555 U3(0x38);
TCA9555 U2(0x39);

// create Rotary Encoder objects
RotaryEncoder Encoder[5];

void setup() {
  // begin Serial output
  Serial.begin(9600);
  Serial.println("Microcontroller has started");

  // begin wire communication (i2c)
  Wire.begin();   
  Wire.setClock(400000);
  delay(5);

  // put your setup code here, to run once:
  pinMode(interruptPin, INPUT);  // Set interruptPin as INPUT with internal Pull-Up Resistors
  attachInterrupt(digitalPinToInterrupt(interruptPin), readEncoders, CHANGE); // Create Interrupt on interrupt pin with ISR on CHANGE

}

void loop() {
  // put your main code here, to run repeatedly:

}

// ISR Routine for Rotary Encoders
void readEncoders(){
  Encoder[0].read(U3, 0, 1, 2);
  Encoder[1].read(U3, 3, 7, 6);
  Encoder[2].read(U3, 5, 4);
  Encoder[2].read(U2, 0);
  Encoder[3].read(U2, 1, 2, 3);
  Encoder[4].read(U2, 7, 6, 5); 
}