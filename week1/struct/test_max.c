#include <stdio.h>
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int main()
{
    int a = 5, b = 4;
    printf("which is max ? %d\n",MAX(a,b));
    return 0;
}
