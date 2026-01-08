/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-dht22
 */

#include <Arduino.h>
#include <SD.h>
#include <SPI.h>

#define PIN_SPI_CS 5 // connect esp32 to SD card adapter

File myfile;

void setup() {
Serial.begin(115200);

bool sd_ready = SD.begin(PIN_SPI_CS);
if (sd_ready == false)
{
    while(true)
    {
        Serial.println("Failed to read SD card.");
        delay(1000);
    }
}
Serial.println("Successful to read SD card.");

}

void loop() {
  // wait a 2 seconds between readings
delay(2000);
myfile = SD.open("/DHT22_log.txt", FILE_APPEND);
if(myfile)
{
    while(myfile.available())
    {
        char ch = myfile.read();
        Serial.print(ch);
    }
    myfile.close();
    }
else
{
    Serial.println("Failed to open the file.");
}
}