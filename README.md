# 🔥 ESP32 Flame Detection System

This project uses an **ESP32**, a **KY-026 flame sensor**, an **OLED display**, and a **buzzer** to detect flames and alert the user both visually and audibly.

## 🎯 Features

- 🔥 Detects flame using analog IR detection (`A0`)
- 📟 Displays flame intensity and status on an OLED (SSD1306)
- 🔊 Activates buzzer and LED when flame is detected
- 📈 Adjustable sensitivity using analog threshold

---

## 🛠️ Hardware Required

| Component           | Quantity |
|---------------------|----------|
| ESP32 Dev Module    | 1        |
| KY-026 Flame Sensor | 1        |
| OLED SSD1306 (I2C)  | 1        |
| Buzzer (active)     | 1        |
| LED (optional)      | 1        |
| Jumper Wires        | As needed |
| Breadboard (optional) | 1     |

---

## 🔌 Wiring Diagram

### KY-026 Flame Sensor
| Sensor Pin | ESP32 Pin |
|------------|-----------|
| VCC        | 3.3V      |
| GND        | GND       |
| A0         | GPIO 34   |

### OLED Display (SSD1306 I2C)
| OLED Pin | ESP32 Pin |
|----------|-----------|
| VCC      | 3.3V      |
| GND      | GND       |
| SCL      | GPIO 22   |
| SDA      | GPIO 21   |

### Buzzer
| Buzzer Pin | ESP32 Pin |
|------------|-----------|
| +          | GPIO 13   |
| -          | GND       |

---

## 💻 Software Setup

### `platformio.ini`
```ini
[env:esp32dev]
platform = espressif32
board = esp32dev
framework = arduino
monitor_speed = 115200

lib_deps =
  adafruit/Adafruit SSD1306@^2.5.7
  adafruit/Adafruit GFX Library@^1.11.9
