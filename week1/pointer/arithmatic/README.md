## Pointer arithmatic
[Tutorialspoint](https://www.tutorialspoint.com/cprogramming/c_pointer_arithmetic.htm)
>There are four arithmetic operators that can be used in pointers:
>```++```, ```--```,```+```,```-```

## Incrementing a Pointer

We prefer using a pointer to an array ```array[10]``` because
* we can use ```ptr++``` to increment to next array element.
    * ```array``` is a constant pointer, can't be incremented.

### Demo:
```c
/*
 * Created by unknowntpo at 2020.2.11 (Tue)
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

```
