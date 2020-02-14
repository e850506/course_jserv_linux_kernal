/*
    Created by unknowntpo at 2020.2.13 (Thu)
    @ title: print all string elements
*/

#include <stdio.h>


int main() {
    char sports[5][15] = {
        "golf",
        "hockey",
        "footbal",
        "cricket",
        "shooting"
    };
    int i = 0;
    int j = 0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 15; j++) {
             printf("%c\t", sports[i][j]);
        }
        printf("\n");
    }

    return 0;
}
