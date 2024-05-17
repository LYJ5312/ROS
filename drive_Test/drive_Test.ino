#include <WiFi.h>
#include <Wire.h>

#include "EEPROM.h"
#include "SSD1306Wire.h"        // legacy: #include "SSD1306.h"

#define SSID_EEP_ADDR 0
#define WiFi_NAME "car000006"
#define PASSWORD "123456789"

SSD1306Wire display(0x3c, 0, 2, GEOMETRY_128_32);

void setup() {
  delay(3000);

  EEPROM.begin(10);
  String read_eep_ssid = EEPROM.readString(SSID_EEP_ADDR);
  
  if(read_eep_ssid != WiFi_NAME){ 
    EEPROM.writeString(SSID_EEP_ADDR, WiFi_NAME);
    EEPROM.commit();
  }

  //OLED 초기화
  display.init();

  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_16);
  display.setTextAlignment(TEXT_ALIGN_LEFT);

  //OLED 표시
  // read_eep_ssid = EEPROM.readString(SSID_EEP_ADDR);
  // display.clear();
  // display.drawString(0,0,read_eep_ssid);
  // display.display();

  //wifi 연결
  read_eep_ssid = EEPROM.readString(SSID_EEP_ADDR);
  const char*ssid = read_eep_ssid.c_str();
  WiFi.begin(ssid,PASSWORD);

  int wifi_status = 0;
  while (WiFi.status() != WL_CONNECTED){
    delay(500);

    display.clear();
    display.drawString(0,0,"waiting connection....");
    display.display();
  }
  //연결 성공
  display.clear();
  display.drawString(0,0,"connected");
  display.display();

  if(wifi_status == 0){
  display.clear();
  display.drawString(0,0,"SsID:");
  display.drawString(40,0,ssid);
  display.drawString(0,16,"PASS:");
  display.drawString(45,16,PASSWORD);
  display.display();
  }
  else{
    display.clear();
    display.drawString(0,0,"SsID:");
    display.drawString(40,0,ssid);
    display.drawString(120,0,".");
    display.drawString(0,16,"PASS:");
    display.drawString(45,16,PASSWORD);
    display.display();
  }

  display.clear();
  display.drawString(20, 0, "IP address:");
  display.drawString(0, 16, ip2Str(WiFi.localIP()));
  display.display();
}

void loop() {
  String read_eep_ssid = EEPROM.readString(SSID_EEP_ADDR);
 
  delay(5000);
}