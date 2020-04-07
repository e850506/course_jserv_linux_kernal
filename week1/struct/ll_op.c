/* 
 *  Build the list {1, 2, 3} in the heap and
 *  store its head pointer in a local stack variable.
 *  Returns the head pointer to the caller. */
#include <stdlib.h> // for malloc()
#include <stddef.h>

typedef struct node{
    int data;
    struct node *next;
}node;

struct node* BuildOneTwoThree()
{
    node *head = malloc(sizeof(node*)); // allocated first block of memory to head.
    node *second = NULL; // memory not allocated yet 
    node *third = NULL;
    return head;
}
int main()
{
    node *list; 
    list = BuildOneTwoThree();
    return 0;
} 
