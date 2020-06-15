#include <stdio.h>

size_t mystrlen(char *s)
{
    int n;
    for(n = 0; *s != '\0'; n++)
        s++;
    return n;
}

int main()
{
    int n = mystrlen("hello");
    printf("n = %d", n);
    return 0;
}
