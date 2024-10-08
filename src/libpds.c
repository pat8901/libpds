#include <libpds.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int main()
{
    /* Single linked list test
    SingleLinkedList *list = slist_create();
    slist_append(list, 1);
    slist_append(list, 2);
    slist_append(list, 4);
    slist_append(list, 8);s
    slist_append(list, 16);
    slist_append(list, 32);
    slist_append(list, 64);
    slist_append(list, 128);
    slist_print(list);
    slist_remove_head(list);
    slist_remove_head(list);
    slist_print(list);
    slist_remove_tail(list);
    slist_remove_tail(list);
    slist_print(list);
    slist_get_id(list, 128);
    slist_get_index(list, 3);
    slist_prepend(list, 0);
    slist_prepend(list, -32);
    slist_print(list);
    */

    /* hashtable test
    Person **ptr_array = hash_init();
    hash_insert(ptr_array, "Jeff", 120, 4);
    hash_insert(ptr_array, "Rick", 54, 0);
    hash_print_table(ptr_array, TABLE_SIZE);
    hash_get(ptr_array, 0);
    hash_delete(ptr_array, 0);
    hash_print_table(ptr_array, TABLE_SIZE);
    hash_get(ptr_array, 4);
    hash_get(ptr_array, 0);
    */

    // Binary Tree
    // BinaryTreeNode *root = tree_init();
    BinaryTreeNode *root = NULL;

    tree_add(&root, 8);
    tree_add(&root, 5);
    tree_add(&root, 7);
    tree_add(&root, 10);
    tree_add(&root, 9);
    tree_add(&root, 13);
    tree_add(&root, 2);

    tree_dfs_inorder(root);
    printf("=========\n");
    tree_dfs_preorder(&root);
    printf("=========\n");

    tree_remove(&root, 10);
    printf("************\n");
    tree_dfs_preorder(&root);
    printf("************\n");

    return 0;
}

void slist_print(SingleLinkedList *list)
{
    int count = 0;
    printf("***********************\n");
    if (list->head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        SingleLinkedNode *curr = list->head;
        while (curr != NULL)
        {
            printf("%d: {id: %d}\n", count, curr->id);
            curr = curr->next;
            count++;
        }
    }
}

SingleLinkedList *slist_create()
{
    SingleLinkedList *ptr = (SingleLinkedList *)malloc(sizeof(SingleLinkedList));
    ptr->head = NULL;
    ptr->tail = NULL;

    return ptr;
}

int slist_prepend(SingleLinkedList *list, int id)
{
    SingleLinkedNode *temp = list->head;
    if (temp == NULL)
    {
        SingleLinkedNode *node = malloc(sizeof(SingleLinkedNode));
        node->id = id;
        node->next = NULL;
        list->head = node;
        list->tail = node;
    }
    else
    {
        SingleLinkedNode *node = malloc(sizeof(SingleLinkedNode));
        node->id = id;
        node->next = temp;
        list->head = node;
    }
    return 0;
}

int slist_append(SingleLinkedList *list, int id)
{
    printf("if: %d\n", id);
    SingleLinkedNode *curr = list->head;
    /* No nodes in list */
    if (curr == NULL)
    {
        printf("No nodes in list\n");
        SingleLinkedNode *node = malloc(sizeof(SingleLinkedNode));
        node->id = id;
        node->next = NULL;

        list->head = node;
        list->tail = node;
    }
    /* One or more nodes in list */
    else
    {
        printf("One node in list\n");
        SingleLinkedNode *node = malloc(sizeof(SingleLinkedNode));
        node->id = id;
        node->next = NULL;
        list->tail->next = node;
        list->tail = node;
    }
    return 0;
}

int slist_remove_head(SingleLinkedList *list)
{
    SingleLinkedNode *temp = list->head;
    if (temp == NULL)
    {
        printf("List is empty!\n");
    }
    else if (list->head == list->tail)
    {
        printf("Found a single node!\n");
        free(temp);
        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        printf("Found more than one node!\n");
        list->head = list->head->next;
        temp->next = NULL;
        free(temp);
    }
    return 0;
}

int slist_remove_tail(SingleLinkedList *list)
{
    SingleLinkedNode *temp = list->tail;
    if (list->tail == NULL)
    {
        printf("List is empty\n");
    }
    else if (list->head == list->tail)
    {
        list->head = NULL;
        list->tail = NULL;
        free(temp);
    }
    else
    {
        SingleLinkedNode *prev = list->head;
        SingleLinkedNode *next_prev = prev->next;
        while (next_prev->next != NULL)
        {
            prev = next_prev;
            next_prev = next_prev->next;
        }
        list->tail = prev;
        prev->next = NULL;
        free(temp);
    }
    return 0;
}

void slist_get_id(SingleLinkedList *list, int id)
{
    SingleLinkedNode *temp = list->head;

    if (temp == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        int count = 0;
        while (temp != NULL)
        {
            if (temp->id == id)
            {
                printf("Found %d at index %d\n", id, count);
                return;
            }
            temp = temp->next;
            count++;
        }
    }
    printf("Id not found!\n");
}

void slist_get_index(SingleLinkedList *list, int index)
{
    SingleLinkedNode *temp = list->head;

    if (temp == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        int count = 0;
        while (temp != NULL)
        {
            if (count == index)
            {
                printf("Found %d at index %d\n", temp->id, count);
                return;
            }
            temp = temp->next;
            count++;
        }
    }
    printf("Index not found!\n");
}

void slist_remove_list(SingleLinkedList *list)
{
}

BinaryTreeNode *tree_init()
{
    BinaryTreeNode *root = malloc(sizeof(BinaryTreeNode));
    // What does this do to the memory. It causes a segmentation fault. I set the pointer to mem to null?
    // root = NULL;
    return root;
}

BinaryTreeNode *tree_create_node(int value)
{
    BinaryTreeNode *node = malloc(sizeof(BinaryTreeNode));
    if (node != NULL)
    {
        node->id = value;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

BinaryTreeNode *tree_add(BinaryTreeNode **rootptr, int val)
{
    BinaryTreeNode *root = *rootptr;

    if (root == NULL)
    {
        printf("NULL found: adding '%d'\n", val);
        (*rootptr) = tree_create_node(val);
        return *rootptr;
    }
    if (root->id == val)
    {
        printf("Node '%d' already exist\n", val);
        return;
    }
    if (val < root->id)
    {
        printf("traversing left\n");
        tree_add(&root->left, val);
    }
    if (val > root->id)
    {
        printf("traversing right\n");
        tree_add(&root->right, val);
    }
}

void tree_remove(BinaryTreeNode **rootptr, int id)
{
    BinaryTreeNode *root = *rootptr;
    if (root == NULL)
    {
        printf("%d not found\n", id);
        return;
    }
    if (root->id > id)
    {
        printf("traversing left\n");
        tree_remove(&root->left, id);
    }
    else if (root->id < id)
    {
        printf("traversing right\n");
        tree_remove(&root->right, id);
    }
    // Delete node
    else
    {
        printf("%d found\n", id);
        // No children
        if (root->left == NULL)
        {
            printf("Setting right/null child\n");
            BinaryTreeNode *temp = root->right;
            free(root);
            *rootptr = temp;
        }
        else if (root->right == NULL)
        {
            printf("Setting left child\n");
            BinaryTreeNode *temp = root->left;
            free(root);
            *rootptr = temp;
        }
        // There is two children
        else
        {
            printf("Node (%d) has two children\n", root->id);
            BinaryTreeNode *minimum = tree_rsubtree_minimum(root->right);
            printf("Right subtree min is Node (%d)\n", minimum->id);
            root->id = minimum->id;
            tree_remove(&root->right, minimum->id);
        }
    }
    return;
}

BinaryTreeNode *tree_rsubtree_minimum(BinaryTreeNode *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

int tree_get(BinaryTreeNode **rootptr, int id)
{
    BinaryTreeNode *root = *rootptr;
    if (root == NULL)
    {
        printf("%d does not exist\n", id);
        return 0;
    }
    if (root->id == id)
    {
        printf("Found %d\n", id);
        return 0;
    }
    if (root->id < id)
    {
        tree_get(&root->right, id);
    }
    if (root->id > id)
    {
        tree_get(&root->left, id);
    }
}

void tree_dfs_inorder(BinaryTreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    tree_dfs_inorder(root->left);
    printf("%d\n", root->id);
    tree_dfs_inorder(root->right);
}

void tree_dfs_preorder(BinaryTreeNode **root_ptr)
{
    BinaryTreeNode *root = *root_ptr;

    if (root == NULL)
    {
        return;
    }
    printf("%d\n", root->id);
    tree_dfs_preorder(&root->left);
    tree_dfs_preorder(&root->right);
}

void tree_dfs_postorder(BinaryTreeNode **rootptr)
{
    BinaryTreeNode *root = *rootptr;
}

int tree_bfs_print(BinaryTree *tree)
{
}

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