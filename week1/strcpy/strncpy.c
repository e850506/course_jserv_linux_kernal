/*
 * @Title: strcpy v.s. strncpy
 * @Author: unknowntpo at 2020.4.8 (Wed)
 * @Ref: https://skylinelimit.blogspot.com/2018/02/c-2.html
 */
#include <string.h>
#include <stdio.h>

int main (void)
{
    /* Buffer Overflow 

    int i = 5;
    char s[8] = "Hi 1234";

    printf("addr. of i: %p\naddr. of s: %p\n", &i, s);
    strcpy(s, "hello sky");
    printf("value of s: %s\nvalue of i:%d", s, i);
    
    */

    /* strncpy version */
    int i = 67; // ASCII 'C'
    char s[8] = "Hi 1234";

    printf("addr. of i: %p\naddr. of s: %p\n", &i, s);
    strncpy(s, "hello sky", 8);
    printf("value of s: %s\nvalue of i:%d", s, i);

    return 0;
}
