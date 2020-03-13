/*
 * @author: unkknowntpo
 * @abstract: play with malloc function.
 * @see: https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/
 *
 */
#include <stdio.h>
#include <stdlib.h> // contains the malloc func.

int main() 
{
    // This pointer will hold the
    // base addresss of the block created.
    int *ptr; 
    int n, i;

    // Get the number of elements for the array
    n = 5;
    printf("Enter number of elements: %d\n", n);
    
    // Dynamically allocate memory using malloc()
    ptr = (int*)malloc(n * sizeof(int));

    // Check if the memory has been successfully
    // allocated by malloc or not
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
        
        // Memory has been successfully allocated
        printf("Memory allocated successfully using malloc.\n");

        // Get the elements of the array
        for (i = 0; i < n; i++) { // why ++i?
            *ptr = i + 1;
            printf("ptr[i] = %d\n", *ptr);
            ptr++;
        }
    }
    return 0;
}
