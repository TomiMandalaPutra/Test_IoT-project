#include "DHT.h"

#define DHTPIN 4 //pin GPIO4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define relay 5 //GPIO5
#define led1 13 //GPIO13
#define led2 14 //GPIO14
#define buzzer 12 //GPI012

void setup()
{
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  dht.begin();
  
  pinMode (relay, OUTPUT);
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (buzzer, OUTPUT);
  digitalWrite(buzzer,LOW);
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  delay(1000);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  delay(1000);

  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(100);
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(100);
}

void loop()
{
  ukur();
  delay(1000);
}

void ukur()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  if (isnan(h) || isnan(t))
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  digitalWrite(led1, HIGH);
  delay(250);
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println(" %");
  digitalWrite(led1, LOW);
  delay(250);
  digitalWrite(led2, HIGH);
  delay(250);
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println("*C");
  digitalWrite(led2, LOW);
  delay(250);

  /*if (t>32 && t<=50)
  {
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    delay(500);
  }
  else 
  {
    digitalWrite(led1, HIGH);
    delay(250);
    digitalWrite(led1, LOW);
    delay(250);
    digitalWrite(led2, HIGH);
    delay(250);
    digitalWrite(led2, LOW);
    delay(250);
  }*/
}
