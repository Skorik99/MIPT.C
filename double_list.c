#include <stdio.h>
#include <stdlib.h>
#include "iilist.h"


DblLinkedList* list_new()
{
    DblLinkedList *tmp = (DblLinkedList*) malloc(sizeof(DblLinkedList));
    tmp->listII_size = 0;
    tmp->head = tmp->tail = NULL;
    return tmp;
}

int list_delete(DblLinkedList **list) {
    Node *tmp = (*list)->head;
    Node *next = NULL;
    while (tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(*list);
    (*list) = NULL;
    return 1;
}


int push(DblLinkedList *list, int value) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL) {
        return 0;
    }
    tmp->value = value;
    tmp->next = NULL;
    tmp->prev = list->tail;
    printf("New element: %d\n", tmp->value);
    if (list->tail) {
        list->tail->next = tmp;
    }
    list->tail = tmp;

    if (list->head == NULL) {
        list->head = tmp;
    }
    list->listII_size++;
    return 1;
}

int pop(DblLinkedList *list) {
    Node *next;
    int tmp;
    if (list->tail == NULL) {
        return 0;
    }

    next = list->tail;
    list->tail = list->tail->prev;
    if (list->tail) {
        list->tail->next = NULL;
    }
    if (next == list->head) {
        list->head = NULL;
    }
    tmp = next->value;
    free(next);

    list->listII_size--;
    return 1;
}

int unshift(DblLinkedList *list, int data) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL) {
        return 0;
    }
    tmp->value = data;
    tmp->next = list->head;
    tmp->prev = NULL;
    printf("New element: %d\n", tmp->value);
    if (list->head) {
        list->head->prev = tmp;
    }
    list->head = tmp;

    if (list->tail == NULL) {
        list->tail = tmp;
    }
    list->listII_size++;
    return 1;
}


int shift(DblLinkedList *list) {
    Node *prev;
    int tmp;
    if (list->head == NULL) {
        return 0;
    }

    prev = list->head;
    list->head = list->head->next;
    if (list->head) {
        list->head->prev = NULL;
    }
    if (prev == list->tail) {
        list->tail = NULL;
    }
    tmp = prev->value;
    free(prev);

    list->listII_size--;
    return 1;
}

DblLinkedList* reverse(DblLinkedList *list)
{
    DblLinkedList* inv = list_new();
    while(inv->listII_size < list->listII_size)
    {
        unshift(inv, list->head->value);
        list->head = list->head->next;
    }
    free(list);
    return inv;
}


void printDblLinkedList(DblLinkedList *list) {
    Node *tmp = list->head;
    while (tmp) {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}


int main()
{
    DblLinkedList* list = list_new();
    push(list, 1);
    push(list, 2);
    push(list, 3);
    push(list, 4);
    push(list, 5);
    DblLinkedList* invert = reverse(list);
    printDblLinkedList(invert);
    return 0;
}
