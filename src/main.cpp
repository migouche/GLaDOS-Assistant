#include <Arduino.h>
#include "IK.h"
#include "ultrasound.h"
#include "serialutils.h"
#include "servoutils.h"

#define Servo_PWM 6 // A descriptive name for D6 pin of Arduino to provide PWM signal
//Servo MG995_Servo;  // Define an instance of of Servo with the name of "MG995_Servo"


int i = 0;

void setup() {
  Serial.begin(9600); // Initialize UART with 9600 Baud rate
  /*MG995_Servo.attach(Servo_PWM);  // Connect D6 of Arduino with PWM signal pin of servo motor
  MG995_Servo.write(0);
  delay(5000);
  MG995_Servo.write(30);*/
}

void loop() {/*
  Serial.println("0");// You can display on the serial the signal value
  MG995_Servo.write(0); //Turn clockwise at high speed
  delay(3000);
  MG995_Servo.detach();//Stop. You can use deatch function or use write(x), as x is the middle of 0-180 which is 90, but some lack of precision may change this value
  delay(2000);
  MG995_Servo.attach(Servo_PWM);//Always use attach function after detach to re-connect your servo with the board
  Serial.println("0");//Turn left high speed
  MG995_Servo.write(180);
  delay(3000);
  MG995_Servo.detach();//Stop
  delay(2000);
  MG995_Servo.attach(Servo_PWM);*/


  i = (i + 1) % 10;
  //Serial.println(i);
  //  Serial.write(i);
  //Serial.write("u 255:0, 235:72, :144, :216, :288");
  Serial.write("u 255:0, 235:72, 30:144, 200:216, 231:288\n");
  
 
  delay(200);
      
}