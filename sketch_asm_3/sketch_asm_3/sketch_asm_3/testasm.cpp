#include "testasm.h"

/* the attribute "used" tells the compiler to not inline this function */
__attribute__((used))
unsigned int testasm(unsigned char a) {
  unsigned int out;

  asm volatile (R"(

   rjmp start_of_assembly

   .data
   ; any data values/static storage can go here

   .text

start_of_assembly:
  push r26 ;//registers r26-r29 are used by this program in addition to r24-r25
  push r27 ;//therefore, they are pushed to the stack
  push r28
  push r29
  

  mov r24,%1 ;// moves variable a to register 24
  cp r24,r1 ;// checks if variable a is equal to zero
  breq zero_case ;// if so, go to zero case
  cpi r24,1 ;// checks if variable a is equal to one
  breq one_case ;// if so, go to one case 
  
  
  ldi r25,0 ;//sets register 25 to 0
  ldi r26,0 ;//sets register 26 to 0
  ldi r27,1 ;//sets register 27 to one
  ldi r29,1 ;//sets register 29 to 1 (counter variable)
  
fib:
  
  add r26,r27 ;//adds fib n-1 to fib n-2
  mov r28,r26 ;//copies fib n to register 28
  mov r26,r27 ;//copies fib n-1 to register 26
  mov r27,r28 ;//copies fib n to register 27

  subi r29,-1 ;//adds 1 to counter variable
  cp r29,r24 ;//checks if counter is equal to requested iteration of fib num
  breq end_of_assembly ;//if so, go to end of assembly
  rjmp fib ;//if not, go back to start of fib

zero_case:

  mov r27,r1 ;//sets fib n to 0
  rjmp end_of_assembly ;//go to end of assembly

one_case:
  mov r27, r24 ;//sets fib n to 1
  rjmp end_of_assembly ;//go to end of assembly

  
end_of_assembly: 
  mov r24,r27 ;//copies r27 to r24
  mov r25,r1 ;//sets r25 to 0
  movw %0,r24 ;//r25r24 ->output

  pop r29 ;//registers r29-r26 popped back in in LIFO 
  pop r28
  pop r27
  pop r26



)" : "=w" (out) 
      //out is %0, and a 16-bit variable that is modified by the assembly language
   : "r" (a) 
      //a is %1, register-sized variable
   : "r25", "r24");
      //r24, r25 are modified by this assembly language fragment

  return out;
}
