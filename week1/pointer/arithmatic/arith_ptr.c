/*
 * Created by unknowntpo at 2020.2.11 (Tue)
<<<<<<< HEAD
 * @ use pointer to array to increment a pointer
 */

##include <stdio.h>

const int MAX = 3;

int main () {
    int var[] = {10, 100, 200}
    int i, *ptr;

    /* let us have array address in pointer */
    ptr = var;
    for (i = 0; i < MAX; i++){
        printf("Address of var[%d] = %x\n", i, ptr);
        printf("Value of var[%d] = %d", i, *ptr);
        /* move to the next location */
    }
    return 0;
}
=======
 * @ use pointer to array to Incrementing a pointer
 * @ use 
>>>>>>> 06069572fcc714398c53f6e69a84147e58677351
