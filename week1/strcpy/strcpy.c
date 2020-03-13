/* 
 * @ Author: unknowntpo
 * @ Time: 2020.3.04
 * @ Title: Experiment with the behavior of  
 *      @ strcpy function 
 *      @ Postfix-op ++
 *      @ Indirection (dereference) op *
 */
//#include <stdio.h>
char *mystrcpy(char *dst, char *src) {
    while(*dst++ = *src++)
        ;
}

int main() {
    char *src = "hello";
    char dst[16] = {'0'};
    mystrcpy(dst, src);
    //printf("size of src = %ld\n", sizeof(*src));
    //printf("size of dst = %ld\n", sizeof(*dst));

    return 0;
}
