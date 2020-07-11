/* https://github.com/conehitech/pengukur-suhu-dan-kelembapan.git
 *
 * Program untuk alat pengukur suhu dan kelembapan
 * oleh: Nurzaman, Hilman x C1 - HiTech R & D
 *
 * Dependencies:
 *   LiquidCrystal_I2C,
 *   DHT
 */

#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// LiquidCrystal_I2C nama_object(0x3F atau 0x27, banyak kolom, banyak baris)
LiquidCrystal_I2C lcd(0x3F,16,2);

// DHT nama_object(pin, jenis DHT)
DHT dht(2, DHT11);

int powerPin = 3;

void setup(){
  lcd.init();
  lcd.backlight();

  pinMode(powerPin, OUTPUT);
  digitalWrite(powerPin, LOW);

  Serial.begin(9600);
  dht.begin();
}

void loop(){
  digitalWrite(powerPin, HIGH);

  float kelembaban = dht.readHumidity();
  float suhu = dht.readTemperature();

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Kelembaban: ");
  lcd.setCursor(11,0);
  lcd.print(kelembaban);

  lcd.setCursor(0,1);
  lcd.print("Suhu: ");
  lcd.setCursor(5,1);
  lcd.print(suhu);
  delay(1000);
}
