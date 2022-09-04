/*********************************************************************************
    MIT License

    Copyright (c) 2020 Gregg E. Berman

    https://github.com/HomeSpan/HomeSpan

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.

 ********************************************************************************/

////////////////////////////////////////////////////////////
//                                                        //
//    HomeSpan: A HomeKit implementation for the ESP32    //
//    ------------------------------------------------    //
//                                                        //
// Example 10: Controlling a full-color RGB LED           //
//                                                        //
//                                                        //
////////////////////////////////////////////////////////////

#include "HomeSpan.h"
#include "DEV_LED.h"
#include "DEV_Identify.h"
#include "DEV_Sensors.h"
//int sensor = 35;
int leds[10] = {26, 25, 23, 32, 18, 19, 14, 27, 13};
//unsigned long previousMillis = 0;
//const long interval = 30000;

void setup() {

  // Example 10 illustrates how to control an RGB LED to set any color and brightness.
  // The configuration below should look familiar by now.  We've created a new derived Service,
  // call RgbLED to house all the required logic.  You'll find all the code in DEV_LED.h.
  // For completeness, this configuration also contains an on/off LED and a dimmable LED as shown
  // in prior examples.
  for (int i = 0; i < 10; i++) {
    pinMode(leds[i], OUTPUT);
  }

  Serial.begin(115200);

  digitalWrite(25, HIGH);
  digitalWrite(26, HIGH);


  homeSpan.enableOTA(true);
  homeSpan.begin(Category::Bridges, "HomeSpan Bridge");

  //pinMode(sensor,INPUT);

  new SpanAccessory();
  new DEV_Identify("Bridge #1", "Elongated Tusk Inc.", "Cyka Blyat", "Le potato", "6.9", 3);
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1.1.0");

  new SpanAccessory();
  new DEV_Identify("Printer LED", "Elongated Tusk Inc.", "Cyka Blyat", "600mA LED", "6.9", 0);
  new DEV_LED(26);                                                               // Create an On/Off LED attached to pin 16

  new SpanAccessory();
  new DEV_Identify("Desk LEDs", "Elongated Tusk Inc.", "Cyka Blyat", "600mA LED", "6.9", 0);
  new DEV_LED(25);

  new SpanAccessory();
  new DEV_Identify("On/Off LED 12", "Elongated Tusk Inc.", "Cyka Blyat", "600mA LED", "6.9", 0);
  new DEV_LED(12);

  new SpanAccessory();
  new DEV_Identify("On/Off LED 23", "Elongated Tusk Inc.", "Cyka Blyat", "600mA LED", "6.9", 0);
  new DEV_LED(23);

  new SpanAccessory();
  new DEV_Identify("Picture LED", "Elongated Tusk Inc.", "Cyka Blyat", "600mA LED", "6.9", 0);
  new DEV_DimmableLED(32);

  new SpanAccessory();
  new DEV_Identify("On/Off LED 18", "Elongated Tusk Inc.", "Cyka Blyat", "600mA LED", "6.9", 0);
  new DEV_LED(18);

  new SpanAccessory();
  new DEV_Identify("IR led", "Elongated Tusk Inc.", "Cyka Blyat", "600mA LED", "6.9", 0);
  new DEV_DimmableLED(19);


  new SpanAccessory();
  new DEV_Identify("RGB LED", "Elongated Tusk Inc.", "Cyka Blyat", "200mA LED", "6.9", 0);
  new DEV_RgbLED(14, 27, 13);                                                    // Create an RGB LED attached to pins 32,22,23 (for R, G, and B LED anodes)


  new SpanAccessory();
  new DEV_Identify("Temp Sensor", "Elongated Tusk Inc.", "MeSensor", "Sensor", "6.9", 0);// Create a Temperature Sensor (see DEV_Sensors.h for definition)
  new DEV_TempSensor();

  new SpanAccessory();
  new DEV_Identify("Humidity Sensor", "Elongated Tusk Inc.", "AirWetBrrrSensor", "Sensor", "6.9", 0);
  // Create a Humidity Sensor (see DEV_Sensors.h for definition)
  new DEV_HumSensor();

} // end of setup()

//////////////////////////////////////

void loop() {
  homeSpan.poll();

  /*
    unsigned long currentMillis = millis();
    if (digitalRead(sensor) == 1){
    for (int i = 0; i < 10; i++){
      pinMode(leds[i],OUTPUT);
    }previousMillis = millis();}

    if (currentMillis - previousMillis >= interval && digitalRead(sensor) == 1) {
        for (int i = 0; i < 10; i++){
      pinMode(leds[i],INPUT);
    }}*/
} // end of loop()
