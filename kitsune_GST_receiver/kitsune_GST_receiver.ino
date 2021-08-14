#include <SPI.h>
#include <LoRa.h>

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
uint8_t pckt[16];
void setup() {

  LoRa.setPins(7, 8, 3);
  Serial.begin(9600);
  while (!Serial);  

  Serial.println("LoRa Receiver");

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }

}

void loop() {

  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet from GST '");

    // read packet
    while (LoRa.available()) {
//      pckt= LoRa.read();
      for (int i = 0; i<16 ; i++ ){
        pckt[i] = LoRa.read();
      }
//      Serial.print(LoRa.read());
    }
        for(int i = 0; i<16;i++)
    {
        Serial.print(pckt[i],HEX);
        Serial.print(" ");
    }

    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());

//    Serial.print(pckt[0], DEC);
//    Serial.print('/');
    Serial.print(pckt[1], DEC);
    Serial.print('/');
    Serial.print(pckt[2], DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[pckt[3]]);
    Serial.print(") ");
    Serial.print(pckt[4], DEC);
    Serial.print(':');
    Serial.print(pckt[5], DEC);
    Serial.print(':');
    Serial.print(pckt[6], DEC);
    Serial.println();
    Serial.println();
  }

}
