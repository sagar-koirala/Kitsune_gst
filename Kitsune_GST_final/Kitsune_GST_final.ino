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
        Serial.print(pckt[i],DEC);
        Serial.print(" ");
    }
    Serial.println("");
    Serial.println("");
    Serial.println("");
    LoRa.beginPacket();
    LoRa.write(pckt,sizeof(pckt));
    LoRa.endPacket();
   
    counter++;
}

void createPackt() {
  DateTime now = (rtc.now()+ TimeSpan(0, 0, 0, 3));
  pckt[0] = now.year()>>8;
  pckt[1] = now.year();
  pckt[2] = now.month();
  pckt[3] = now.day();
  pckt[4] = now.dayOfTheWeek();
  pckt[5] = now.hour();
  pckt[6] = now.minute();
  pckt[7] = now.second();
//  pckt[8] = now.second();
//  pckt[9] = now.second();e
  pckt[10] = analogRead(batt_volt_pin);
  pckt[11] = analogRead(sp_volt_pin);
  pckt[12] = analogRead(batt_current_pin);
}
