#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *mystrncpy(char *dest, const char *src, size_t n)
{
    size_t i;
    
    for(i= 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    for( ; i < n; i++)
        dest[i] = '\0';
    return dest;
}

int main()
{
    char *src = "hello";
    char *dest;
    int len = strlen(src);
    dest = malloc(sizeof(len + 1));
    dest = mystrncpy(dest, src, len); // len means we don't copy the '\0' from src
    return 0;
}
