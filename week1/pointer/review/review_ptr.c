/*
    Created by unknowntpo at 2020.2.16 (Sun)
    @ use pointer++ to manipulate an array.
*/

#include <stdio.h>

const int MAX = 3;

int main () {
    int var[] = {100, 200, 300};
    int i, *ptr;
    
    /* let us have array address in pointer */
    ptr = var;
    for (i = 0; i < MAX; i++){
        printf("the address of var[%d] is %x\n", i, ptr);
        printf("the value of var[%d] is %d\n", i, *ptr);
        /* move to the next element */
        ptr++;
    }

}
