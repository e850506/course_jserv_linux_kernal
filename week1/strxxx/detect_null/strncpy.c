#include <stdio.h>
#define DETECTNULL(X) (((X)-0x01010101) & ~(X)&0x80808080)
int main() {
  unsigned int x = 0, y = 1;
  char null = '\0';
  printf("result of detectnull(x): %d\n", DETECTNULL(x));
    printf("result of detectnull(y): %d\n", DETECTNULL(y));
  printf("result of detectnull(null): %d\n", DETECTNULL(null));
  return 0;
}
