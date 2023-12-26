#include <Servo.h> 
Servo horizontalServo;

int servoh = 90;
int servohLimitHigh = 180;
int servohLimitLow = 0;
int tolerance = 10;

void setup(){
Serial.begin(9600);
horizontalServo.attach(7);
horizontalServo.write(180);
delay(3000);
}

void loop() 
{
  int ldrLeft = analogRead(A4);
  int ldrRight = analogRead(A0);
  int diffHorizontal = ldrLeft - ldrRight;// check the diffirence of left and right
  
  if ( diffHorizontal <-1*tolerance || diffHorizontal > tolerance){ //check if the difference is tolerable else rotate the motor
    if (ldrLeft > ldrRight){
      servoh = servoh+2;
      if (servoh > servohLimitHigh){servoh = servohLimitHigh;}
    } else if (ldrLeft < ldrRight){
      servoh = servoh-2;
      if (servoh < servohLimitLow){servoh = servohLimitLow;}
    } else if (ldrLeft = ldrRight){
    // nothing
    }
  }
    horizontalServo.write(servoh);
  delay(10);
}
