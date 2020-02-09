/*
    Created by unknowntpo at 2020.2.10 (Mon)
    @ title print the address of variable b.
*/

#include <stdio.h>

int main(){
    int b = 2;
    printf("value of b = %d\n",b);
    printf("address of b = %p\n",&b);
    printf("Value of b = %d\n", *&b); // get the value from the addr of b
    printf("Value of b = %d\n", &*b);
    return 0;
}
