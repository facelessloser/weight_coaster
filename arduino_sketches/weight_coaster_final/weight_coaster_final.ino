#include "HX711.h"
#include <EEPROM.h>

// HX711.DOUT	- pin #A1
// HX711.PD_SCK	- pin #A0

HX711 scale(A1, A0); // parameter "gain" is ommited; the default value 128 is used by the library

// Ws2812 stuff
#include <Adafruit_NeoPixel.h>
#define PIXEL_PIN 3 // Digital IO pin connected to the NeoPixels.

#define PIXEL_COUNT 12 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

boolean readOnce = 1;
boolean firstButtonOnly = 0;
boolean secondButtonOnly = 0;
boolean weighing = 0;
boolean weighingFirstButton = 0;
boolean weighingSecondButton = 0;
int modePicker = 0;
int modePicker1 = 0;

// Ws2812 stuff

int readingScale;
int readingMap;
int ledNumber = 0;
int clearLedNumber = 0;
int emptyLedNumber = 0;
int ledNumber1 = 0;

// Button stuff
const int button = 5; // Button set to pin 5
long time_button = 0; // the last time the output pin was toggled
long debounce = 50; // the debounce time, increase if the output flickers
int reading_button; // the current reading from the input pin
int previous_button = HIGH; // the previous reading from the input pin
// Button stuff

// Button stuff
const int button1 = 4; // Button set to pin 5
long time_button1 = 0; // the last time the output pin was toggled
//long debounce = 50; // the debounce time, increase if the output flickers
int reading_button1; // the current reading from the input pin
int previous_button1 = HIGH; // the previous reading from the input pin
// Button stuff

// Latch stuff
const int latchPin = 10; // the number of the latchbutton pin
int buttonState = 0; // variable for reading the pushbutton status

// eeprom stuff
int emptyGlass;
int fullGlass;
int addrLow = 0;
int addrHigh = 1;

// millus stuff
long readGlassSince = 0;
long readGlassWait = 200;
unsigned long blinkSince = 0;  // Millis wait times
unsigned long blinkWait = 40;  // Millis wait times

int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by
//unsigned long blinkSince = 0;  // Millis wait times
//unsigned long blinkWait = 40;  // Millis wait times
uint16_t i;

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    //    delay(wait);
  }
}

void setup() {

  strip.setPixelColor(0, 0, 0, 255);  // Green 
  strip.show(); // Initialize all pixels to 'off'

  pinMode(button, INPUT); // Set the button as input
  digitalWrite(button, HIGH); // initiate the internal pull up resistor

  pinMode(button1, INPUT); // Set the button as input
  digitalWrite(button1, HIGH); // initiate the internal pull up resistor

  pinMode(latchPin, INPUT);
  digitalWrite(latchPin, HIGH); // initiate the internal pull up resistor

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  Serial.begin(9600); // Start serial
  scale.set_scale(2280.f); // this value is obtained by calibrating the scale with known weights; see the README for details
  scale.tare(); // reset the scale to 0
  strip.setPixelColor(0, 0, 0, 0);  // off 
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {

  emptyLedNumber = 0;
  clearLedNumber = 0;
  ledNumber = 0;
  ledNumber1 = 0;
  buttonState = digitalRead(latchPin);

  if (weighing == 0)
  {

    if (millis() - readGlassSince >= readGlassWait)
    {
      readGlassSince = millis();
      readingScale = scale.get_units(), 1;
    }

    if (readingScale >= emptyGlass )
    {
      //      readingMap = map(readingScale, 0, fullGlass, 0, 12);
      readingMap = map(readingScale, emptyGlass, fullGlass, 0, 11);
      //    Serial.print("readingMap ");
      //    Serial.println(readingMap);
      while (ledNumber <= readingMap)
      {
        strip.setPixelColor(ledNumber, 0, 255, 0); // Green 
        ledNumber = ledNumber + 1;
        strip.show(); // Initialize all pixels
      }

    }

    else if (readingScale <= emptyGlass && readingScale >= 10)
    {
      while (emptyLedNumber <= 11)
      {
        strip.setPixelColor(emptyLedNumber, 255, 0, 0); // Red
        emptyLedNumber = emptyLedNumber + 1;
        strip.show(); // Initialize all pixels
      }
    }

    else
    {
      //    Serial.println("no glass");
      while (clearLedNumber <= 11)
      {
        strip.setPixelColor(clearLedNumber, 0, 0, 0); // Off 
        clearLedNumber = clearLedNumber + 1;
        strip.show(); // Initialize all pixels to 'off'
      }
    }

    // if (modePicker == 0)
    // {
    //
    //
    //  }
  }

  if (weighingFirstButton == 1)
  {
    if (modePicker == 1)
    {
      //    Serial.println("modePicker 1 ");
      if (millis() - blinkSince >= blinkWait) 
      {
        blinkSince = millis();
        brightness = brightness + fadeAmount;

        colorWipe(strip.Color(brightness, brightness, brightness), 0); // White?

        strip.show(); // Initialize all pixels

        if (brightness <= 0 || brightness >= 255) 
        {
          fadeAmount = -fadeAmount ; 
        }
      }
    }


    if (modePicker == 2) {
      //    Serial.println("modePicker 1 ");
      if (millis() - blinkSince >= blinkWait) 
      {
        blinkSince = millis();
        brightness = brightness + fadeAmount;

        colorWipe(strip.Color(brightness, 0, 0), 0); // Red

        strip.show(); // Initialize all pixels

        if (brightness <= 0 || brightness >= 255) 
        {
          fadeAmount = -fadeAmount ; 
        }
      }
    }

    if (modePicker == 3) {
      //    Serial.println("modePicker 1 ");
      if (millis() - blinkSince >= blinkWait) 
      {
        blinkSince = millis();
        brightness = brightness + fadeAmount;

        colorWipe(strip.Color(0, brightness, 0), 0); // Green

        strip.show(); // Initialize all pixels

        if (brightness <= 0 || brightness >= 255) 
        {
          fadeAmount = -fadeAmount ; 
        }
      }
    }

    if (modePicker == 4) {
      //    Serial.println("modePicker 1 ");
      if (millis() - blinkSince >= blinkWait) 
      {
        blinkSince = millis();
        brightness = brightness + fadeAmount;

        colorWipe(strip.Color(0, 0, brightness), 0); // Blue

        strip.show(); // Initialize all pixels

        if (brightness <= 0 || brightness >= 255) 
        {
          fadeAmount = -fadeAmount ; 
        }
      }
    }

    if (modePicker == 5) {
      //    Serial.println("modePicker 1 ");
      if (millis() - blinkSince >= blinkWait) 
      {
        blinkSince = millis();
        brightness = brightness + fadeAmount;

        colorWipe(strip.Color(0, brightness, brightness), 0); // Light blue

        strip.show(); // Initialize all pixels

        if (brightness <= 0 || brightness >= 255) 
        {
          fadeAmount = -fadeAmount ; 
        }
      }
    }

    if (modePicker == 6) {
      //    Serial.println("modePicker 1 ");
      if (millis() - blinkSince >= blinkWait) 
      {
        blinkSince = millis();
        brightness = brightness + fadeAmount;

        colorWipe(strip.Color(brightness, brightness, 0), 0); // Yellow

        strip.show(); // Initialize all pixels

        if (brightness <= 0 || brightness >= 255) 
        {
          fadeAmount = -fadeAmount ; 
        }
      }
    }

    if (modePicker == 7) {
      //    Serial.println("modePicker 1 ");
      if (millis() - blinkSince >= blinkWait) 
      {
        blinkSince = millis();
        brightness = brightness + fadeAmount;

        colorWipe(strip.Color(brightness, 0, brightness), 0); // Pink

        strip.show(); // Initialize all pixels

        if (brightness <= 0 || brightness >= 255) 
        {
          fadeAmount = -fadeAmount ; 
        }
      }
    }
  }

  if (weighingSecondButton == 1)
  {

    if (modePicker1 == 1)
    {
      //  ledNumber1 = 11;
      while (ledNumber1 <= 11)
      {
        strip.setPixelColor(ledNumber1, 255, 255, 255); // White
        ledNumber1 = ledNumber1 + 1;
        strip.show(); // Initialize all pixels
      }
    }

    if (modePicker1 == 2)
    {
      //  ledNumber1 = 11;
      while (ledNumber1 <= 11)
      {
        strip.setPixelColor(ledNumber1, 0, 255, 0); // Green 
        ledNumber1 = ledNumber1 + 1;
        strip.show(); // Initialize all pixels
      }
    }

    if (modePicker1 == 3)
    {
      //  ledNumber1 = 11;
      while (ledNumber1 <= 11)
      {
        strip.setPixelColor(ledNumber1, 255, 0, 0); // Red 
        ledNumber1 = ledNumber1 + 1;
        strip.show(); // Initialize all pixels
      }
    }

    if (modePicker1 == 4)
    {
      //  ledNumber1 = 11;
      while (ledNumber1 <= 11)
      {
        strip.setPixelColor(ledNumber1, 0, 0, 255); // Blue 
        ledNumber1 = ledNumber1 + 1;
        strip.show(); // Initialize all pixels
      }
    }

    if (modePicker1 == 5)
    {
      //  ledNumber1 = 11;
      while (ledNumber1 <= 11)
      {
        strip.setPixelColor(ledNumber1, 0, 127, 127); // Light blue 
        ledNumber1 = ledNumber1 + 1;
        strip.show(); // Initialize all pixels
      }
    }

    if (modePicker1 == 6)
    {
      //  ledNumber1 = 11;
      while (ledNumber1 <= 11)
      {
        strip.setPixelColor(ledNumber1, 127, 127, 0); // Yellow 
        ledNumber1 = ledNumber1 + 1;
        strip.show(); // Initialize all pixels
      }
    }

    if (modePicker1 == 7)
    {
      //  ledNumber1 = 11;
      while (ledNumber1 <= 11)
      {
        strip.setPixelColor(ledNumber1, 127, 0, 127); // Pink 
        ledNumber1 = ledNumber1 + 1;
        strip.show(); // Initialize all pixels
      }
    }
  }

  if (readOnce == 1)
  {
    emptyGlass = EEPROM.read(addrLow)+5;
    fullGlass = EEPROM.read(addrHigh);
    Serial.print("Empty glass ");
    Serial.println(emptyGlass);
    Serial.print("Full glass ");
    Serial.println(fullGlass);
    readOnce = 0;
  }

  if (buttonState == LOW) 
  {
    readOnce = 1;

    // ------------- Debound code button green start code -------------
    reading_button = digitalRead(button);

    if (reading_button == HIGH && previous_button == LOW && millis() - time_button > debounce) { 
      time_button = millis(); 
      // Do something here
      Serial.println("Setting empty glass");
      EEPROM.write(addrLow, readingScale);
    }
    previous_button = reading_button;

    // -------------- Debound code button green end code -------------

    // ------------- Debound code button green start code -------------
    reading_button1 = digitalRead(button1);

    if (reading_button1 == HIGH && previous_button1 == LOW && millis() - time_button1 > debounce) { 
      time_button1 = millis(); 
      // Do something here
      Serial.println("Setting full glass");
      EEPROM.write(addrHigh, readingScale);
    }
    previous_button1 = reading_button1;

    // -------------- Debound code button green end code -------------
  }

  // ------------- Debound code button green start code -------------
  reading_button = digitalRead(button);

  if (secondButtonOnly == 0)
  {
    if (reading_button == HIGH && previous_button == LOW && millis() - time_button > debounce) { 
      time_button = millis(); 
      // Do something here
//      Serial.println("first button different mode");
      modePicker += 1;
      firstButtonOnly = 1;
      weighing = 1;
      weighingFirstButton = 1;
      if (modePicker == 8)
      {
        modePicker = 0;
        firstButtonOnly = 0;
        weighing = 0;
        weighingFirstButton = 0;
      }
    }
    previous_button = reading_button;

    // -------------- Debound code button green end code -------------
  }

  // ------------- Debound code button green start code -------------
  reading_button1 = digitalRead(button1);

  if (firstButtonOnly == 0)
  {
    if (reading_button1 == HIGH && previous_button1 == LOW && millis() - time_button1 > debounce) { 
      time_button1 = millis(); 
      // Do something here
//      Serial.println("second button different mode");
      modePicker1 += 1;
      secondButtonOnly = 1;
      weighing = 1;
      weighingSecondButton = 1;
      if (modePicker1 == 8)
      {
        secondButtonOnly = 0;
        weighing = 0;
        weighingSecondButton = 0;
        modePicker1 = 0;
      }
      Serial.println(modePicker1);
    }
    previous_button1 = reading_button1;

    // -------------- Debound code button green end code -------------
  }
}

