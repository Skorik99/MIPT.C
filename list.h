/*
 * This file is slist.h
 * Single linked list
 *
 */

#pragma once
#include <stdlib.h>
#include <stdio.h>
// Forward declaration

typedef struct slist_entry *pslist_entry;
typedef struct slist *pslist;

struct slist_entry
{
    pslist_entry next;
    int value;
};

struct slist
{
    int list_size;
    pslist_entry head;
};

/*
 * Creates an empty list
 * Params: none
 * Returns pointer to the list
 */

pslist slist_new(void);

/*
 * Deletes list and all the elements
 * Params: list - pointer to the list
 * Returns none
 */

void slist_delete(pslist list);

/*
 * Allocate the element
 * put at the beginning
 * Params: list - pointer to the list
 *         value - value to put in the node
 * Returns 0
 */
int slist_insert(pslist list, int value);

/*
 Go through the list, remove if value is equal
 * Params: list - pointer to the list
 *         value - value for check
 * Returns: 0
 */
int slist_remove(pslist list, int value);

/*
 * For each element print in value
 * Params: list - pointer to the list
 * Returns none
 */
void slist_print(pslist list);
