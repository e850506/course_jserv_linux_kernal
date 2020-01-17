/*
 * Created by unknowntpo at 2020.1.15(Wed)
 * @ title: 2018q1 第一週測驗題
 * @ ref  : https://hackmd.io/@sysprog/rJh9U4Guf?type=view
 * @ abstract : Check whether the input integer is N's multiple,
 *              then find the value of N.
 */

#include <stdlib.h>
#include <stdio.h>
int isMultN(unsigned int n) {
	int odd_c =0, even_c =0;  /* variables to cound odd and even SET bits */

	if (n == 0)    // return true if difference is 0;
		return 1;
	if (n == 1)
		return 0;

	while (n) {
		if (n & 1)	// odd bit is SET, increment odd C
			odd_c++;
		n >>=1;    // n right shift 1 bit.

		if (n & 1)    // even bits is SET, increment evnet even_c
			even_c++;
		n = n >> 1;
	}

	/* Recursive call till you get 0/1 */
	return(isMultN(abs(odd_c - even_c)));
}
void testNum(int n) {
	
}

int main() {
	unsigned int n=2; // set the test num to 4
	int result=0;
	for (int i=4; i<5;i++){
		result = isMultN(i);
		printf("test num=%d, result=%d\n",i,result);
	}
}
