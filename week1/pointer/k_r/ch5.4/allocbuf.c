/*
 * @Title: K&R 5.4 Allocbuf
 * @Author: unknowntpo
 * @Ref: K&R 5.4
 */
#define ALLOCSIZE 10000 /* size of avaliable space */

static char allocbuf[ALLOCSIZE]; /* storage of alloc */
static char *allocp = allocbuf; /* next free position */

char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n; /* move allocp to next free pos. */
        return allocp-n; /* return old p for user */
    } else {
        return 0; /* not enough space */
    }
}


/* free storage pointed to by p */
void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p; /* move allocp to old pos. */
}
/* TODO strncpy to copy the string p */

int main()
{
    char *p = alloc(8);
    *p = "hello";
    afree(p);
    return 0;
}


