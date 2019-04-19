//stepper_continous(char M,int dir)
//stepper_degree(char M, int degree,int dir)
//stepper_rev(char M,float rev,int dir)
#include <Servo.h> 
Servo myservo;  // create servo object to control a servo 

void setup()
{
  //horizontal motor
  pinMode(H_stepPin,OUTPUT);
  pinMode(H_dirpin,OUTPUT);
  pinMode(H_enpin,OUTPUT);
  digitalWrite(H_enpin,LOW);
  
  
  //vertical motor
  pinMode(V_stepPin,OUTPUT);
  pinMode(V_dirpin,OUTPUT);
  pinMode(V_enpin,OUTPUT);
  digitalWrite(V_enpin,LOW);
  
  Serial.begin(9600);
   myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop()
{
  
  
  //hor_stepper 3 rev
  //stepper_rev('H',3,0);//forward
  //down to limit of ultrasonic

  //Serial.println(ultrasonic());
    
  while(ultrasonic()> 3)
  {
    stepper_continous('v',0);
    Serial.println("yes");
  }
  //up to certain limit
  while(ultrasonic()<7)
  {
    stepper_continous('v',1);
    Serial.println("No");
  }
  
  /*
  //servo & pump
  myservo.write(160);
  delay(500);
  myservo.write(0);
  //repeat
  
 */

}
