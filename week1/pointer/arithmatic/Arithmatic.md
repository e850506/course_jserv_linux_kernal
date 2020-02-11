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
Output:
```
Address of var[0] = e775c71c
Value of var[0] = 10
Address of var[1] = e775c720
Value of var[1] = 100
Address of var[2] = e775c724
Value of var[2] = 200
```

## Decrementing a Pointer
```c
#include <stdio.h>

const int MAX = 3;

int main () {

   int  var[] = {10, 100, 200};
   int  i, *ptr;

   /* let us have array address in pointer */
   ptr = &var[MAX-1];

   for ( i = MAX; i > 0; i--) {

      printf("Address of var[%d] = %x\n", i-1, ptr );
      printf("Value of var[%d] = %d\n", i-1, *ptr );

      /* move to the previous location */
      ptr--;
   }

   return 0;
}
```
Output:
```
Address of var[2] = bfedbcd8
Value of var[2] = 200
Address of var[1] = bfedbcd4
Value of var[1] = 100
Address of var[0] = bfedbcd0
Value of var[0] = 10
```
## Pointer Comparisons
>Pointers may be compared by using relational operators, such as ```==```, ```<```, and ```>```.<br>
If p1 and p2 point to variables that are related to each other, such as elements of the same array, then p1 and p2 can be meaningfully compared.


```c
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
```


Output:
```
Address of var[0] = e695e70c
value of var[0] = 10
Address of var[1] = e695e710
value of var[1] = 100
Address of var[2] = e695e714
value of var[2] = 200
```
