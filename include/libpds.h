#ifndef LIBPDS_H
#define LIBPDS_H

#include <stdint.h>

#define MAX_NAME 256

typedef struct Stack
{
    char *stack;
    int size;
    int capacity;
    char *top;
} Stack;

typedef struct SingleLinkedNode
{
    int id;
    void *next;
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

typedef struct HashMap
{
    /* data */
} HashMap;

/* Structs for testing */
typedef struct Person
{
    char name[MAX_NAME];
    int age;
} Person;

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

/* Create hash table */
Person **hash_init();
/* Generate hash */
int hash();
/* Insert value into hash table */
int hash_insert(Person **hash_table, char *name, int age, int hash);
/* Delete value from hash table */
int hash_delete(Person **hash_table, int idx);
/* Get value from hash table */
int hash_get();
/* Print the whole hash table */
void hash_print_table(Person **hash_table, int table_size);

#endif