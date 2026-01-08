#include <Arduino.h>
#include <DHT.h>
#include <SD.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <iostream> // using for normal operation in c++

// setup screen OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3c
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// setup sensor DHT22
#define DHT22_PIN  33 // connect esp32 to DHT22 sensor
DHT dht22(DHT22_PIN, DHT22);

// setup SD card adapter
#define PIN_SPI_CS 5 // connect esp32 to SD card adapter
File myfile;

// declare variable using to count amount of data that log into SD card
int max_samples = 5;
int sampleCount = 0;

String text_output[3] = {"rh [%] : ", "tempC : ", "tempF : "};
float text_output_value[3] = {};

void setup()
{
  Serial.begin(115200);
  dht22.begin(); // initialize the DHT22 sensor

  // checking SD card adapter
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

  // checking display OLED
  bool display_ready = display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  if (!display_ready)
  {
    Serial.println("Display allocation failed");
    while(true)
    {
      delay(1000);
    }
  }
  Serial.println("Display allocation succeed");

  display.clearDisplay();
  
  // setup setting text output
  display.setTextSize(1);
  display.setTextColor(WHITE);
}

void loop()
{
  if (sampleCount >= max_samples)
  {
    Serial.println("Logging Finished.");
    while(true);
  }
  // read humidity
  float humi  = dht22.readHumidity(); text_output_value[0] = humi;
  // read temperature in Celsius
  float tempC = dht22.readTemperature(); text_output_value[1] = tempC;
  // read temperature in Fahrenheit
  float tempF = dht22.readTemperature(true); text_output_value[2] = tempF;

  // check whether the reading is successful or not
  if ( isnan(tempC) || isnan(tempF) || isnan(humi)) 
  {
    Serial.println("Failed to read from DHT22 sensor!");
  } else
  {
    for (int i = 0; i < 3; i++)
    {
      Serial.print(text_output[i]);
      Serial.print(text_output_value[i]);
      Serial.print("  |  ");
    }
    Serial.println("");
  }
  // sampleCount++;

  myfile = SD.open("/DHT22_log.txt", FILE_APPEND);
  if(myfile)
  {
    for (int i = 0; i < 3; i++)
    {
      myfile.print(text_output[i]); myfile.print(text_output_value[i]); myfile.print("  |  ");
    }
    myfile.println(""); myfile.close(); sampleCount++;
    Serial.print("sampleCount: "); Serial.println(sampleCount);
    Serial.println("Data saved to SD card.");
  }
  else
  {
    Serial.println("Failed to open the file.");
  }

  // output data to OLED screen
  // output outside of screen fix it by using "display.setcursor()"
  for (int i = 0; i < 3; i++)
  {
    display.setCursor(0, 28);
    display.print(text_output[i]); display.println(text_output_value[i]);
    display.display(); delay(3000); display.clearDisplay(); display.display();
  }
}