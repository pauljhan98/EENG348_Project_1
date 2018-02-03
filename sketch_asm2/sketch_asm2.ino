#include "testasm.h"

void setup() {
  // put your setup code here, to run once
  Serial.begin(9600);

  // The operation sumval() + diffval() returns
  // 2*(the largest of the two numbers)
  // Of course, this is not how this was implemented
  // In the assembly, but it makes it much easier to
  // check if the function output is correct


  // Test Cases  
  Serial.print("Input: a = 11, b = 8 \n Expected Output: 22 \n Output: sumval() + diffval() is: ");
  Serial.println(testasm(11, 8));
  Serial.print("\n");

  Serial.print("Input: a = 255, b = 4 \n Expected Output: 510 \n Output: sumval() + diffval() is: ");
  Serial.println(testasm(255, 4));
  Serial.print("\n");
  
  Serial.print("Input: a = 8, b = 11 \n Expected Output: 22 \n Output: sumval() + diffval() is: ");
  Serial.println(testasm(8, 11));
  Serial.print("\n");

  Serial.print("Input: a = 134, b = 176 \n Expected Output: 352 \n Output: sumval() + diffval() is: ");
  Serial.println(testasm(134, 176));
  Serial.print("\n");
   
  Serial.print("Input: a = 11, b = 11 \n Expected Output: 22 \n Output: sumval() + diffval() is: ");
  Serial.println(testasm(11, 11));
  Serial.print("\n");

  Serial.print("Input: a = 255, b = 1 \n Expected Output: 510 \n Output: sumval() + diffval() is: ");
  Serial.println(testasm(255, 1));
  Serial.print("\n");

  Serial.print("Input: a = 255, b = 0 \n Expected Output: 510 \n Output: sumval() + diffval() is: ");
  Serial.println(testasm(255, 0));
  Serial.print("\n");

  Serial.print("Input: a = 0, b = 255 \n Expected Output: 510 \n Output: sumval() + diffval() is: ");
  Serial.println(testasm(0, 255));
  Serial.print("\n");


  Serial.print("Input: a = 233, b = 27 \n Expected Output: 466 \n Output: sumval() + diffval() is: ");
  Serial.println(testasm(233, 27));
  Serial.print("\n");

  Serial.print("Input: a = 0, b = 0 \n Expected Output: 0 \n Output: sumval() + diffval() is: ");
  Serial.println(testasm(0, 0));
  Serial.print("\n");

  
  pinMode (13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite (13, HIGH);
  delay(400);
  digitalWrite (13, LOW);
  delay(400);
}
