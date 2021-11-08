1. Inject 0x7FFFFFFF for the “counter” value in the variable window, then step thru the program 
only once to increment “counter”. 
a) What is the value of the “counter” from the “Locals” window? 
The Locals window is setup in default view which displays a signed int. It reads -2147483648.
b) What is the value of the “counter” in the “Registers” window? 
The register window shows the counter stored in R0. It reads 0x80000000
c) Please note down which flags are set in the APSR register. And explain why. 
The N bit for a negative result is set. The V bit for an overflow is also set. Both are set because the counter storing 0x7FFFFFFF incremented to 0x80000000. The instruction used to increment the R0 register was ADDS which sets N flag if the result is negative (0x80000000 is -2147483648 if interpreted as a signed int) and sets the V flag if overflow occurs (the R0 register was 2147483647 and went to -2147483648).

2. If your write all Fs (0XFFFFFFFF) in the Register value for “counter” then step thru the program 
once to increment “counter” 
a) What happens to the value of “counter” in the “Locals” window? 
The value of counter is zero after incrementing.
b) Please note down which are set in the APSR register. And explain why. 
The Z flag is set because the result of the ADDS instruction resulted in zero. The C flag is set because the ADDS instruction resulted in a value greater than or equal to 2^32.

3. Change the “counter” variable type in your code to “unsigned int”. Inject the values 
“0x7FFFFFFF” then step thru the program to increment the “counter” once: 
a) What is the value of “counter” in the “Locals” window after incrementing for each value? 
The value of counter in the Locals window is 2147483648. The locals window tracks the type as defined in the C code as unsigned int.
b) Please note down which flags are set in the APSR register. And explain why. 
THe N bit is set because the most significant bit of the result of the ADDS instruction is set; however, it is not technically a negative number from the C code's perspective. The V bit is set as well because the result of adding two positives resulted in a negative number (MSb is set).

4. Change the “counter” variable type in your code to “unsigned”. Inject the values “0xFFFFFFFF” 
then step thru the program to increment the “counter” once: 
a) What is the value of “counter” in the “Locals” window after incrementing for each value? 
The result is zero.
b) Please note down which are set in the APSR register. And explain why.
The Z flag is set because the result of the ADDS instruction resulted in zero. The C flag is set because the ADDS instruction resulted in a value greater than or equal to 2^32.

5. Move the “counter’ variable outside of main (at the top of the file): 
a) What is the scope of the variable “counter”? 
The counter variable is now a global variable.
b) Is it still visible in the “Locals” view? 
No, counter is located outside of the main() function.
c) In which window view can we track “counter” now?
I set up a watch window. It can also be view in the memory window.  
d) What is the address of the “counter” variable in memory? 
0x20000000

6. Change the source code to the following, then run the program in the simulator: 
a) What is the value of “counter” at the end of the program (halting at the return 0 statement) 
The value of counter is 4.
b) Explain why the counter value has changed? 
Counter has been increamented 4 times despite only being explicitly increamented in the C code because the compiler chose
 to store counter at 0x20000000 in the same place as *p_int is pointing to. The program increments the value where p_int points to. If the compiler chose to store counter in a different location than it did, then counter would only be 1 as it would not be affected by the pointer variable. 

7. Change the setting of IAR to run the same program on the evaluation board:
a) What is the address where “counter” is stored?  
0x20000000
b) Is the “counter” variable stored in RAM or ROM? 
It is in SRAM1
c) What is the value of “counter” at the end of the program (halting at the return 0 
statement).  
It is 4.
