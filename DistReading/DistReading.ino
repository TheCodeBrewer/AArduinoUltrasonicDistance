#include <LiquidCrystal.h>
#include "SR04.h"

// This selects the pins on the Arduino Mega that the ultra-sonic sensor is connected to:
#define TRIG_PIN 2
#define ECHO_PIN 4

// This selects the pins on the Arduino Mega that the lcd is connected to:
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// Don't think this is necessary, but the manual gave a "nickname" to the main HC-SR04 library in lowercase, so I kept it in:
SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);

// This is my own variable to store the distance numbers from the ultra-sonic sensor to display later on the LCD:
long distNum;

void setup() {
  // put your setup code here, to run once:
  // UltraSonic Sensor:  
  Serial.begin(9600);
  delay(1000);

  // LCD Init:
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Calling the distance function from the sensor's library to calculate the distance from the sensor's input and storing it into my distNum variable created earlier:
  distNum = sr04.Distance();

  // LCD Display:
  lcd.setCursor(0, 0);
  lcd.print("Dist         CM ");
  lcd.setCursor(6, 0);
  
  // Displaying the distNum calculation on the display:
  lcd.print(distNum);
  delay(500);
}
