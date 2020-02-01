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
   if ((fptr = fopen("program.txt","r")) == NULL){
       printf("Error! opening file");
       // Program exits if the file pointer returns NULL.
       exit(1);
   }
   fscanf(fptr,"%d", &num);
   printf("Value of n=%d", num);
   fclose(fptr);

   return 0;
}
