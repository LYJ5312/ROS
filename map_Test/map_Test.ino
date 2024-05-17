#define IN_R 13
#define IN_L 14
#define IN_RD 12
#define IN_LD 15

void setup(){
  Serial.begin(9600);

  pinMode(IN_R,OUTPUT);
  pinMode(IN_L,OUTPUT);

  pinMode(IN_R,OUTPUT);
  pinMode(IN_L,OUTPUT);
}
void loop(){
  Serial.println("go");

  digitalWrite(IN_RD,LOW);
  analogWrite(IN_R,255);

  digitalWrite(IN_LD,HIGH);
  analogWrite(IN_L,255);
  delay(2000);
}