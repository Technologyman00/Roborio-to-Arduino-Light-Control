//Imports Librarys
#include <Adafruit_NeoPixel.h>
#include <Wire.h>


//Light Rin Stuff
#define PIN            6
#define NUMPIXELS      12
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int delayval = 50; // delay between light refreshes
int loopct = 1; //Default Color Variable does not = Color
byte color = -1;




//Program Code
void setup() {
  pixels.begin(); //Initializes the NeoPixel library
  Wire.begin(8); // join i2c bus with address #8
  Wire.onReceive(I2CSlave); // register I2C Command
  Serial.begin(9600);   // start serial for output

  for(int ii=0;ii<NUMPIXELS;ii++){
    pixels.setPixelColor(ii, pixels.Color(0,255,0));
  }
  
}
 
void loop() {
 LightControl(); //Updates Light if Received new Color
}

void I2CSlave(){
  color = Wire.read();
  Serial.println(color);
}

void LightControl(){

   // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    //ifs for Colors
    if (color == 0){
      //Off or Black
      pixels.setPixelColor(i, pixels.Color(0,0,0));
    }
    if (color == 1){
      //Red
      pixels.setPixelColor(i, pixels.Color(255,0,0));
    }
    if (color == 2){
      //Green
      pixels.setPixelColor(i, pixels.Color(0,255,0));
    }
    if (color == 3){
      //Blue
      pixels.setPixelColor(i, pixels.Color(0,0,255));
    }
    if (color == 4){
      //Orange
      pixels.setPixelColor(i, pixels.Color(255,154,0));
    }
    if (color == 5){
      //Yellow
      pixels.setPixelColor(i, pixels.Color(255,255,0));
    }
    if (color == 6){
      //Indigo
      pixels.setPixelColor(i, pixels.Color(179,0,255));
    }
    if (color == 7){
      //Violet
      pixels.setPixelColor(i, pixels.Color(95,0,135));
    }
    if (color == 8){
      //Team Color
      pixels.setPixelColor(i, pixels.Color(27,82,165));
    }
    if (color == 9){
      //Cyan
      pixels.setPixelColor(i, pixels.Color(0,230,255));
    }
    if (color == 10){
      //Brown
      pixels.setPixelColor(i, pixels.Color(51,0,0));
    }
    if (color == 11){
      //Grey
      pixels.setPixelColor(i, pixels.Color(192,192,192));
    }
    if (color == 12){
      //Pink
      pixels.setPixelColor(i, pixels.Color(255,204,229));
    }
    if (color == 13){
      //White
      pixels.setPixelColor(i, pixels.Color(255,255,255));
    }
    if (color == 14){
      //Yellow Green
      pixels.setPixelColor(i, pixels.Color(153,255,51));
    }
    if (color == 15){
      //Darker Pink
      pixels.setPixelColor(i, pixels.Color(255,51,153));
    }
    
    pixels.show(); //Sends the updated pixel color

    delay(delayval); // Delay for a period of time (in milliseconds)
  }  
}

