#include <Servo.h>

int ldr1Pin = A0;  
int ldr2Pin = A1;  

Servo servoX; 
Servo servoY; 

int ldr1Value = 0; 
int ldr2Value = 0;  
int threshold =0;

void setup() {
  servoX.attach(9);
  servoY.attach(10);

  servoX.write(90); 
  servoY.write(90);

  Serial.begin(9600); 
}

void loop() {
  ldr1Value = analogRead(ldr1Pin); 
  ldr2Value = analogRead(ldr2Pin); 


  Serial.print("LDR1: ");
  Serial.print(ldr1Value);
  Serial.print(" | LDR2: ");
  Serial.println(ldr2Value);

 
  if (ldr1Value > ldr2Value) {
   
     servoX.write(servoX.read() + 5); 
} else if (ldr1Value < ldr2Value) {
    servoX.write(servoX.read() - 5);
}

 
  if (ldr2Value > ldr1Value + threshold) {
   
    servoX.write(servoX.read() + 5);
  } else if (ldr2Value < ldr1Value - threshold) { 
  
   servoX.write(servoX.read() - 5);
  }

  delay(100);  
}