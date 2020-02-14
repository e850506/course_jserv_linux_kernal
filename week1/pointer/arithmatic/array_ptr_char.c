/*
    Created by unknowntpo at 2020.2.13 (Thu)
    @title: A array of pointers to char to store a list of string
*/

#include <stdio.h>

const int MAX = 4;

int main() {
    char *names[] = {
        "Zara Ali",
        "Hina Ali",
        "Nuha Ali",
        "Sara Ali"
    };

    int i = 0;
    
    for (i = 0; i < MAX; i++) {
        printf("Value of names[%d] = %s\n", i, names[i]);
    }

    return 0;
} 
