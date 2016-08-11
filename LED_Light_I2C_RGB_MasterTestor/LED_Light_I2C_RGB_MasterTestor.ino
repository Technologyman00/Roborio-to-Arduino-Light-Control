// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI slave device
// Refer to the "Wire Slave Receiver" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

char x = 'x';
int x1;
int x2;
int x3;

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
  delay(1000);
  Serial.begin(9600);
}

void loop() {
  Wire.beginTransmission(8); // transmit to device #8
  //Wire.write(x);
  x1 = random(0,254);
  Wire.write(x1);
  x2 = random(0,254);
  Wire.write(x2);
  x3 = random(0,254);
  Wire.write(x3);
  Wire.endTransmission();    // stop transmitting
    Serial.println(x);
    Serial.println(x1);
    Serial.println(x2);
    Serial.println(x3);
  delay(1000);
  //Wire.beginTransmission(8); // transmit to device #8
  //x1 = random(0,254);
 //Wire.write(x1);
  //x2 = random(0,254);
  //Wire.write(x2);
 // x3 = random(0,254);
  //Wire.write(x3);
  //Wire.endTransmission();    // stop transmitting
     // Serial.println(x1);
      //Serial.println(x2);
     // Serial.println(x3);
  //delay(1000);
}
