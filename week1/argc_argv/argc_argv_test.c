/*
 * Created by unknowntpo at 2020.1.27 (Mon)
 * @ title: C argc, *argv example
   @ link : http://crasseux.com/books/ctutorial/argc-and-argv.html    
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int count;
    printf("This program was called with \"%s\".\n",argv[0]);
    
    if (argc > 1){
            // print all of the argument
            for (count=1; count < argc; count++){
                printf("argv[%d] = %s\n", count, argv[count]);
            }
        }
    else{
        printf("The command had no other arguments.");
    }
    return 0;
}
