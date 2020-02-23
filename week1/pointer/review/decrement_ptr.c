/*
    Created by unknowntpo at 2020.2.16(Sat)
    @ decrementing a ptr.
*/

#include <stdio.h>

const int MAX = 3;

int main() {
    
    int var[] = {100, 200, 300};
    int i, *ptr;
    ptr = &var[MAX-1]; // ptr points to the last element of array
    
    for (i = MAX; i > 0; i--){
        printf("Address of var[%d] = %x\n", i-1, ptr );
        printf("Value of var[%d] = %d\n", i-1, *ptr );
        ptr--;
    }
} 
