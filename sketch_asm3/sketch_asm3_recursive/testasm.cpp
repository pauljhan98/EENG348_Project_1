#include "testasm.h"

/* the attribute "used" tells the compiler to not inline this function */
__attribute__((used))
unsigned int testasm(unsigned char a, unsigned char b) {
  unsigned int out;

  asm volatile (R"(

   rjmp start_of_assembly

   .data
   ; any data values/static storage can go here

   .text

start_of_assembly:
   ; Your assembly language program goes here
   ;
   ; For this example, your program must not modify any registers other than 
   ; r24 and r25. In other words, save and restore all the registers that
   ; are modified by your code.

   ; Tell the compiler to move the arguments a, b into registers 
   ; r24, r25 respectively
   ;
   mov r24,%1
   ;mov r25,%2
   ;
   ;  --- YOUR CODE GOES HERE ---
   ;       r24 = a, r25 = b
   ;


  ; input value stored in r24; output value stored in r24

  push r20
  ldi r20, 1  ; r20 holds the value 1 for the equality test later
  mov r25, r1 ; probably not needed, but makes sure r25 holds the value 0
  push r21    ; holds value from recursive call


 
  call fib

  pop r21    ; restore registers
  pop r20

  rjmp end_of_assembly





  ; Essentially, what is happening in this function is:
  ; Recurse to a leaf (i.e, 1 or 0)
  ; Return that value, and add it to other returned leaves, ect. 


fib:
  cp r24, r1  
  brne test_2 ; If n != 0, go to second test
  ret         ; Else, return with value 0 in r24

test_2:
  cp r24, r20
  brne recursion  ; If n != 1, n > 1, so need to continue recursion until we get 1 or 0
  ret             ; Else, return with value 1 in r24


recursion:

  push r24        ; Save input value on stack b/c we also use this as our return; It may get modified somewhere in the recursion
  subi r24,1      ; Use r24 as our parameter and do this: fib(n-1)

  call fib

  mov r21, r24    ; r24 constains return value, save it in r21
  pop r24         ; Restore original r24 value
  push r21        ; Save on stack b/c it may get modified somewhere in the recursion
  subi r24, 2     ; Use r24 as our parameter and do this: fib(n-2) 
  call fib

  pop r21         ; Restore return from fib(n-1) and add it to fib(n-2)
  add r24, r21


  ret             ; return
  



   ;
   ;  --- YOUR CODE ENDS ---
   ;      The result must be in the register pair r25:r24
   ;      You can also rjmp to the label end_of_assembly if you need to.
   ;
end_of_assembly: 
   ; -- move r25:r24 to the 16-bit word in variable out
   movw %0,r24

)" : "=w" (out)  /* out is %0, and a 16-bit variable that is modified
		    by the assembly language */
   : "r" (a), "r" (b)  /* a is %1, b is %2, both are register-sized
			  variables */
   : "r25", "r24");   /* r24, r25 are modified by this assembly
			 language fragment */

  return out;
}
