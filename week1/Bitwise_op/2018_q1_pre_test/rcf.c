/*
 * Created by unknowntpo at 2020.1.27 (Mon)
 * @ ref: 課前測驗參考解答
 *	  https://hackmd.io/@sysprog/ByzoiggIb?type=view
 *	  https://hackmd.io/DFko67zDSy-uUp3ZuTbcug?view
 * @ title: 加解密程式 rcf.c (week 1 課前測驗 2018q1 )
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t reverse_bit(uint32_t x) {
    x = ((x & 0xffff0000) >> 16) | ((x & 0x0000ffff) << 16);
    x = ((x & 0xff00ff00) >>  8) | ((x & 0x00ff00ff) <<  8);
    x = ((x & 0xf0f0f0f0) >>  4) | ((x & 0x0f0f0f0f) <<  4);
    x = ((x & 0xcccccccc) >>  2) | ((x & 0x33333333) <<  2);
    x = ((x & 0xaaaaaaaa) >>  1) | ((x & 0x55555555) <<  1);
    return x;
}	

int main(int argc, char *argv[]){
    if (argc < 3) {
        printf( "\nUsage:" 
                "\t %s input.txt output.txt\n\n"
		"This is a simple encrypt/decrypt app "
   		"based on reverse_bit algorithm.\n\n"   
		, argv[0]);
        return 0;
    }
    
    const char *input_path = argv[1];
    FILE *fin = fopen(input_path, "rb");
    if (!fin) {
    	fclose(fin);
	fprintf(stderr, 
	       "Error: failed to open input file %s\n", input_path);
	exit(-1);
    }
    
    const char *output_paht = argv[2];
    FILE *fout = fopen(output_path, "wb");


}
