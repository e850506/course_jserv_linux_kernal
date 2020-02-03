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
    if (argc < 3) {  // type ./rcf to check the manual.
        printf( "\nUsage:" 
                "\t %s input.txt output.txt\n\n"
		"This is a simple encrypt/decrypt app "
   		"based on reverse_bit algorithm.\n\n"   
		, argv[0]);
        return 0;
    }
    
    const char *input_path = argv[1]; // input from input.txt
    FILE *fin = fopen(input_path, "rb"); // dealing with file input 
    if (!fin) {
	fprintf(stderr, 
            "Error: failed to open input file %s\n", input_path);
	exit(-1);
    }
    
    const char *output_path = argv[2]; // argv[2] = output.txt
    FILE *fout = fopen(output_path, "wb"); // dealing with file output
    if (!fout) {
        fclose(fin);
        fprintf(stderr,
            "ERROR: failed to open output file %s\n", output_path);
        exit(-1); // EXIT_FAILURE;
    }

    uint32_t ch; // pointer to the the text 
    int nread;
    while((nread = fread(&ch, 1, sizeof(uint32_t), fin)) > 0){
        /* if read size less than sizeof(uint32_t), just write it. */
        if (nread < sizeof(uint32_t)){
            fwrite(&ch, 1, nread, fout);
        }
        else {
                uint32_t chn = reverse_bit(ch);
                fwrite(&chn, 1, nread, fout);
        }
        printf("nread=%d\n", nread);
        fclose(fin);
        fclose(fout);
        return 0;
    }
}
