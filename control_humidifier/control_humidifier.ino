#include <DHT_U.h>
#include <DHT.h>

#define DHT11_TYPE DHT11
#define DHT11_PIN 5

#define RELAY 2


DHT dht(DHT11_PIN, DHT11_TYPE);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  pinMode(RELAY, OUTPUT);
}

void loop() {
    delay(1000);
  // put your main code here, to run repeatedly:

  float h = dht.readHumidity();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  
  Serial.print("Humidity = ");
  Serial.print(h);
  Serial.println(" %");

  if ((h < 85) | (h > 90)) {
      digitalWrite(RELAY, HIGH);
  } else {
      digitalWrite(RELAY, LOW);  
  }
}
