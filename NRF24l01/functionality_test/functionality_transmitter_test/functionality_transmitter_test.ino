#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const int _MISO = 20;
const int _MOSI = 19;
const int _CS = 10;
const int _SCK = 18;

RF24 radio(7,8 );  // CE, CSN

const byte address[6] = "00001";

void setup() {
  // SPI.setRX(_MISO);
  // SPI.setTX(_MOSI);
  // SPI.setSCK(_SCK);

  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  const char text[] = "Hello";
  radio.write(&text, sizeof(text));
  delay(1000);
}