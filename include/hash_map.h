#ifndef Hash_map_H
#define Hash_map_H

#define MAX_NAME 256

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