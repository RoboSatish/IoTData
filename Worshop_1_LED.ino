#define LDR 19
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LDR,INPUT);
  pinMode(18,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int s1= digitalRead(LDR);
  Serial.println(s1);
  
  /*digitalWrite(18,HIGH);
  delay(1000);
  digitalWrite(18,LOW);
  delay(1000);
*/
}
