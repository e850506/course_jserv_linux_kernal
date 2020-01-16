/*
 *  created by unknowntpo at 2020.1.14(Tue)
 *  @ ref: https://hackmd.io/@sysprog/By0MltO_m?type=view
 *  @ title: Jserv linux核心 bitwise operation
 *  	     Setting and Clearing a Bit.
 *
 */

#include <stdio.h>
#include <stdbool.h>

/* 
 * @ Function: binary
 * @ convert the Decimal to Binary.
 * if n = 256
 * n in binary is    n = 0b100000000
 * the initial i is  i = 0b100000000
 * --> when first loop end, the printed value is 1. 
 */   
void binary(unsigned int n) {
	for (int i=256; i>0; i/=2) {  // i/=2 means right shift 1 bit 
		if (n & i)
			printf(" 1");
		else
			printf(" 0");
	}
	printf("\n");
}

/*
 * @ Function: getBit
 * @ get the current bit, which location is specified by the index.  
 *
 *
 */
bool getBit(int n, int index){
	return ((n & (1 << index)) >0);
}

/*
 *  @ Function: setBit
 *  @ set the current bit to 1.
 */
int setBit(int n, int index, bool b) {
	if(b)
		return (n | (1 << index)); // if b = true, just set the 'index'-th bit.
	int mask = ~(1 << index);
	return n & mask; // if b = false, the mask is used to unset the 'index'-th bit.
}


int main() {
	int num = 16, index;

	printf("input\n");
	for (int i = 7; i >=0; i--)
		printf("%d ", getBit(num,i));
	printf("\n");

	/* set bit */
	index = 6;
	printf("# Setting %d-th bit\n", index);
	num = setBit(num, index, true); // ""
	for (int i = 7; i >= 0; i--)
		printf("%d ", getBit(num,i));
	printf("\n");
	
	/* unset (clear) bit */
	index = 4;
	printf("# Clearing %d-th bit\n", index);
	num = setBit(num, index, false); // false means we want to clear the bit.
	for (int i = 7; i >= 0; i--)
		printf("%d ", getBit(num,i));
	printf("\n");

}





