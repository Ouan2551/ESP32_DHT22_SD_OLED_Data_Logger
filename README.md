# 🗃️ ESP32_DHT22_SD_OLED_Data_Logger

# 📝 Introduction
This project uses an ESP32 microcontroller to read temperature and humidity data from a DHT22 sensor and log the data to an SD card for offline analysis. The project focues on practicing embedded systems fundamentals such as sensor interfacing, SPI communication and data logging.

# 🧠 What I learn
- Basic usage of the ESP32 and how to interface it with external sensors.
- How to read and understand datasheets for wiring and coding.
- Problem analysis and real world troubleshooting.
- Selecting hardware components that match project requirements.
- Time management during development.

# 🛣️ What I do
- Learned how to use the ESP32 with multiple external components.
- Learned how to connect and programmed the ESP32 to work with sensors and modules.

# 🛠️ Challenges
- Choosing compatible hardware components for the project.
- Making hardware connections and software work together correctly.

# 📸 Tools I Used
- VS Code
- PlatformIO (extension for complie and editor on Vs code.)
- ESP32 board (ESP-WROOM-32/ NodeMCU-32S)
- Breadboard
- Micro SD Card Module
- Base for ESP32
- DHT22 Module
- OLED Graphic Display Module
- Jumper Wire (Male to Male, Male to Female, Female to Female)
- Google, YouTube, ChatGPT (for learning and help me during coding)

# ⚙️ System overview
DHT22 Module -> ESP32 board -> Micro SD Card Module -> OLED Graphic Display Module

# 📁 How it works
- The ESP32 reads temperature and humidity data from the DHT22 sensor
- The data is logged to an SD card using the SD card module
- The data readings are displayed on the OLED screen

# 🔰 How to run/ use
- Connect all components to the ESP32 according to the wiring setup
- Insert a FAT32-formatted SD card into the SD card module
- Upload the code to the ESP32
- Monitor the output on the Serial Monitor and OLED display

# 📛 What I do wrong for future improvements
- Using mutiples .cpp files in the main folders caused PlatformIO to crash during compilation.
- Using an SD card larger than 32GB or not formatted as FAT32 caused detection issues.
- Forgetting to check which file was currently active on VS CODE led to unnecessary debugging.
