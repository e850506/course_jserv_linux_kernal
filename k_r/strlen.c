/*
    Created by unknowntpo at 2020.2.17 (Mon)
    @ title: Count the length of a string.
*/

/* strlen: return length of string s */

#include <stdio.h>
int forstrlen(char *s) { // s is a lical variable pointer
                     // pointed to the first element of string.
    int n;
    
    for (n=0; *s !='\0'; s++)
        n++;
    return n;
}



int mystrlen(char *s)
{
    int n;
    while(*s++ != '\0')
        n++;
    return n;
}


int main() {
    int len = 0;
    len = mystrlen("Hello World.");
    printf(" the length of the string = %d\n", len);
    len = forstrlen("Hello World.");
    printf(" the length of the string = %d\n", len);

}
