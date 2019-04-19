//TODO stepper 90 degree
//TODO place 
//TODO ultrasonic


// Horizontal_stepper 
#define ppc 1600 //pulses per cycle
#define H_stepPin 7 //pulse pin
#define H_dirpin 8 //rotation direction high or low
#define H_enpin 13 //the enable pin

#define V_stepPin 22 //pulse pin
#define V_dirpin 24 //rotation direction high or low
#define V_enpin 26 //the enable pin

#define ccw 0//
#define cw 1//

int stepPin = 0;
int dirpin = 0;
int enpin = 0;

void choose_motor(char M)
{
    if(M=='H')
  {
    stepPin = H_stepPin;
    dirpin = H_dirpin;
    enpin = H_enpin;
  }
  else
  {
    stepPin = V_stepPin;
    dirpin = V_dirpin;
    enpin = V_enpin;
  }
}
void rotate(char M)
{
    choose_motor(M);
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(500);
    //Serial.println(stepPin);
}

void stepper_degree(char M,int degree,int dir)
{
  /*rotate the stepper by a degree
  degree: degree of rotation
  dir: the direction of rotation(0 or 1)
  */
  //choose the motor
  choose_motor(M);
  //set the direction of rotation
  digitalWrite(dirpin,dir); 
  
  //calculate the number of pulses
  //calculate the no of revlutions by divdide
  //multiply by number of pulses ppc
  float no_of_pulses = ppc*(degree/360.0);
  Serial.println(no_of_pulses);
  for(int i = 0; i < no_of_pulses; i++) 
  {//send the number of pulses to the stepper
   //replace this lines with rotate()functions
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(500);
  }
}

void stepper_rev(char M,float rev,int dir)
{
  /*make the stepper move number of revolutions
  M: the vertical or horizontal motor
  rev: number of revolutions
  dir: the direction of rotation
  */
  //choose the motor
  choose_motor(M);
  digitalWrite(dirpin,dir);//set the direction of rotation
  
  float no_of_pulses = ppc*rev; //calculate the number of pulses
  for(int i = 0; i < no_of_pulses; i++) 
  {
    //send the pulses to the stepper
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(500);
  }
}


void stepper_continous(char M,int dir)
{
  //clockwise or counter clockwise
  //i think this function is not important
  //and not needed can be replaced by one revlution
  choose_motor(M);
  digitalWrite(dirpin, dir);
  rotate(M);
}
