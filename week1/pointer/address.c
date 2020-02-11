/*
    Created by unknowntpo at 2020.2.10 (Mon)
    @ title print the address of variable b.
*/

#include <stdio.h>

int main(){
    int b = 2;
    int *ptr = &b;
    unsigned long lu = 0;
    printf("value of b: %d\n", b);
    printf("addr. of b: %p\n", &b);
    printf("value of pointer: %p\n", ptr); // ptr == &b
    printf("addr. of pointer variable 'ptr': %p\n", &ptr);
    printf("value of pointer: %d\n", *ptr);
    return 0;
}
