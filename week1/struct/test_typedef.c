#include<stdio.h>

void foo(void);
 
int main()
{
    typedef unsigned char uchar;
    uchar ch = 'a';
    printf("ch inside main() : %c\n", ch);
    foo();
    return 0;
}
 
void foo(void)
{
    uchar ch = 'a'; // Error
    unsigned char ch = 'z';
    printf("ch inside foo() : %c\n", ch);
}
