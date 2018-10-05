#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 8

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(12, PIN, NEO_RGBW + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  //strip.setBrightness(8);
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  // Some example procedures showing how to display to the pixels:
  borgEye(strip.Color(0, 0, 0, 2), 128); // White
//  borgEye(strip.Color(0, 0, 0, 255), 100); // white
}

// Fill the dots one after the other with a color
void borgEye(uint32_t c, uint16_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    paintGlow();
    paintScan(i, c);
    showRing();
    //delay(wait);
  }
  
}

void paintGlow() {
  for(uint16_t i=0; i<strip.numPixels(); i++) {    
    strip.setPixelColor(i, random(2, 2), 0, 0, 0);    
  }
}

void paintScan(uint16_t i, uint32_t c) {
  for(uint16_t f=0; f < 2; f++) {
    /*
    if(i < 10) {
      strip.setPixelColor(i, 0, 0, 0, random(2, 8));
      strip.setPixelColor(i+1, 0, 0, 0, random(2, 8));
      strip.setPixelColor(i+2, 0, 0, 0, random(2, 8));
    }
    if(i == 10) {
      strip.setPixelColor(i, 0, 0, 0, random(2, 8));
      strip.setPixelColor(i+1, 0, 0, 0, random(2, 8));
      strip.setPixelColor(i-10, 0, 0, 0, random(2, 8));
    }
    
    if(i > 10) {
      strip.setPixelColor(i, 0, 0, 0, random(2, 8));
      strip.setPixelColor(i-10, 0, 0, 0, random(2, 8));
      strip.setPixelColor(i-11, 0, 0, 0, random(2, 8));
    }
    */
    strip.setPixelColor(i, 0, random(0, 0), 0, random(0, 4));
    showRing();
    delay(random(0,4));
  }
  
}

void showRing() {
   strip.show();
}

