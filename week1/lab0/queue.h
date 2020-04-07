#ifndef LAB0_QUEUE_H
#define LAB0_QUEUE_H

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 * 
 * It uses a singly-linked list to represent the set of queue elements
 */
#include <stdbool.h>
#include <stddef.h>

/* Data structure declarations */

/* Linked list element (You shouldn't need to change this) */
typedef struct ELE {
    /* Pointer to array holding string.
     * This array needs to be explicitly allocated and freed
     */
    char *value;
    struct ELE *next;
} list_ele_t;
typedef struct{
    list_ele_t *head;
    list_ele_t *tail;
    int size;
}queue_t;




