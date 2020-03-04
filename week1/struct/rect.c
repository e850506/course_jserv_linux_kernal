/*
 * @ File name: rect.c
 * @ Author: unknowntpo at 2020.2.24 (Mon)
 * @ Title: Structure tag;
 * @ Short description:
 *      Nested structure "screen"  
 *      use member access operator (.)
 *      to access nested structure screen.pt1.x 
 */

#include <stdio.h>

struct point {
    int x;
    int y;
};

typedef struct {
    struct point pt1;
    struct point pt2;  
} rect;

int main () {
    //struct rect screen;
    rect screen;
    screen.pt1.x = 3;
    screen.pt1.y = 0;
    screen.pt2.x = 2;
    screen.pt2.y = 1;


    printf("screen pt1 : (%d,%d)\n", screen.pt1.x, screen.pt1.y);
    printf("screen pt2 : (%d,%d)\n", screen.pt2.x, screen.pt2.y);




}


