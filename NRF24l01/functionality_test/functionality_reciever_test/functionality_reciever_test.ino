#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const int _MISO = 20;
const int _MOSI = 19;
const int _CS = 10;
const int _SCK = 18;

RF24 radio(3, 2); // CE, CSN

const byte address[6] = "00001";

void setup()
{
  //   SPI.setRX(_MISO);
  // SPI.setTX(_MOSI);
  // SPI.setSCK(_SCK);
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop()
{
  if (radio.available())
  {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
  }
}