//Imports Librarys
#include <Adafruit_NeoPixel.h>
#include <Wire.h>


//Light Rin Stuff
#define PIN            6
#define NUMPIXELS      12
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int delayval = 50; // delay between light refreshes
int loopct = 1; //Default Color Variable does not = Color
int Red = 0;
int Green = 255;
int Blue = 0;

//I2C Stuff
int bytes;
char x = 'x';
char xx;


//Program Code
void setup() {
  pixels.begin(); //Initializes the NeoPixel library
  Wire.begin(8); // join i2c bus with address #8
  Wire.onReceive(I2CSlave); // register I2C Command
  Serial.begin(9600);  
}
 
void loop() {
 LightControl(); //Updates Light if Received new Color
}

void I2CSlave(int numbytes){
  bytes = numbytes;
  //xx = Wire.read();
  //Serial.println(xx);
  //if(x == xx){
    Red = Wire.read();
    Serial.println(Red);
    Green = Wire.read();
    Serial.println(Green);
    Blue = Wire.read();
    Serial.println(Blue);
  //}
}

void LightControl(){
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(Red,Green,Blue));
  }
  pixels.show(); //Sends the updated pixel color 
}

