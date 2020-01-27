/*
 *  created by unknowntpo
 *  2018-q1-課前測驗
 *  @ ref: My experiment record：https://hackmd.io/@unknowntpo/BJ-XC3wZL?type=view
 *  @ ref: 課前測驗參考解答 by 老師 https://hackmd.io/@sysprog/ByzoiggIb?type=view
 *  @ Title: LSB --> MSB reversal
 */
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>
uint32_t reverse_bits_32 (uint32_t x){
    uint32_t reverse_x = 0;
    for (int i=0; i<32; i++){    
	if (x & (1 << i))  // check if the value of bit[i] = 1
	/* left shift to set bit[(32-1) - i] to 1 */
	reverse_x |= 1 << ((32-1) - i); 
    }
    return reverse_x;
}

int main(int argc, char *argv[]){

    clock_t start_time, end_time;
    printf("pid = %d\n", getpid());	 
    // start counting
    start_time = clock();
    uint32_t reverse1 = reverse_bits_32(0x12345678);
    uint32_t reverse2 = reverse_bits_32( reverse1 );
    // end counting
    end_time = clock();
    printf("0x12345678 --> 0x%x --> 0x%x\n", reverse1, reverse2);
    printf("used time: %ld\n", end_time - start_time );
    return 0;
}


