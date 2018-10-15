//#include <Adafruit_NeoPixel.h>
#include <Adafruit_NeoPixel_ZeroDMA.h>

#include <Servo.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN 0 // for LED

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//Adafruit_NeoPixel strip = Adafruit_NeoPixel(12, PIN, NEO_RGBW + NEO_KHZ800);
Adafruit_NeoPixel_ZeroDMA strip(12, PIN, NEO_GRBW);

unsigned long ledInterval = random(0,4);
  
// Servo init
Servo myservo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position
unsigned long servoInterval = random(2000,6000);
unsigned long ledPreviousMillis = 0;        // will store last time LED was updated
unsigned long servoPreviousMillis = 0;        // will store last time servo was updated

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  //strip.setBrightness(8);
  strip.show(); // Initialize all pixels to 'off'
  myservo.attach(1);  // attaches the servo on pin 10 to the servo object

}

void loop() {
  borgEye(strip.Color(0, 0, 0, 2), 128); // White
  borgServo();
}

// Fill the dots one after the other with a color
void borgEye(uint32_t c, uint16_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    paintGlow();
    paintScan(i, c);
    //showRing();
  }  
}

void paintGlow() {
  for(uint16_t i=0; i<strip.numPixels(); i++) {    
    strip.setPixelColor(i, 0, 2, 0, 0);
    strip.show();    
  }
}

void paintScan(uint16_t i, uint32_t c) {
  unsigned long currentMillis = millis();
  for(uint16_t f=0; f < 2; f++) {
      if (currentMillis - ledPreviousMillis >= ledInterval) {
      ledPreviousMillis = currentMillis;
      strip.setPixelColor(i, 0, random(0, 0), 0, random(0, 64));
      showRing();
      //ledInterval = random(0,4);
      //delay(random(0,4));
    }
  }
  
}

void showRing() {
   strip.show();
}

void borgServo () {
  unsigned long currentMillis = millis();
  if (currentMillis - servoPreviousMillis >= servoInterval) {
    //myservo.attach(8);
    pos = random(110, 170);
    servoPreviousMillis = currentMillis;    
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    //delay(random(1000,5000));        // waits some random time for the servo to reach the position
    Serial.println(pos);
    //delay(50);
    //myservo.detach();
  }
}
