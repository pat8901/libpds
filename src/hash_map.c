#include <hash_map.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 10

Person **hash_init()
{
    Person **arr = malloc(sizeof(Person) * 10);

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Person *ptr = malloc(sizeof(Person));
        arr[i] = ptr;
        // arr[i] = malloc(sizeof(Person) * 10);
        snprintf(arr[i]->name, 256, "%s", "NULL");
        arr[i]->age = 0;
    }

    return arr;
}

int hash()
{
    return 5;
}

int hash_insert(Person **hash_table, char *name, int age, int hash)
{
    int key = hash;
    int idx = key % TABLE_SIZE;
    strcpy(hash_table[idx]->name, name);
    hash_table[idx]->age = age;

    return 0;
}

int hash_delete(Person **hash_table, int key)
{
    int idx = key % TABLE_SIZE;
    strcpy(hash_table[idx]->name, "NULL");
    hash_table[idx]->age = 0;

    return 0;
}

int hash_get(Person **hash_table, int key)
{
    int idx = key % TABLE_SIZE;
    printf("%d: Name: %s Age: %d\n", idx, hash_table[idx]->name, hash_table[idx]->age);

    return 0;
}

void hash_print_table(Person **hash_table, int table_size)
{
    for (int i = 0; i < table_size; i++)
    {
        printf("%d Name: %s Age: %d\n", i, hash_table[i]->name, hash_table[i]->age);
        printf("--------------------\n");
    }
}