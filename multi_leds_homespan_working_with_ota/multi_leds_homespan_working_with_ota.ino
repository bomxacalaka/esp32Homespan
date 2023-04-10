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

#include "HomeSpan.h"
#include "DEV_LED.h"
#include "DEV_Identify.h"
#include "DEV_Sensors.h"

void setup() {

  // Used to control all 6 lights in my room while giving me temperature and 
  //humidity sensor and having a 5 mins moviment detector to turn off the main lights.
  
  Serial.begin(115200);

  homeSpan.enableOTA();
  homeSpan.begin(Category::Bridges, "magic chip");

  new SpanAccessory();
  new DEV_Identify("Bridge #1", "Elongated Tusk Inc.", "Cyka Blyat", "Le potato", "6.9", 3);
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1.1.0");

  new SpanAccessory();
  new DEV_Identify("Printer", "Elongated Tusk Inc.", "Cyka Blyat", "600mA LED", "6.9", 0);
  new DEV_LED(26);

  new SpanAccessory();
  new DEV_Identify("Desk", "Elongated Tusk Inc.", "Cyka Blyat", "600mA LED", "6.9", 0);
  new DEV_LED(25);

  new SpanAccessory();
  new DEV_Identify("UV", "Elongated Tusk Inc.", "Cyka Blyat", "600mA LED", "6.9", 0);
  new DEV_DimmableLED(12);

//  new SpanAccessory();
//  new DEV_Identify("On/Off LED 23", "Elongated Tusk Inc.", "Cyka Blyat", "600mA LED", "6.9", 0);
//  new DEV_DimmableLED(23);

  new SpanAccessory();
  new DEV_Identify("Painting", "Elongated Tusk Inc.", "Cyka Blyat", "600mA LED", "6.9", 0);
  new DEV_DimmableLED(32);

//  new SpanAccessory();
//  new DEV_Identify("On/Off LED 18", "Elongated Tusk Inc.", "Cyka Blyat", "600mA LED", "6.9", 0);
//  new DEV_DimmableLED(18);

  new SpanAccessory();
  new DEV_Identify("IR", "Elongated Tusk Inc.", "Cyka Blyat", "600mA LED", "6.9", 0);
  new DEV_DimmableLED(19);


  new SpanAccessory();
  new DEV_Identify("RGB", "Elongated Tusk Inc.", "Cyka Blyat", "200mA LED", "6.9", 0);
  new DEV_RgbLED(14, 27, 13);


  new SpanAccessory();
  new DEV_Identify("Temp Sensor", "Elongated Tusk Inc.", "MeSensor", "Sensor", "6.9", 0);
  new DEV_TempSensor();

  new SpanAccessory();
  new DEV_Identify("Humidity Sensor", "Elongated Tusk Inc.", "AirWetBrrrSensor", "Sensor", "6.9", 0);
  new DEV_HumSensor();

  new SpanAccessory();
  new DEV_Identify("Motion Sensor", "Elongated Tusk Inc.", "MovimentoSensore", "Sensor", "6.9", 0);
  new DEV_MotionSensor(4);

} // end of setup()

//////////////////////////////////////

void loop() {
  homeSpan.poll();
} // end of loop()
