/*
 * @ Author: unknowntpo
 * @ Time: 2020.3.5 (Thu)
 * @ Title: testing sqrt() function in <math.h>
 * @ Short Description:
 *      @ compute the result of distance using sqrt()
 */

#include <stdio.h>
#include <math.h>

typedef struct {
   int x;
   int y; 
}point;



int main() {
    point pt = {10, 20};
    double dist;
    printf("pt = (%d,%d)\n", pt.x, pt.y);
    dist = sqrt( (double)pt.x * pt.x + (double)pt.y * pt.y);
    printf("distance from origin to pt = %lf\n", dist);
}
