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

typedef struct SingleLinkedList
{
    // data
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

Person **hash_init();                                                // Create hash table
int hash();                                                          // Generate hash
int hash_insert(Person **hash_table, char *name, int age, int hash); // Insert value into hash table
int hash_delete(Person **hash_table, int idx);                       // Delete value from hash table
int hash_get();                                                      // Get value from hash table
void hash_print_table(Person **hash_table, int table_size);          // Print the whole hash table

#endif