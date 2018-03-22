/*
  Original color detection code by Rui Santos (http://randomnerdtutorials.com)
  Original servo control code by Scott Fitzgerald
  Adapted by Will Blevins for the cap sorting project @La fabrica del sol
*/

#include <Servo.h>
Servo microServo;  // create servo object to control a servo

//Define variables
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

int servoPosition = 0;    // variable to store the servo servoPositionition

int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;

int redColor = 0;
int greenColor = 0;
int blueColor = 0;

void setup() {
  // Setting the outputs
  microServo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  
  pinMode(sensorOut, INPUT);
  
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);
}

void loop() {
  // Setting RED (R) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  
  // Reading the output frequency
  redFrequency = pulseIn(sensorOut, LOW);
  // Remaping the value of the RED (R) frequency from 0 to 255
  // You must replace with your own values. Here's an example: 
  // redColor = map(redFrequency, 70, 120, 255,0);
  redColor = map(redFrequency, 70, 120, 255,0);
  
  // Printing the RED (R) value
  Serial.print("R = ");
  Serial.print(redColor);
  delay(100);
  
  // Setting GREEN (G) filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  
  // Reading the output frequency
  greenFrequency = pulseIn(sensorOut, LOW);
  // Remaping the value of the GREEN (G) frequency from 0 to 255
  // You must replace with your own values. Here's an example: 
  // greenColor = map(greenFrequency, 100, 199, 255, 0);
  greenColor = map(greenFrequency, 100, 199, 255, 0);
  
  // Printing the GREEN (G) value  
  Serial.print(" G = ");
  Serial.print(greenColor);
  delay(100);
 
  // Setting BLUE (B) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  
  // Reading the output frequency
  blueFrequency = pulseIn(sensorOut, LOW);
  // Remaping the value of the BLUE (B) frequency from 0 to 255
  // You must replace with your own values. Here's an example: 
  // blueColor = map(blueFrequency, 38, 84, 255, 0);
  blueColor = map(blueFrequency, 38, 84, 255, 0);
  
  // Printing the BLUE (B) value 
  Serial.print(" B = ");
  Serial.print(blueColor);
  delay(100);

  // Checks the current detected color and prints
  // a message in the serial monitor
  if(redColor > greenColor && redColor > blueColor){
      Serial.println(" - RED detected!");
      servoMove(120);       // angle lever to place red cap in correct place
  }
  if(greenColor > redColor && greenColor > blueColor){
    Serial.println(" - GREEN detected!");
       servoMove(15);       // angle lever to place red cap in correct place

  }
  if(blueColor > redColor && blueColor > greenColor){
    Serial.println(" - BLUE detected!");
    servoMove(-90);       // angle lever to place red cap in correct place

  }
}


void servoMove(int angle){
  int pos=0;
  if (angle>0){                                 // if we need to turn clockwise
    for (pos = 0; pos <= angle; pos += 1) { 
      // in steps of 1 degree
      microServo.write(pos);             
      delay(15);                     
    }
    for (pos = angle; pos >= 0; pos -= 1) { 
      microServo.write(pos);              
      delay(15);                   
    }
  } else {                                      // if we need to turn counter-clockwise 
      for (pos = 0; pos >= angle; pos -= 1) {   
      // in steps of 1 degree
      microServo.write(pos);            
      delay(15);                     
    }
    for (pos = angle; pos <= 0; pos += 1) { 
      microServo.write(pos);              
      delay(15);                      
    }
  }
}
    

