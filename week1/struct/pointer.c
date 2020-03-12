#include <stdio.h>

struct pointer {
    int len;
    char *str;
};

int main() {

    struct pointer *p;
    p->len = 1;
    // struct *p->str = "hello";
    //printf("p -> len = %d", p->len);
    //printf("++p -> len = %d", ++p->len);
    return 0;
}
