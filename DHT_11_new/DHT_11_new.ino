#include <SoftwareSerial.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>

 
DHT dht(9, DHT22);

void setup(){
  
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
  dht.begin();
 
}//end "setup()"
 
void loop(){
  //Start of Program 
 
    // DHT.read11(dht_apin);
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    //Serial.print("Current humidity = ");
    Serial.println(h);
    //Serial.print(" %");
    //Serial.println("temperature = ");
    Serial.println(t); 
    //Serial.print(" C");
    
    delay(4000);//Wait 5 seconds before accessing sensor again.
 
  //Fastest should be once every two seconds.
 
}// end loop()
