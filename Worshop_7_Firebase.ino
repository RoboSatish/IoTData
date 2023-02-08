#include <WiFi.h>
#include <FirebaseESP32.h>
#include "DHT.h"

#define DHTPIN 18     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

#define FIREBASE_HOST "worshopmgmcsit-default-rtdb.europe-west1.firebasedatabase.app/"
#define WIFI_SSID "satish" 
#define WIFI_PASSWORD "satish123" 
#define FIREBASE_Authorization_key "2OuQCrbjvl11cfstfGSTvb71sJIqYHxvTd6HJ9L3"


int Gas_analog = 4;
int IR = 2;


 int ira,irb,irc,ldr,butt;
 int ira1,irb1,irc1;
float voltage;
FirebaseData firebaseData;
FirebaseJson json;

void setup() {

  Serial.begin(115200);
  pinMode(Gas_analog,INPUT);
pinMode(IR,INPUT);
dht.begin();

  
  WiFi.begin (WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting...");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  Firebase.begin(FIREBASE_HOST, FIREBASE_Authorization_key);

}


void loop() {
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



  

   Firebase.setFloat(firebaseData, "IR1", g);
  Firebase.setFloat(firebaseData, "LDR", g1);
  Firebase.setFloat(firebaseData, "Hum", h);
  Firebase.setFloat(firebaseData, "Temp", t);
  delay(200);
}
