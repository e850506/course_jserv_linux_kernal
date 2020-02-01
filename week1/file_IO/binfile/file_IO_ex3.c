/*
 *  Created by unknowntpo at 2020.1.30 (Fri)
 *  @title      : Write to a binary file using fwrite()
 *  @ref        : https://www.programiz.com/c-programming/c-file-input-output
 *  @abstract   : write to a binary file using fwrite()
 *
 */

#include <stdio.h>
#include <stdlib.h>

struct threeNum
{
    int n1, n2, n3;
};

int main()
{
    int n;
    struct threeNum num;
    FILE *fptr;  // pointer to the file location

    if ((fptr = fopen("program.bin", "wb")) == NULL){
        printf("Error when opening file");

        // pointer exits if the file pointer returns NULL.
        exit(1);
    }

    for(n = 1; n < 5; ++n){
        num.n1 = n;
        num.n2 = 5*n;
        num.n3 = 5*n + 1;
        /* fwrite(addressData, sizeData, numbersData, pointerToFile) */   
        fwrite(&num, sizeof(struct threeNum), 1, fptr);   
    }
    fclose(fptr);

    return 0;
}
