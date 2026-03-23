#include <LiquidCrystal.h>

// Ustawienie pinów LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int tempPin = A0;
const int enA = 9;      // Pin ENA w L298N
const int in1 = 8;      // Pin IN1 w L298N
const int in2 = 7;      // Pin IN2 w L298N

void setup() {
  lcd.begin(16, 2);
  lcd.print("System Start...");
  
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  
  delay(1500);
  lcd.clear();
}

void loop() {
  // Odczyt TMP36
  int raw = analogRead(tempPin);
  float voltage = raw * 5.0 / 1024.0;
  float tempC = (voltage - 0.5) * 100.0;

  // Linia 1: Temperatura
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(tempC, 1); // ,1 oznacza jedno miejsce po przecinku
  lcd.print((char)223); // Symbol stopnia
  lcd.print("C  ");

  // Linia 2: Status wentylatora
  lcd.setCursor(0, 1);
  if (tempC > 27.0) { 
    lcd.print("FAN: PRACUJE   ");
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, 255); // Pełna moc przy 5V z USB
  } else {
    lcd.print("FAN: STOP      ");
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(enA, 0);
  }

  delay(500); // Odświeżaj co pół sekundy
}