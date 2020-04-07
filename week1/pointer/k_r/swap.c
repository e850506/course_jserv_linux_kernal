/*
 * @Title: swap function using pointer
 * @Author: unknowntpo
 * @Ref: K&R Ch5.2
 */
#include <stdio.h>

void swap(int *pa, int *pb)
{
    int temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}

int main()
{
    int a = 0, b = 1;
    printf("a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("After swap: a = %d, b = %d\n", a, b);
    return 0;
}
