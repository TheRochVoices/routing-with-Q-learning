#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
const byte address1[6] = "00002";
void writeData(String tex)
{
   radio.stopListening();
  radio.openWritingPipe(address1);
  char text[32] = ""; 
  tex.toCharArray(text, 32);
  Serial.println(text);
  radio.write(&text, sizeof(text)); 
    radio.openReadingPipe(0, address);
    radio.startListening();

}


void readData()
{
   if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    String tex = String(text);
    String tex1 = "Fuck you";
    writeData(tex);
    writeData(tex1);
  } 
}


void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}
void loop() {
  readData();
}
