/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.13 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.13.13 or later version;
     - for iOS 1.10.3 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// you can enable debug logging to Serial at 115200
//#define REMOTEXY__DEBUGLOG    

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__WIFI_POINT

#include <ESP8266WiFi.h>

// RemoteXY connection settings 
#define REMOTEXY_WIFI_SSID "RemoteXY"
#define REMOTEXY_WIFI_PASSWORD "12345678"
#define REMOTEXY_SERVER_PORT 6377


#include <RemoteXY.h>

// RemoteXY GUI configuration  
#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =   // 63 bytes
  { 255,5,0,0,0,56,0,17,0,0,0,31,1,106,200,1,1,5,0,1,
  43,57,24,24,0,2,31,0,1,21,81,24,24,0,2,31,0,1,64,81,
  24,24,0,2,31,0,1,43,105,24,24,0,2,31,0,4,79,134,15,53,
  0,2,26 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t up; // =1 if button pressed, else =0
  uint8_t left; // =1 if button pressed, else =0
  uint8_t right; // =1 if button pressed, else =0
  uint8_t down; // =1 if button pressed, else =0
  int8_t speed_slider; // from 0 to 100

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;   
#pragma pack(pop)

 
/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////


const int IN1 = D0;
const int IN2 = D1;
const int IN3 = D2;
const int IN4 = D3;
const int ENA = D5;
const int ENB = D6;

int speed = 255;

void setup() 
{
  RemoteXY_Init (); 
  
  
  // TODO you setup code
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

}

void loop() 
{ 
  RemoteXY_Handler ();
  
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay(), use instead RemoteXY_delay() 
  int8_t isForward = RemoteXY.up;
  int8_t isBackward = RemoteXY.down;
  int8_t isLeft = RemoteXY.left;
  int8_t isRight = RemoteXY.right;


  speed = RemoteXY.speed_slider * 2.55;

  if(isForward==1){
    moveForward();
  }
  else if(isBackward==1){
    moveBackward();
  }
  else if(isLeft==1){
    turnLeft();
  }
  else if(isRight==1){
    turnRight();
  }
  else if (isForward == 0 && isBackward == 0 && isLeft == 0 && isRight == 0){
    stopMotors();
  }


}

void stopMotors(){
  // motor 1 stop
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  // motor 2 stop
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
}

void startMotors(){
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void moveForward(){
  // motor 1 forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  // motor 2 forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void moveBackward(){
  // motor 1 forward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  // motor 2 forward
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  // change speed
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void turnLeft(){
  // motor 1 forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  // motor 2 forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  // change speed
  analogWrite(ENA, speed-(speed/1.5));
  analogWrite(ENB, speed);
}

void turnRight(){
  // motor 1 forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  // motor 2 forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  // change speed
  analogWrite(ENA, speed);
  analogWrite(ENB, speed-(speed/1.5));
}