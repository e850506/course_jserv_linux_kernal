/*
 * Created by unknowntpo at 2020.1.19(Sun)
 * @ improved the algorithm of addition
 * @ $ less variables
 */


#include <stdio.h>

int addition (int a, int b){
    int carries = 1; // assigned 1 to carries to start the while loop
    while(carries != 0){
        if (carries != 0){ // with carries
            carries = a & b;
            a = a ^ b; // calculate the addition and assigned to a
            b = 0;
            carries <<=1; // left shift the carries
        }else {
            a = a ^ b;
            break;
        }
    }
    return a; // return the addition result
}

int main() { 
    int x = 0, y = 0, result = 0;
    printf("intput the numbers two add:\n");
    scanf("%d",&x);
    printf("next number:\n");
    scanf("%d",&y);
    printf("the numbers are %d + %d\n", x, y);
     
    result = addition(x, y);
    printf("result = %d", result);
}

