#include <Servo.h>

#define ALPHA 9

#define BETA 10

Servo alphaServo;
Servo betaServo;

void attachServos()
{
    alphaServo.attach(ALPHA);
    betaServo.attach(BETA);
}

void servoWrite()
{
    
}