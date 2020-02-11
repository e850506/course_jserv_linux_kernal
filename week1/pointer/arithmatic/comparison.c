/*
 * Created by unknowntpo at 2020.2.11 (Tue)
 * @ pointer comparison.
 */

#include <stdio.h>

const int MAX = 3;

int main () {
    int var[] = {10, 100, 200};
    int i, *ptr;
    
    /* let us have array address of the first element in pointer.*/
    ptr = var;
    i = 0;
    while( ptr <= &var[MAX-1]) {
        printf("Address of var[%d] = %x\n", i, ptr);
        printf("value of var[%d] = %d\n", i, *ptr);
        /* point to the next element. */
        ptr++;
        i++;
    }    
    return 0;
}
