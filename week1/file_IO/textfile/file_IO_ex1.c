/*
 *  Created by unknowntpo 2020.1.30 (Thu)
 *  @Title: example1 - write to a text file
 *  @ref: https://www.programiz.com/c-programming/c-file-input-output
 *  @abstract: takes a number from the user and stores in the file
 *             "program.txt".
 */
#include <stdio.h>
#include <stdlib.h>  // for declaration of exit()

int main(){
    int num;
    FILE *fptr;
    // use appropriate location if you are using MacOS or Linux
    fptr = fopen("program.txt", "w");

    if(fptr == NULL){
        printf("Error!");
        exit(1);  // what's this ?
    }

    printf("Enter num: ");
    scanf("%d", &num);
    
    fprintf(fptr, "%d", num);
    fclose(fptr);

    return 0;


}
