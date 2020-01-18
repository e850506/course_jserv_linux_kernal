/*
 * Created by unknowntpo at 2020.1.18(Sat)
 *
 * @ title: Do the addition using bitwise operation
 * @ ref : https://hackmd.io/UwDCb8YMQ--gneR2eqEGWw?both
 */

#include <stdio.h>

int addition (int x, int y){
    int b = 0;
    do {
        // a : store the runtime addition result
        // b : stores the carries
        int a = 0;
        
        a = x ^ y;  // XOR simulate x + y (without carries)
        b = x & y;  // AND assigned the carries to b
        
        if (b == 0)
            return a;
        else
            b <<= 1;
        printf("b = %d\n", b);
        x = a;
        y = b;
    }while(b != 0);
    
    return 0;
}

int main() {
    int x = 0, y = 0, result = 0;
    printf("intput the numbers two add:\n");
    scanf("%d",&x);
    printf("next number:\n");
    scanf("%d",&y);
    printf("the numbers are %d + %d", x, y);
    
    result = addition(x, y);
    printf("result = %d", result);
}
// 3 = 0b0011
// 2 = 0b0010
//3+2 error : 4 infinite loop
// 3 & 2 = 0b0010 (count the carries)
// 3 ^ 2 = 0b0001 (addition without carries)
//
