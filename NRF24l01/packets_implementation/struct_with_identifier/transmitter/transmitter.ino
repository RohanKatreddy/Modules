#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(6, 7); // CE, CSN

const byte address[6] = "00001";

struct send_structure {
  int key;
  char text;
};

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  send_structure data;
  data.key = 1;
  data.text = 'H';
  radio.write(&data, sizeof(data));
  delay(1000);
  data.key = 2;
  data.text = 'W';
  radio.write(&data, sizeof(data));
}