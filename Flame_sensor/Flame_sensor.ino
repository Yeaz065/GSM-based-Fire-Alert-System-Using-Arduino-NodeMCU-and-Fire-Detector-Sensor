#define FLAME 7
#define BUZZER 12 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Fire Module Test");
  pinMode(FLAME, INPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int fire = digitalRead(FLAME);
  if(fire == HIGH)
  {
    digitalWrite(BUZZER, HIGH);
    Serial.println("Fire! Fire!");
  }
  else
  {
    digitalWrite(BUZZER, LOW);
    Serial.println("Peace");
  }
  delay(2000);
}
