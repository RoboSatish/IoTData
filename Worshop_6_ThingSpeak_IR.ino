
#include <WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>

#include "DHT.h"

#define DHTPIN 18     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);
int Gas_analog = 4;
int IR = 2;

const char* ssid = "satish"; //Your Network SSID
const char* password = "satish123"; //Your Network Password
WiFiClient client;
unsigned long myChannelNumber =2024742; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "S796FK9ZSQ8MUOLR"; //Your Write API Key
void setup()

{
Serial.begin(115200);
delay(10);
pinMode(Gas_analog,INPUT);
pinMode(IR,INPUT);
WiFi.begin(ssid, password);
ThingSpeak.begin(client);
 dht.begin();


}
void loop()
{

  int g = digitalRead(Gas_analog);
  Serial.println(g);
   int g1 = digitalRead(IR);
  Serial.println(g1);




   float h = dht.readHumidity();
  
  float t = dht.readTemperature();

  float f = dht.readTemperature(true);

 
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

 
 

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
 // Serial.print(f);
  //Serial.print(F("°C "));
 
 // Serial.println(F("°F"));
 // delay(100);
   ThingSpeak.writeField(myChannelNumber, 1,h, myWriteAPIKey); //Humidity
    
    ThingSpeak.writeField(myChannelNumber, 2,g1, myWriteAPIKey); //IR
   
   ThingSpeak.writeField(myChannelNumber, 3,g, myWriteAPIKey); //LDR
   ThingSpeak.writeField(myChannelNumber, 4,t, myWriteAPIKey); //Temp
   
   
 
}

 
