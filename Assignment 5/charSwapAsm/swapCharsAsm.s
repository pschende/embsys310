/*******************************************************************************
File name       : swapCharsAsm.s
Description     : Assembly language function for swapping two chars
*******************************************************************************/   
    
    PUBLIC swapCharsAsm       // Exports symbols to other modules
                        // Making swapCharsAsm available to other modules.
    
// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables.
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
Function Name   : swapCharsAsm
Description     : swaps the values within two char, compares them, 
                : returns 0 if the same, returns 1 if differnt
C Prototype     : int swapCharsAsm(char* charPtr1, char* charPtr2)
                : Charptrs are the addresses of the chars to be swapped and compared
Parameters      : R0: char pointer, R1: char pointer
Return value    : R0: integer 0 for match, 1 for mismatch
*******************************************************************************/  
  
swapCharsAsm
    LDRB R2, [R0]        // load char value stored at address in R0 into R2
    LDRB R3, [R1]        // load char value stored at address in R1 into R3
    STRB R2, [R1]        // load R2 into the address stored in R1
    STRB R3, [R0]        // load R3 into the addree stored in R0
    CMP R2, R3          //compare R2 and R3
    BEQ CHARS_ARE_EQ    //Branch if R2 and R3 are equal, goto GARS_ARE_EQ
    MOV R0, #1          //Chars are not equal put 1 in R0 to return
    B CHARS_ARE_DIFF    //Skip the next instruction
CHARS_ARE_EQ
    MOV R0, #0          //Chars are equal, set R0 to 0 to return
CHARS_ARE_DIFF
    BX LR               // return (with function result in R0)

    END
