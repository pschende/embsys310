#include<string.h>
#include"morse.h"
#include "led.h"
#define DELAY_CONST 100000

int morse_code(char *code){
	int beep = 0;
        int i = 0 ;
	for (i = 0; i < strlen(code); i++){
		switch (code[i]){
			case 'A':
			case 'a':
				beep = 0x12;
				break;
			case 'B':
			case 'b':
				beep = 0x2111;
				break;
			case 'c':
			case 'C':
				beep = 0x2121;
				break;
			case 'd':
			case 'D':
				beep = 0x211;
				break;
			case 'E':
			case 'e':
				beep = 0x1;
				break;
			case 'F':
			case 'f':
				beep = 0x1121;
				break;
			case 'G':
			case 'g':
				beep = 0x221;
				break;
			case 'H':
			case 'h':
				beep = 0x1111;
				break;
			case 'I':
			case 'i':
				beep = 0x11;
				break;
			case 'J':
			case 'j':
				beep = 0x1222;
				break;
			case 'k':
			case 'K':
				beep = 0x212;
				break;
			case 'L':
			case 'l':
				beep = 0x1211;
				break;
			case 'M':
			case 'm':
				beep = 0x22;
				break;
			case 'N':
			case 'n':
				beep = 0x21;
				break;
			case 'O':
			case 'o':
				beep = 0x222;
				break;
			case 'P':
			case 'p':
				beep = 0x1221;
				break;
			case 'Q':
			case 'q':
				beep = 0x2212;
				break;
			case 'R':
			case 'r':
				beep = 0x121;
				break;
			case 'S':
			case 's':
				beep = 0x111;
				break;
			case 'T':
			case 't':
				beep = 0x2;
				break;
			case 'U':
			case 'u':
				beep = 0x112;
				break;
			case 'V':
			case 'v':
				beep = 0x1112;
				break;
			case 'W':
			case 'w':
				beep = 0x122;
				break;
			case 'X':
			case 'x':
				beep = 0x2112;
				break;
			case 'Y':
			case 'y':
				beep = 0x2122;
				break;
			case 'z':
			case 'Z':
				beep = 0x2211;
				break;
			case '1':
				beep = 0x12222;
				break;
			case '2':
				beep = 0x11222;
				break;
			case '3':
				beep = 0x11122;
				break;
			case '4':
				beep = 0x11112;
				break;
			case '5':
				beep = 0x11111;
				break;
			case '6':
				beep = 0x21111;
				break;
			case '7':
				beep = 0x22111;
				break;
			case '8':
				beep = 0x22211;
				break;
			case '9':
				beep = 0x22221;
				break;
			case '0':
				beep = 0x22222;
				break;
			case 0x20:
				beep = -1;
			default :
				beep = 0;
		}
		morse_letter(beep);
	}
	return beep;
}
	
void morse_letter(int beep){
	if (beep == -1){
		delay(7);
	}
	else{
		if (beep & 0x30000){
			led_on();
			if (beep & 0x20000){
				delay(3);
			}
			else {
				delay(1);
			}
			led_off();
			delay(1);
		}
		if (beep & 0x3000){
			led_on();
			if (beep & 0x2000){
				delay(3);
			}
			else {
				delay(1);
			}
			led_off();
			delay(1);
		}
		if (beep & 0x300){
			led_on();
			if (beep & 0x200){
				delay(3);
			}
			else {
				delay(1);
			}
			led_off();
			delay(1);
		}
		if (beep & 0x30){
			led_on();
			if (beep & 0x20){
				delay(3);
			}
			else {
				delay(1);
			}
			led_off();
			delay(1);
		}
		if (beep & 0x3){
			led_on();
			if (beep & 0x2){
				delay(3);
			}
			else {
				delay(1);
			}
			led_off();
			delay(1);
		}
		delay(3);
	}
}

void delay(int pause_units){
	pause_units *= DELAY_CONST;
	while (pause_units > 0){
		pause_units--;
	}
}
