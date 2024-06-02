#include<Wire.h>
#define buzzer 12
int gas;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  gas = analogRead(A0);
  if(gas>300){
    digitalWrite(buzzer, HIGH);
    Serial.println("GAS LEAKAGE!!!");
  }
  else{
    digitalWrite(buzzer, LOW);
  }
  Serial.println(gas);
  delay(500);
}
