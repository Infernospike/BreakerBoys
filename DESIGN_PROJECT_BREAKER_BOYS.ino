/* Servo motor with Arduino example code. Position and sweep. More info: https://www.makerguides.com/ */

// Include the servo library:
#include <Servo.h>

// Create a new servo object:
Servo myservo;
int val1 = 0;
int val2 = 0;
int rest = 90;






#define INPUT1 2
#define INPUT2 3
#define servoPin 9



void setup() {
  // Attach the Servo variable to a pin:
  myservo.attach(servoPin);
  pinMode(INPUT1, INPUT);
  pinMode(INPUT2, INPUT);
  Serial.begin(9600);
  
}
void OFF(){
  
  int angle_180 = 145;
  
  for(int i = 90; i < angle_180; i++){
    myservo.write(i);
    delay(5);
  }
  myservo.write(rest);
}

void ON(){
  int angle_0 = 35;
 

 for(int i = 90; i > angle_0; i--){
    myservo.write(i);
    delay(3);
 }
 myservo.write(90);
}

void loop(){
  
  val1 = digitalRead(INPUT1);

  val2 = digitalRead(INPUT2);

  
  if((val1 == 1)&&(val2 == 0)){
    OFF();
    val1 = 0;
    val2 = 0;
    }
  if((val1 == 0)&&(val2 == 1)){
    ON();
    val1 = 0;
    val2 = 0;
  }
  else{
    myservo.write(rest);
  }
}

  
  


  
  



 
  
  
  

  
