#include "testasm.h"

void setup() {
  // put your setup code here, to run once
  Serial.begin(9600);
  Serial.print("FIB 0 is:");
  Serial.println(testasm(0, 0));
  Serial.print("FIB 1 is:");
  Serial.println(testasm(1, 0));
  Serial.print("FIB 2 is:");
  Serial.println(testasm(2, 0));
  Serial.print("FIB 3 is:");
  Serial.println(testasm(3, 0));
  Serial.print("FIB 4 is:");
  Serial.println(testasm(4, 0));
  Serial.print("FIB 5 is:");
  Serial.println(testasm(5, 0));
  Serial.print("FIB 6 is:");
  Serial.println(testasm(6, 0));
  Serial.print("FIB 7 is:");
  Serial.println(testasm(7, 0));
  Serial.print("FIB 8 is:");
  Serial.println(testasm(8, 0));
  Serial.print("FIB 9 is:");
  Serial.println(testasm(9, 0));
  Serial.print("FIB 10 is:");
  Serial.println(testasm(10, 0));
  Serial.print("FIB 11 is:");
  Serial.println(testasm(11, 0));
  Serial.print("FIB 12 is:");
  Serial.println(testasm(12, 0));
  Serial.print("FIB 13 is:");
  Serial.println(testasm(13, 0));
  
  
  pinMode (13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite (13, HIGH);
  delay(400);
  digitalWrite (13, LOW);
  delay(400);
}
