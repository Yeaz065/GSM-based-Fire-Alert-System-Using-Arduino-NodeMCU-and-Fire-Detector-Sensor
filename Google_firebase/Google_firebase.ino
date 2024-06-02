#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>

#include <ESP8266WiFi.h>                 
     
#include "DHT.h"              
 
#define FIREBASE_HOST "https://eee-310-project-default-rtdb.firebaseio.com"      
#define FIREBASE_AUTH "a3JeKYIIxQlRJgBbpRUkbarAHHreMn64hmEXoQSL"            
#define WIFI_SSID "SWH 5011"                                  
#define WIFI_PASSWORD "SWH5011@4"            
 
#define DHTPIN D3                                            // Digital pin connected to DHT22
#define DHTTYPE DHT22                                        // Initialize dht type as DHT 22
DHT dht(DHTPIN, DHTTYPE);                                                    
 
void setup() 
{
  Serial.begin(115200);
  dht.begin();                                                  //reads dht sensor data 
               
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                  
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
 
  Serial.println();
  Serial.print("Connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());                               //prints local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);                 // connect to the firebase
 
}
 
void loop() 
{
  float h = dht.readHumidity();                                 // Read Humidity
  float t = dht.readTemperature();                              // Read temperature
  
  if (isnan(h) || isnan(t))                                     // Checking sensor working
  {                                   
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  } 
  Serial.print("Humidity: ");  
  Serial.print(h);
  String fireHumid = String(h) + String("%");                   //Humidity integer to string conversion
  
  Serial.print("%  Temperature: ");  
  Serial.print(t);  
  Serial.println("°C ");
  String fireTemp = String(t) + String("°C");                  //Temperature integer to string conversion
  delay(5000);
 
 
  Firebase.pushString("/DHT22/Humidity", fireHumid);            //setup path to send Humidity readings
  Firebase.pushString("/DHT22/Temperature", fireTemp);         //setup path to send Temperature readings
    if (Firebase.failed()) 
    {
 
      Serial.print("pushing /logs failed:");
      Serial.println(Firebase.error()); 
      return;
  }
}
