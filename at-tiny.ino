#include <Wire.h>
uint8_t answer[4]={0x40,0x08, 0x00, 0x9E}; // Dieser Code ist die Katalognummer in Hexadezimalformat

void I2C_RxHandler(int numBytes)
{
  Wire.write(answer, sizeof(answer)); // Auf jede Frage mit unserer Nummer reagieren
}
 
void setup() {
  Wire.setClock(250000); // 250 khZ Frequnz
  Wire.begin(0x50); // Auf Adresse 50h reagieren
  Wire.onRequest(I2C_RxHandler);
}
 
void loop() {
}
