#include <Arduino.h>

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}

long pulseTime(int echo, int trigger)
{
  pinMode(trigger, OUTPUT);
   digitalWrite(trigger, LOW);
   delayMicroseconds(2);
   digitalWrite(trigger, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigger, LOW);
   pinMode(echo, INPUT);
   return pulseIn(echo, HIGH);
}

long cmFromPulse(int echo, int trigger)
{
    return microsecondsToCentimeters(pulseTime(echo, trigger));
}

