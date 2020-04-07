/*
 * @Title: CMU Linked List tutorial implementation
 * @Author: unknowntpo
 * @Ref: http://www.cs.cmu.edu/~iliano/courses/18S-CMU-CS122/handouts/10-linkedlist.pdf
 */

typedef struct list_node list; // hold the actual element of queue in linked list
struct list_node{
    int data;
    list *next;
}
typedef struct queue_header queue; // declare queue with front and back
struct queue_header{
    list *front;
    list *back;
};

typedef queue *queue_t; // declare an interface

bool is_queue(queue* Q)
{
    return Q != NULL // NULL queue is not a valid queue.
        && is_acyclic(Q->front) // acyclic queue is not the queue we want 
        && is_segment(Q->front, Q->back); // queue needs to be a list segment (?
}

bool queue_empty(queue* Q)
//@requires is_queue(Q);
{
    return Q->front == Q->back; // if front == back, then queue is empty
}
