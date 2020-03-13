/*
 * @ author: unknowntpo at 2020.3.2
 * @ queue.c: play with queue using array.
 * @ insert: insert element to queue.
 * @ delete: delete first element of queue.
 * @ traverse: display all queue.
 */
#include <stdio.h>
#include "queue.h"

#define CAPACITY 5

int queue[CAPACITY] = {0,0,0,0,0};

/*@ TODO fix the rear don't move to next problem */

int insert(int ele, int front, int rear) {
    int i = 0;
    if (rear == CAPACITY)
        printf("Queue is full.\n");
    queue[rear] = ele;
    rear++;
    return rear; 
};


void delete () {

};

void traverse() {
    int i = 0;
    for (i = 0; i < CAPACITY; i++){
        printf("queue[%d] =%d\n", i,  queue[i]);
    }   
};



int main () {
    int front = 0;
    int rear = 0;
    /* Print the queue */
    traverse();
    printf("\n");
    /* insert an element on queue */
    insert(5, 0, 0);
    printf("\n");
    traverse();
    printf("\n");
    
    /* insert an element on queue */    
    insert(10, 0, 0);
    printf("\n");
    traverse();
    printf("\n");

    return 0;
}
