/*
 *  Created by unknowntpo at 2020.1.30 (Fri)
 *  @title      : Read to a binary file using fread()
 *  @ref        : https://www.programiz.com/c-programming/c-file-input-output
 *  @abstract   : Read to a binary file using fread()
 *
 */

#include <stdio.h>
#include <stdlib.h>

struct threeNum
{
    int n1, n2, n3;
};    // struct variable ??

int main()
{
    int n;
    struct threeNum num;
    FILE *fptr;

    if ((fptr = fopen("program.bin", "rb")) == NULL){
        printf("Error! opening file.");
            // program exits if the file pointer returns NULL.
            exit(1);
    }

    for(n = 1; n < 5; ++n){     // ++n vs n++ ?
        fread(&num, sizeof(struct threeNum), 1, fptr);
        printf("n1: %d\tn2: %d\tn3: %d\n", num.n1, num.n2, num.n3);
    }  
    // try without fclose --> nothing special happened. 
    fclose(fptr);

    return 0;
}
