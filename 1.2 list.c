// this function implements a list with elements from 1 to N
// and is a solution to task 1.2
pslist first_integers(int N)
{
    int count = 1;
    if(N < 0)
    {  printf("Error! Please, enter a positive number");
        exit(-1);
    }
    if(N == 0)
    {
        printf("allocated memory for an empty list!");
        return slist_new();
    }
    pslist ordered = slist_new();
    while(ordered->list_size < N)
    {
        slist_insert(ordered, count);
        count++;
    }
    return ordered;
}

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

pslist slist_new(void)
{
    pslist plst;
    plst = (pslist)malloc(sizeof(struct slist));
    plst->head = (pslist_entry)malloc(sizeof(struct slist_entry));
    plst->list_size = 0;
    plst->head->next = NULL;
    return(plst);
}

pslist_entry slist_pop(pslist list)
{
    pslist_entry prev = NULL;
    int val;
    if(list->head == NULL)
        exit(-1);
    prev = list->head;
    val = prev->value;
    list->head = list->head->next;
    free(prev);
    return NULL;
}

void slist_delete(pslist list)
{
    while(list->head->next)
    {
        slist_pop(list);
        list->head = list->head->next;
    }
    free(list->head);
    free(list);
}

int slist_insert(pslist list, int value)
{
        pslist_entry tmp = (pslist_entry)malloc(sizeof(struct slist_entry));
        if (tmp == NULL)
        return -1;
        tmp->next = list->head;
        tmp->value = value;
        printf("New element: %d\n", tmp->value);
        list->head = tmp;
        list->list_size++;
        return 0;
}

int slist_remove(pslist list, int value)
{
    pslist_entry prev = NULL, prevprev; // Указатели на предыдущий и предпредыдущий элемент
    int val; // сравниваемое значение
    if(list->head == NULL)
        exit(-1);
    prevprev = prev;
    prev = list->head;
    val = prev->value;
    list->head = list->head->next;
    while(list->head)
    {
        if(val == value)
        {
            prevprev->next = list->head; // указатель, который ссылался на элемент, значение которого равно значению
                                         // value, теперь ссылается на следующий за этим элемент.
            free(prev);
            prev = prevprev;
        }
        prevprev = prev;
        prev = list->head;
        val = prev->value;
        list->head = list->head->next;
    }
    return 0;
}

void slist_print(pslist list)
{
    pslist_entry pcurrent = list->head;
    printf("List: \n");
    while (pcurrent != NULL)
    {
       printf("> %d\n", pcurrent->value);
       pcurrent = pcurrent->next;
    }
}


pslist first_integers(int N)
{
    int count = 1;
    if(N < 0)
    {  printf("Error! Please, enter a positive number");
        exit(-1);
    }
    if(N == 0)
    {
        printf("allocated memory for an empty list!");
        return slist_new();
    }
    pslist ordered = slist_new();
    while(ordered->list_size < N)
    {
        slist_insert(ordered, count);
        count++;
    }
    return ordered;
}

int main()
{
    first_integers(-5);
    first_integers(0);
    first_integers(8);
    return 0;
}
