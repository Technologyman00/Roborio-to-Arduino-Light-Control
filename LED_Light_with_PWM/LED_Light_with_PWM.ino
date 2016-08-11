//Imports Neopixel stuff
#include <Adafruit_NeoPixel.h>
#include <avr/io.h>

//Out Pin for Light Ring
#define PIN            6

//In Pin for PWM signal
int PWM_PIN = 3;

//PWM SETUP
int pwm_value;


//LED Ring SETUP
#define NUMPIXELS      12
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int delayval = 50; // delay for half a second

//Colors For Lights Stuff
int loopct = 1; //Default Color
 
void setup() {
  pinMode(PWM_PIN, INPUT); //Sets Pin to Input
  pixels.begin(); // This initializes the NeoPixel library.

  //Default Color
  for(int ii=0;ii<NUMPIXELS;ii++){
    pixels.setPixelColor(ii, pixels.Color(0,255,0));
  }
  
}
 
void loop() {
  //
  //Arduino Hz Stuff
  //1020 is the period for 1/980*10^6 to convert seconds to ms port (5 and 6)
  //2040 for most
  //
  //Default Roborio Stuff
  //Default update frequency is 50hz for Roborio
  // Default period 1/50*10^6 = 20000
  //
  //Explanation   (The 1.0 converts to an integer)
  //PWM Integer = (1.0 * Microseconds from High to Low / Period of Refesh Rate in Mircoseconds * The biggest pwm number)
  pwm_value= (1.0 * pulseIn(PWM_PIN, HIGH) / 2040 * 255); //So this is like a huge part of it


   // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    //Ifs for PWM Numbers
    if (pwm_value > 10 && pwm_value < 20){
      //Red
      pixels.setPixelColor(i, pixels.Color(255,0,0));
    }
    if (pwm_value > 20 && pwm_value < 30){
      //Green
      pixels.setPixelColor(i, pixels.Color(0,255,0));
    }
    if (pwm_value > 30 && pwm_value < 40){
      //Blue
      pixels.setPixelColor(i, pixels.Color(0,0,255));
    }
    if (pwm_value > 40 && pwm_value < 50){
      //Orange
      pixels.setPixelColor(i, pixels.Color(255,154,0));
    }
    if (pwm_value > 50 && pwm_value < 60){
      //Yellow
      pixels.setPixelColor(i, pixels.Color(255,255,0));
    }
    if (pwm_value > 60 && pwm_value < 70){
      //Indigo
      pixels.setPixelColor(i, pixels.Color(179,0,255));
    }
    if (pwm_value > 70 && pwm_value < 80){
      //Violet
      pixels.setPixelColor(i, pixels.Color(95,0,135));
    }
    if (pwm_value > 80 && pwm_value < 90){
      //Team Color
      pixels.setPixelColor(i, pixels.Color(27,82,165));
    }
    if (pwm_value > 90 && pwm_value < 100){
      //Cyan
      pixels.setPixelColor(i, pixels.Color(0,230,255));
    }
    if (pwm_value > 100 && pwm_value < 110){
      //Brown
      pixels.setPixelColor(i, pixels.Color(51,0,0));
    }
    if (pwm_value > 110 && pwm_value < 120){
      //Black
      pixels.setPixelColor(i, pixels.Color(0,0,0));
    }
    if (pwm_value > 120 && pwm_value < 130){
      //Grey
      pixels.setPixelColor(i, pixels.Color(192,192,192));
    }
    if (pwm_value > 130 && pwm_value < 140){
      //Pink
      pixels.setPixelColor(i, pixels.Color(255,204,229));
    }
    if (pwm_value > 140 && pwm_value < 150){
      //White
      pixels.setPixelColor(i, pixels.Color(255,255,255));
    }
    if (pwm_value > 150 && pwm_value < 160){
      //Yellow Green
      pixels.setPixelColor(i, pixels.Color(153,255,51));
    }
    if (pwm_value > 160 && pwm_value < 170){
      //Darker Pink
      pixels.setPixelColor(i, pixels.Color(255,51,153));
    }
    
    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).
  } 
}
