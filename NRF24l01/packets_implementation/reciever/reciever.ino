#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(6, 7); // CE, CSN

const byte address[6] = "00001";
String full_string = "";

struct recieve_structure {
  int key;
  char text;
};

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  
  if (radio.available()) {
    recieve_structure data;
    radio.read(&data, sizeof(data));
    if (data.key == 1){
      full_string = data.text;
    }
    if (data.key == 2){
      full_string += data.text;
      Serial.println(full_string);
    }
  }
}