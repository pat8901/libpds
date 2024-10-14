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

typedef struct CircularQueue_
{
    uint32_t size;
    uint32_t capacity;
    uint32_t head;
    uint32_t tail;
    int *array;
} CircularQueue;

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

typedef struct BinaryTreeNode
{
    int id;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
} BinaryTreeNode;

typedef struct BinaryTree
{
    uint8_t size;
    struct BinaryTreeNode *root;
} BinaryTree;

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

/* Create a circular queue */
int queue_init(CircularQueue *queue, uint32_t size);
int queue_enqueue(CircularQueue *queue, int value);
int queue_dequeue(CircularQueue *queue);
void queue_print(CircularQueue *queue);
int queue_peek(CircularQueue *queue);
int queue_is_empty(CircularQueue *queue);
int queue_clear(CircularQueue *queue);

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

/* Binary Tree */
BinaryTreeNode *tree_init();
BinaryTreeNode *tree_create_node(int value);
BinaryTreeNode *tree_add(BinaryTreeNode **rootptr, int val);
void tree_remove(BinaryTreeNode **rootptr, int id);
BinaryTreeNode *tree_rsubtree_minimum(BinaryTreeNode *root);
int tree_get(BinaryTreeNode **rootptr, int id);
void tree_dfs_preorder(BinaryTreeNode **rootptr);
void tree_dfs_inorder(BinaryTreeNode *root);
void tree_dfs_postorder(BinaryTreeNode **rootptr);
void tree_bfs_print(BinaryTreeNode *root);

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