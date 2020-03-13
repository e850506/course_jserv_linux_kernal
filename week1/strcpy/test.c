char *mystrcpy(char *dst, char *src) {
    while(*dst++ = *src++)
        ;
}

int main() {
    char *src = "hello";
    char dst[16] = {'0'};
    mystrcpy(dst, src);
    return 0;
}
