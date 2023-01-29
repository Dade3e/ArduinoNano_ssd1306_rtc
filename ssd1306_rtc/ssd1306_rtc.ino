//OLED TIME


#include <SPI.h>

#include <Wire.h>

#include <Adafruit_GFX.h>

#include <Adafruit_SSD1306.h>

#include <Time.h>
#include "RTClib.h"

RTC_DS1307 DS1307_RTC;

char Week_days[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};



#define OLED_RESET 4

Adafruit_SSD1306 display(OLED_RESET);


void setup()

{


  //Serial.begin(9600);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  //indirizzo I2C 0x3D (per il 128x64)

  //display.display();

  display.clearDisplay();

  display.setTextSize(1);

  display.setTextColor(WHITE);

  display.clearDisplay();

  if (!DS1307_RTC.begin()) {
    Serial.println("Couldn't find RTC");
    while(1);
  }
   DS1307_RTC.adjust(DateTime(F(__DATE__), F(__TIME__)));


}


void loop()

{


  DateTime now = DS1307_RTC.now();

  schermata(now);

  delay(1000);


}

void schermata(DateTime now){
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(20,10);
  display.print(now.hour());
  display.print(" : ");
  display.print(now.minute());
  display.display();
}
