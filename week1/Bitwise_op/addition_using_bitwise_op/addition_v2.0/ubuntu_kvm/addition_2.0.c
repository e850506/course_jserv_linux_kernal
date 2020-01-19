/*
 * Created by unknowntpo at 2020.1.19(Sun)
 * @ improved the algorithm of addition
 * @ $ less variables
 */


#include <stdio.h>

int addition (int a, int b){
    int carries = 1; // assigned 1 to carries to start the while loop
    while(carries != 0){
        // we use a to store the runtime addition result
        
        carries = a & b; //calculate the carries
/*  Check if we are in round 2 (carries must be 0)  */   
        if (carries == 0){ // round 2, carries must be 0
            a = a ^ carries; // assign final result of addition to a 
            break;
        }
        a = a ^ b; // calculate the addition and assigned to a
        carries <<=1; // left shift the carries 
    }

    return 0;
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

