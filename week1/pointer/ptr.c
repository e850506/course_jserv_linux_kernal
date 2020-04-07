int main()
{    
    int x = 1; 
    int *ip; /* ip is a pointer to int */
    ip = &x; /* assign addr. of x to pointer ip */
    int **pp = &ip; /* assign ip's addr. to y; (pointer to pointer ) */
    *ip = 0; /*set pointer ip's addr. to zero */
}
