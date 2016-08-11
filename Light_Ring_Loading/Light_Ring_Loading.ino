#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

int ii;

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  theaterChase(); // White
}

//Theatre-style crawling lights.
void theaterChase() {
  for (int j=0; j<10000; j++) {  //do 10 cycles of chasing
      ii = 12;
      for (int i=0; i < 12; i=i+1) {
        strip.setPixelColor(i, strip.Color(5, 5, 5));
        strip.setPixelColor(ii, strip.Color(5, 5, 5));
        strip.show();
      delay(85);
        strip.setPixelColor(i, 0); 
        strip.setPixelColor(ii, 0);        
        strip.show();
      delay(85); 
        ii=ii-1;
    }
  }
}
