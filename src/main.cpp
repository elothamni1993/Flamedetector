#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED setup
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Pins
#define FLAME_ANALOG_PIN 34
#define LED_PIN 2
#define BUZZER_PIN 15  // Nouveau

#define FLAME_THRESHOLD 1000

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);  // Buzzer pin

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("Erreur OLED !");
    while (true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Systeme Pret...");
  display.display();
  delay(2000);
}

void loop() {
  int flameValue = analogRead(FLAME_ANALOG_PIN);

  Serial.print("Valeur flamme : ");
  Serial.println(flameValue);

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Flamme (A0) : ");
  display.println(flameValue);

  if (flameValue < FLAME_THRESHOLD) {
    // Flamme détectée
    display.setCursor(0, 25);
    display.println("🔥 Flamme detectee !");
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);  // Active le buzzer
  } else {
    // Pas de flamme
    display.setCursor(0, 25);
    display.println("❄️ Pas de flamme");
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);  // Éteint le buzzer
  }

  display.display();
  delay(1000);
}
