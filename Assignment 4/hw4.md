Problem 1:
a. What instructions does the compiler produce in assembly for “writing” to the 
RCC_AHB2ENR bit when using bit-band address? 
MOVS	R0, #1
LDR.N	R1, [PC, #0x38]; References a constant of 0x42420980
STR		R0, [R1]

b. What were the instructions produced when writing to the RCC_AHB2ENR without using 
bit-banding? 
LDR.N	R0, [PC, #0x3c]
LDR		R1, [R0]
ORRS.W	R1, R1, #1
STR		R1, [R0]

Problem 2:
a. How does the calling function “func2” pass the values to the called function “func1”? 
Func2 stores the first 4 arguments (32-bit ints) in registers R0-R3. It pushes the fifth argument onto the stack.
b. What extra code did the compiler generate before calling the function “func1” with the 
multiple arguments? 
It had a single instruction to PUSH R7 and the link register to the stack.
c. What extra code did the compiler generate inside the called function “funct1” with the 
list of multiple arguments? 
It pushes R4 to the stack. It then uses R4 to increament a variable as coded in c. I then pops the stack back into R4 before returning to the calling function func2.

d. Any other observations? 
Because my func1 function does nothing with the input arguments, but instead increments a new variable, the passed registers are untouched by func1. It instead uses R4 as its stratch register, while saving it on the stack first.

