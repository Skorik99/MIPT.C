/*
 * This file is IIlist.h
 * Single linked list
 *
 */

#pragma once
#include <stdlib.h>
#include <stdio.h>

//Forward declaration


typedef struct _Node {
    int value;
    struct _Node *next;
    struct _Node *prev;
}Node;

typedef struct _DblLinkedList {
    int listII_size;
    Node *head;
    Node *tail;
} DblLinkedList;

/*
 * Creates an empty list
 * Params: none
 * Returns pointer to the list
 */
DblLinkedList* list_new(void);


/*
 * Deletes list and all the elements
 * Params: list - pointer to pointer to the list
 * Returns 1
 */
int list_delete(DblLinkedList **list);


/*
 * Allocate the element
 * put at the end
 * Params: *list - pointer to the list
 *         value - value to put in the node
 * Returns 1 or 0 depending on whether the operation was successful
 */
int push(DblLinkedList *list, int value);


/*
 * Remove the last element in the list
 * Params: *list - pointer to the list
 * Returns 1 or 0 depending on whether the operation was successful
 */
int pop(DblLinkedList *list);


/*
 * Allocate the element
 * put at the begining
 * Params: *list - pointer to the list
 *         value - value to put in the node
 * Returns 1 or 0 depending on whether the operation was successful
 */
int unshift(DblLinkedList *list, int value);


/*
 * Remove the first element in the list
 * Params: *list - pointer to the list
 * Returns 1 or 0 depending on whether the operation was successful
 */
int shift(DblLinkedList *list);


/*
 * Inverts the list
 * Params: *list - pointer to the list
 * Retunrns pointer to the invert list( it is a new list. not inverted list is free)
 */
DblLinkedList* reverse(DblLinkedList *list);

/*
 * auxiliary function. 
 * Required to check the correctness of the function reverse
 * Params: *list - pointer to the list
 * Returns none
 */
void printDblLinkedList(DblLinkedList *list);
