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
    // This pointer will hold the base
    // address of the block
    int *ptr;
    int n, i;

    // Get the number of the element
    n = 5;
    printf("Enter number of elements = %d\n", n);
    
    // Dynamically allocate memory using calloc()
    ptr = (int*)calloc(n, sizeof(int));

    // Check if the memory has successfully 
    // allocated by calloc or not.
    if (ptr == NULL) {
        printf("Memory not allocated .");
        exit(0);
    }else {
        // Memory has been successfully allocated.
        printf("Memory successfully allocated using calloc.\n");
        for (i=0; i < n; i++) {
            printf("%d", ptr[i]);
        }
    }
    
    return 0;
}

