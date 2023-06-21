
#include <Servo.h>
 
//Création des objets servo
Servo servo_zero;
bool ok=false;
int i=0;

void setup() 
 {

 }
 
void loop() 
{
  if (ok==false)
  {
     for (i=2;i<14;i++)
      {
      servo_zero.attach(i);
      servo_zero.write(60);
      delay(1000);
      servo_zero.write(120);
      delay(1000);
      servo_zero.write(90);
      delay(1000);
      servo_zero.detach();
      }
    ok=true;
   }
 }


