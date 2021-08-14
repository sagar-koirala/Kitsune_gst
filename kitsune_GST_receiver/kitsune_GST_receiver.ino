#include <SPI.h>
#include <LoRa.h>

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
      Serial.print(LoRa.read());

    }

    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  }

}
