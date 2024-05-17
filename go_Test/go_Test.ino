#define IN_R 13
#define IN_L 14
#define IN_RD 12
#define IN_LD 15

void setup() {
  Serial.begin(9600);

  pinMode(IN_R, OUTPUT);
  pinMode(IN_L, OUTPUT);
  pinMode(IN_RD, OUTPUT);
  pinMode(IN_LD, OUTPUT);
}

int speed = 255; 
bool sequenceCompleted = false;
void loop() {
  if (!sequenceCompleted) {
    Serial.print("Go: ");
    Serial.println(speed);
    car_go(speed); 
    delay(3000);

    car_go(speed); 
    delay(3000);

    Serial.print("Left: ");
    Serial.println(speed);
    car_left(speed); 
    delay(3000);

    Serial.print("Back Left: ");
    Serial.println(speed);
    car_back_left(speed); 
    delay(3000);

    Serial.print("Right: ");
    Serial.println(speed);
    car_right(speed);
    delay(3000);

    Serial.print("Right: ");
    Serial.println(speed);
    car_back_right(speed); 
    delay(3000);

    Serial.print("Back: ");
    Serial.println(speed);
    car_back(speed);
    delay(3000);

    car_back(speed);
    delay(3000);

    Serial.println("Stop");
    car_stop(); // 정지

    sequenceCompleted = true;
  }
}

void car_go(int speed) {
  digitalWrite(IN_LD, HIGH);
  analogWrite(IN_L, speed);
  digitalWrite(IN_RD, LOW);
  analogWrite(IN_R, speed);
}

void car_back(int speed) {
  digitalWrite(IN_LD, LOW);
  analogWrite(IN_L, speed);
  digitalWrite(IN_RD, HIGH);
  analogWrite(IN_R, speed);
}

void car_left(int speed) {
  digitalWrite(IN_LD, HIGH);
  analogWrite(IN_L, speed / 4);
  digitalWrite(IN_RD, LOW);
  analogWrite(IN_R, speed);
}

void car_back_left(int speed){
  digitalWrite(IN_LD, LOW);
  analogWrite(IN_L, speed / 4);
  digitalWrite(IN_RD, HIGH);
  analogWrite(IN_R, speed);
}

void car_right(int speed) {
  digitalWrite(IN_LD, HIGH);
  analogWrite(IN_L, speed);
  digitalWrite(IN_RD, LOW);
  analogWrite(IN_R, speed / 4);
}
void car_back_right(int speed) {
  digitalWrite(IN_LD, LOW);
  analogWrite(IN_L, speed);
  digitalWrite(IN_RD, HIGH);
  analogWrite(IN_R, speed / 4);
}
void car_stop() {
  analogWrite(IN_L, 0);
  analogWrite(IN_R, 0);
}
