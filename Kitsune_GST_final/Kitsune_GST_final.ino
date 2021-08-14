/***********including Libraries*******/
#include <RTClib.h>  
#include <SPI.h>
#include <LoRa.h>


/*********defining pins****/
#define batt_volt_pin A5
#define sp_volt_pin A4
#define batt_current_pin A1
#define sp_current_pin  A0

RTC_PCF8523 rtc;
uint8_t pckt[16] ;
int counter = 0;

void setup() {

  Serial.begin(57600);
  Serial1.begin(9600);

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  if (! rtc.initialized()) {
    Serial.println("RTC is NOT running!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));    //adjust time after a power loss
    }
//    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));    //adjust time on previously configured device
    rtc.start();

  Serial.println("Kitsune GST");
  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);}
}

void loop() {
  createPackt();
    Serial.print("Sending packet: ");
    Serial.print(counter);
    Serial.print(":    ");
    
    for(int i = 0; i<16;i++)
    {
        Serial.print(pckt[i],HEX);
        Serial.print(" ");
    }
    Serial.println("");
    LoRa.beginPacket();
    LoRa.write(pckt,16);
    LoRa.endPacket();
   
    counter++;
}

void createPackt() {
  DateTime now = (rtc.now()+ TimeSpan(0, 0, 0, 3));
  pckt[0] = now.year();
  pckt[1] = now.month();
  pckt[2] = now.day();
  pckt[3] = now.dayOfTheWeek();
  pckt[4] = now.hour();
  pckt[5] = now.minute();
  pckt[6] = now.second();
//  pckt[7] = now.second();
//  pckt[8] = now.second();
//  pckt[9] = now.second();
  pckt[10] = analogRead(batt_volt_pin);
  pckt[11] = analogRead(sp_volt_pin);
  pckt[12] = analogRead(batt_current_pin);
//  pckt[0] = now.second();
//  pckt[0] = now.second();
}
