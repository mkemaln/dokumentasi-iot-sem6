#include <Arduino.h>
#include <DHT.h>

#define DHTPIN 4        
#define DHTTYPE DHT11

#define LDR_PIN 5

DHT dht(DHTPIN, DHTTYPE); 

void setup() {
    Serial.begin(9600);  
    dht.begin();           
    Serial.println("ESP32-S2 Siap, Membaca Sensor DHT11...");
  
    // konfigurasi sensor LDR
    pinMode(LDR_PIN, INPUT);
}

void loop() {
    float suhu = dht.readTemperature();    // Membaca suhu dalam Celcius
    float kelembaban = dht.readHumidity(); // Membaca kelembaban dalam persen
    
    // Cek apakah pembacaan valid
    if (isnan(suhu) || isnan(kelembaban)) {
        Serial.println("Gagal membaca dari sensor DHT11!");
        return;
    }

    // Menampilkan data ke Serial Monitor
    Serial.print("Suhu: ");
    Serial.print(suhu);
    Serial.print("°C  |  Kelembaban: ");
    Serial.print(kelembaban);
    Serial.println("%");
  
    if (digitalRead(LDR_PIN) == LOW) { // membaca tingkat cahaya dalam satuan lux
    Serial.println("Light!");
  } else {
    Serial.println("Dark  ");
  }

    delay(2000); // Delay 2 detik sebelum membaca ulang
}
