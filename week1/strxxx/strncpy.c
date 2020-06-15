/*
 * @Title: strcpy v.s. strncpy
 * @Short_Description:
 *     the experiment of checking that which condition strncpy will add `\0` automatically
 * @Author: unknowntpo at 2020.4.17 (Wed)
 *     undated at 2020.4.21 (Mon)
 *     experiment recode: https://hackmd.io/@unknowntpo/strncpy
 * @Ref: Linux man page strncpy
 */
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
    int len = strlen(src);
    dest = malloc(sizeof(len + 1));
    dest = mystrncpy(dest, src, len + 1); // len+1 to tell mystrncpy to add `\0`
    return 0;
}
