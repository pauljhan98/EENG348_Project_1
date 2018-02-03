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
   mov r25,%2
   ;
   ;  --- YOUR CODE GOES HERE ---
   ;       r24 = a, r25 = b
   ;

push r16  ; We choose to follow the caller convention in this code
push r17  ; r16 and r17 are saved to the stack

call sumval
call diffval

add r24, r16 ; This preforms sumval() + diffval()
mov r25, r17 ; If there is a carry from sumval, include it here
adc r25, r1  ; If there is a carry from sumval() + diffval(), include it here

pop r17   ; Restore r17 to its original value before the function calls
pop r16   ; Restore r16 to its original value before the function calls

rjmp end_of_assembly



sumval: mov r16, r24
        mov r17, r25
        add r16, r17 ;adds register 17 to register 16 and saved it to r16. May or may not flag carry bit
        mov r17, r1  ;sets r17 to 0
        adc r17, r1  ; if carry flag is set, adds 1 to the operation of adding 0 to r17, if not, simply adds 0 and r17
        ret


 
diffval:  cp r25, r24               ; Sets c flag in SREG if a is greater than b
          brsh b_greater_than_a     ; Branches if c flag is 0 (if b is greater than a)
          sub r24, r25
          mov r25, r1
          ret
    
b_greater_than_a:  sub r25, r24
                   mov r24, 25
                   mov r25, r1
                   ret

  

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
