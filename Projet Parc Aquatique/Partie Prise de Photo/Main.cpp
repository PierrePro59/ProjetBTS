#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#define TRIG_PIN 15
#define ECHO_PIN 16
int main() {
 wiringPiSetup();
 pinMode(TRIG_PIN, OUTPUT);
 pinMode(ECHO_PIN, INPUT);
 while (1) {
 digitalWrite(TRIG_PIN, LOW);
 delayMicroseconds(2);
 digitalWrite(TRIG_PIN, HIGH);
 delayMicroseconds(10);
 digitalWrite(TRIG_PIN, LOW);
 while (digitalRead(ECHO_PIN) == LOW);
 long start_time = micros();
 while (digitalRead(ECHO_PIN) == HIGH);
 long end_time = micros();
 long travel_time = end_time - start_time;
 int distance = travel_time / 58;
 printf("Distance: %dcm\n", distance);
 if (distance < 30) {
 char command[] = "gphoto2 --capture-image-and-download --filename
/home/pi/Images/photo.jpg";
 system(command);
 break;
 }
 delay(1000);
 }
 return 0;
}