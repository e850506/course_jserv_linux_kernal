/*
 * Created by unknowntpo at 2020.1.10 (Fri)
 * @ Title : Bitwise Operation practice (jserv Linux 核心設計)
 * 
 * @ Ref : https://hackmd.io/@sysprog/By0MltO_m?type=view
 */

// Set a bit 
// where n is the bit number, and 0 is the least significant bit.
#include <stdio.h>

/* bit clear
   a : int,
   pos : bit position to clear */
#define CLEARBIT(a, pos) ( a &= ~( 1 << pos ) ) // 1 left shift to the position, and use ~ to let 1 to 0,
										// and use bitwise AND to set that bit in positon pos to zero.


#define SETBIT(b, pos) ( b |= ( 1 << pos ) ) // 1 left shift to the position, and use bitwise OR to set the bit
									 // to 1

#define TOGGLEBIT(c, pos) ( c ^= (1 << pos) ) // shift the bit "1" to the pos, and use ^ XOR to TOGGLE it

int DecToBinary(char dec);   // later seperate it to different file. DecToBinary.h .c.

void modulus (int i);


int main() {
	/* 'z': decimal number value 122 (0b01111010) */
	char a = 'z';

	/* Clearing the 5th bit */
	char a_Out = CLEARBIT(a, 5);
	printf("a_Out = %c\n", a_Out);

	/* a_Out: 'Z': decimal  value 90 = (122 - 1*2^5) = 122 - 32 */
	

	/* Select the bit position to set */
	char b = 'y';
	char b_Out = SETBIT(b, 5);
	printf("b_Out = %c\n", b_Out);

	/* Toggle the bit */
	// untested code.
	char c = 'a';       
	printf("%d", (int)c); 
	char c_Out = TOGGLEBIT(c, 5); // c_OUT: decimal value = 65
	printf("%c",c_Out); // c_OUT: "A" 
}


