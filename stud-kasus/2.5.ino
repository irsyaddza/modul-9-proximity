#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Alamat LCD dapat disesuaikan sesuai modul LCD Anda

const int buttonPin = 7;        // Pin push button
const int proximitySensorPin = A0; // Pin sensor proximity
const int buzzerPin = 8;         // Pin buzzer
const int ledPin = 9;            // Pin LED untuk PWM

int buttonState = 0;             // Status tombol
int lastButtonState = 0;
int mode = 0;                    // Mode operasi
int proximityValue = 0;          // Nilai pembacaan sensor proximity
int threshold = 400;             // Batas nilai proximity untuk peringatan

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  lcd.setCursor(0, 0);
  lcd.print("Proximity System");
  delay(1000);
  lcd.clear();
}

void loop() {
  // Baca status tombol
  buttonState = digitalRead(buttonPin);

  // Jika tombol ditekan, ubah mode
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      mode++;
      if (mode > 3) mode = 1;  // Kembali ke mode 1 setelah mode 3
      delay(500);  // Debounce
    }
  }
  lastButtonState = buttonState;

  // Baca nilai sensor proximity
  proximityValue = analogRead(proximitySensorPin);

  switch (mode) {
    case 1:
      // Mode 1: Tampilkan nilai proximity di LCD dan Serial Monitor
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Proximity:");
      lcd.setCursor(0, 1);
      lcd.print(proximityValue);
      Serial.print("Mode 1 - Proximity Value: ");
      Serial.println(proximityValue);
      delay(500);
      break;

    case 2:
      // Mode 2: Jika proximity melewati threshold, aktifkan buzzer dan peringatan di LCD dan Serial
      if (proximityValue > threshold) {
        digitalWrite(buzzerPin, HIGH); // Aktifkan buzzer
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Warning!");
        lcd.setCursor(0, 1);
        lcd.print("Proximity High");
        Serial.println("Mode 2 - Warning! Proximity High");
      } else {
        digitalWrite(buzzerPin, LOW); // Matikan buzzer
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Proximity OK");
        lcd.setCursor(0, 1);
        lcd.print("Value:");
        lcd.print(proximityValue);
        Serial.print("Mode 2 - Proximity Value: ");
        Serial.println(proximityValue);
      }
      delay(500);
      break;

    case 3:
      // Mode 3: Tampilkan nilai proximity di LCD dan Serial, dan fungsikan LED sebagai PWM
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("LED PWM:");
      lcd.setCursor(0, 1);
      lcd.print(proximityValue);
      Serial.print("Mode 3 - LED PWM Value: ");
      Serial.println(proximityValue);
      int ledPWM = map(proximityValue, 0, 1023, 0, 255); // Sesuaikan rentang PWM LED
      analogWrite(ledPin, ledPWM);
      delay(500);
      break;
  }
}