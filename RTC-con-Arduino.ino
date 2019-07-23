/*
  Created by TEOS
  Domotic with Arduino https://goo.gl/btZpjs
  YouTube https://goo.gl/k7TUSZ
  Instagram https://goo.gl/zEIjia
  Facebook https://goo.gl/eivraR
  Twitter https://goo.gl/du5Wgn
  Github https://goo.gl/Xl5IiS
  Google Plus https://goo.gl/gBnUdh
  Web https://www.proyecto-teos.com
*/

#include "RTClib.h" //https://github.com/adafruit/RTClib/
#include <Wire.h>

String resultSerialT;
RTC_DS3231 RTCModuleT;

void setup() {
  Serial.begin(9600);
  delay(1000);

  if (!RTCModuleT.begin()) {
    Serial.println(F("No es posible iniciar el modulo RTC"));
    while (1);
  }

  if (RTCModuleT.lostPower())
    RTCModuleT.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void loop() {
  DateTime now = RTCModuleT.now();
  getDateT(now);
  delay(1000);
}

void getDateT(DateTime date) {
  resultSerialT = String(date.hour(), DEC) + ":" + String(date.minute(), DEC) + ":" + String(date.second(), DEC) + " | ";
  resultSerialT += String(date.day(), DEC) + "/" + String(date.month(), DEC) + "/" + String(date.year(), DEC);
  Serial.println(resultSerialT);
}
