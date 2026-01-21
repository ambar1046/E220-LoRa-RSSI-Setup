#include <SoftwareSerial.h>

// CONFIG UART (temporary)
SoftwareSerial lora(8, 9); // RX, TX

void setup() {
  Serial.begin(9600);
  lora.begin(9600);

  delay(2000); // IMPORTANT: wait for module self-check

  Serial.println("Sending RSSI enable command...");

  // Enable RSSI byte: C0 05 01 80
  byte cmd[] = {0xC0, 0x05, 0x01, 0x80};
  lora.write(cmd, sizeof(cmd));
}

void loop() {
  if (lora.available()) {
    Serial.print("Response: ");
    while (lora.available()) {
      byte b = lora.read();
      Serial.print("0x");
      if (b < 0x10) Serial.print("0");
      Serial.print(b, HEX);
      Serial.print(" ");
    }
    Serial.println();
  }
}
