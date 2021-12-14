/*******************************************************************************
File name       : user_led.s
Description     : Assembly language function for controlling the user LED
*******************************************************************************/   

    EXTERN delay                    // delay() is defined outside this file

    PUBLIC control_user_led1        // Exports symbols to other modules

// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables. The syntax for declaring bss section is -
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.
// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : control_user_led1
Description     : - Uses Peripheral registers at base 0x4800.0000
                    to set GPIOA Output Data Register.
                  - Calls another assembly function delay to insert
                    delay loop

C Prototype     : void control_user_led(uint8_t state, uint32_t duration)
                : Where state indicates if LED should be on or off.
Parameters      : R0: uint8_t state
                : R1: uint32_t duration
Return value    : None
*******************************************************************************/  

GPIOA_BASE  EQU 0x48000000
GPIOA_ODR   EQU 0x14
GPIOA_BIT_5 EQU 0x20

control_user_led1
    PUSH {R4,LR}        //Save R4 and the LR as they will be modified
    LDR R2, =GPIOA_BASE  //Puts a constant into R2, GPIOA_BASE
    LDR R3, =GPIOA_ODR   //Puts a constant into R3, GPIOA_ODR offset
    ADD R2, R2, R3      //Add the offset to the base to get the address of GPIOA_ODR
    LDR R4, [R2]        //Put the contents of the address at R2 into R4
    CBZ R0, TURN_OFF    //Check if R0 is zero, clear bit if it is
    MOV R3, #1          //Place a 1 in R3 for the next insrtuction
    BFI R4, R3, #5, #1  //Write a 1 to the bit at positon five of R3
    B SET_ODR
TURN_OFF
    BFC R4, #5, #1      //Clear bit position 5 of R4
SET_ODR
    STR R4, [R2]        //Put R4 into the address stored in R2, GPIOA_ODR changes state
    MOV R0, R1          //Put the argument for delay into R0
    BL delay            //call the dealy function
    POP {R4,LR}         //revert R4 back, retrieve link pointer
    BX LR               // return
    END
