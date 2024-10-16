#ifndef Linked_list_H
#define Linked_list_H

typedef struct SingleLinkedNode
{
    int id;
    struct SingleLinkedNode *next;
} SingleLinkedNode;

/* Single linked list - allows duplicates */
typedef struct SingleLinkedList
{
    SingleLinkedNode *head;
    SingleLinkedNode *tail;
} SingleLinkedList;

typedef struct DoubleLinkedList
{
    /* data */
} DoubleLinkedList;

/* Create single linked list */
SingleLinkedList *slist_create();
int slist_prepend(SingleLinkedList *list, int id);
int slist_append(SingleLinkedList *list, int id);
int slist_remove_head(SingleLinkedList *list);
int slist_remove_tail(SingleLinkedList *list);
void slist_remove_list(SingleLinkedList *list);
void slist_get_id(SingleLinkedList *list, int id);
void slist_get_index(SingleLinkedList *list, int index);
void slist_print(SingleLinkedList *list);

#endif