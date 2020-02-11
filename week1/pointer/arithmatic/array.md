## C-Array of pointer

Before we understand the concept of arrays of pointers, let us consider the following example, which uses an array of 3 integers −
#### Consider a program:
```c
#include <stdio.h>

const int MAX = 3;

int main () {

   int  var[] = {10, 100, 200};
   int i;

   for (i = 0; i < MAX; i++) {
      printf("Value of var[%d] = %d\n", i, var[i] );
   }

   return 0;
}
```
Output:
```
Value of var[0] = 10
Value of var[1] = 100
Value of var[2] = 200
```
* There may be a situation when we want to maintain an array,
    * which can store
        * pointers to an
            * int or
            * char or
            * any other data type available.

Following is the declaration of an array of pointers to an integer.

```c
int *ptr[MAX];
```

It declares ```ptr``` as **an array of ```MAX``` integer pointers**<br>Thus, each element in ```ptr```, holds a pointer to an int value,
<br>
The following example uses theree integers, which are stored in **an array of pointers**.


```c
#include <stdio.h>

const int MAX = 3;

int main () {

   int  var[] = {10, 100, 200};
   int i, *ptr[MAX];

   for ( i = 0; i < MAX; i++) {
      ptr[i] = &var[i]; /* assign the address of integer. */
   }

   for ( i = 0; i < MAX; i++) {
      printf("Value of var[%d] = %d\n", i, *ptr[i] );
   }

   return 0;
}
```
Output:
```
$ ./array_ptr
value of var[0] = 10
value of var[1] = 100
value of var[2] = 200
```
