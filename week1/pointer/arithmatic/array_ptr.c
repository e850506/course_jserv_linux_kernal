/*
 * Created by unknowntpo at 2020.2.11 (Tue)
 * @ experiment with array of pointer.
 */
#include <stdio.h>

const int MAX = 3;

int main() {
    int var[] = {10,100,200};
    int i, *ptr[MAX]; // declare the array of pointers ptr[MAX]

    for (i = 0; i < MAX; i++) {
        ptr[i] = &var[i]; // assign the addr. of integer.
    }
    for (i = 0; i < MAX; i++) {
        printf("value of var[%d] = %d\n", i, *ptr[i]);
    }
}
