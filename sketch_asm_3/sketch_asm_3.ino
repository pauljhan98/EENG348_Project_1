#include "testasm.h"

void setup() {
  // put your setup code here, to run once
  Serial.begin(9600);
  Serial.print("The 13th fibonacci number is: ");
  Serial.println(testasm(13));
  Serial.print("The 0th fibonacci number is: ");
  Serial.println(testasm(0));
  Serial.print("The 1st fibonacci number is: ");
  Serial.println(testasm(1));
  Serial.print("The 2nd fibonacci number is: ");
  Serial.println(testasm(2));
  Serial.print("The 3rd fibonacci number is: ");
  Serial.println(testasm(3));
  
  pinMode (13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite (13, HIGH);
  delay(400);
  digitalWrite (13, LOW);
  delay(400);
}
