#include <Wire.h>               
#include "SSD1306Wire.h"

#define IN_R 13
#define IN_L 14
#define IN_RD 12  //HIGH 후진, LOW 전진 
#define IN_LD 15  //HIGH 전진, LOW 후진

SSD1306Wire display(0x3c, 0, 2, GEOMETRY_128_32);
int TIME_INTERVAL = 2000;

void setup() {
  display.init();

  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_LEFT);

  //모터 회전수
  pinMode(IN_R,OUTPUT);
  pinMode(IN_L,OUTPUT);

  //모터 회전방향
  pinMode(IN_RD,OUTPUT);
  pinMode(IN_LD,OUTPUT);
}



void loop() {
   int speed = 255;
    
  
    if (speed >= 0 && speed <= 255)  { 
     
      // car_FL(speed);
      // delay(TIME_INTERVAL*2);

      // car_BL(speed);
      // delay(TIME_INTERVAL*2);

      // car_FR(speed);
      // delay(TIME_INTERVAL*2);

      // car_BR(speed);
      // delay(TIME_INTERVAL*2);

      // car_BL(speed);
      // delay(TIME_INTERVAL*2);

      // car_FL(speed);
      // delay(TIME_INTERVAL*2);
      
      // car_BR(speed);
      // delay(TIME_INTERVAL*2);

      // car_FR(speed);
      // delay(TIME_INTERVAL*2);

      // car_FW(speed);
      // delay(TIME_INTERVAL);

      Turn_Right(speed);
      delay(TIME_INTERVAL / 4);

      car_FR(speed);
      delay(TIME_INTERVAL*8);

      
      car_stop();
    }
 
  
}

void car_stop() {
  // 모든 모터를 정지
  analogWrite(IN_L, 0);
  analogWrite(IN_R, 0);
}

void Turn_Right(int speed){
  //왼쪽모터
  digitalWrite(IN_LD,LOW);
  analogWrite(IN_L,speed);

   //오른쪽모터
  digitalWrite(IN_RD,LOW);
  analogWrite(IN_R,speed);
}

void oLED_print(String msg){
  display.clear();
  display.drawString(0, 10, msg);
  display.display();
}

void car_FW(int speed){ 
  analogWrite(IN_L,0);
  analogWrite(IN_R,0);

  oLED_print("forward : "+String(speed));

  //왼쪽모터
  digitalWrite(IN_LD,HIGH);
  analogWrite(IN_L,speed);

   //오른쪽모터
  digitalWrite(IN_RD,LOW);
  analogWrite(IN_R,speed);
}

void car_BW(int speed){ 
  analogWrite(IN_L,0);
  analogWrite(IN_R,0);

  oLED_print("backward : "+String(speed));
  //왼쪽모터
  digitalWrite(IN_LD,LOW);
  analogWrite(IN_L,speed);

   //오른쪽모터
  digitalWrite(IN_RD,HIGH);
  analogWrite(IN_R,speed);
}


void car_FL(int speed){ 
  analogWrite(IN_L,0);
  analogWrite(IN_R,0);
  
  oLED_print("forward left : "+String(speed));

  //왼쪽모터
  digitalWrite(IN_LD,HIGH);
  analogWrite(IN_L,speed/4);

   //오른쪽모터
  digitalWrite(IN_RD,LOW);
  analogWrite(IN_R,speed);
}

void car_FR(int speed){ 
  analogWrite(IN_L,0);
  analogWrite(IN_R,0);

  oLED_print("forward right: "+String(speed));

  //왼쪽모터
  digitalWrite(IN_LD,HIGH);
  analogWrite(IN_L,speed);

   //오른쪽모터
  digitalWrite(IN_RD,LOW);
  analogWrite(IN_R,speed/4);
}

void car_BR(int speed){ 
   oLED_print("backward right: "+String(speed));
  //왼쪽모터
  digitalWrite(IN_LD,LOW);
  analogWrite(IN_L,speed);

   //오른쪽모터
  digitalWrite(IN_RD,HIGH);
  analogWrite(IN_R,speed/4);
}

void car_BL(int speed){ 
   oLED_print("backword left : "+String(speed));

  //왼쪽모터
  digitalWrite(IN_LD,LOW);
  analogWrite(IN_L,speed/4);

   //오른쪽모터
  digitalWrite(IN_RD,HIGH);
  analogWrite(IN_R,speed);
}