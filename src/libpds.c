#include <libpds.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

#define TABLE_SIZE 10

int main()
{
    queue_t *queue = qinit(16, sizeof(int));
    queue_t *tree_queue = qinit(16, sizeof(BinaryTreeNode));

    BinaryTreeNode *node1 = malloc(sizeof(BinaryTreeNode));
    node1->id = 128;

    BinaryTreeNode *node2 = malloc(sizeof(BinaryTreeNode));
    node2->id = 256;
    qadd(tree_queue, node1);
    qadd(tree_queue, node2);

    BinaryTreeNode *result1 = (BinaryTreeNode *)qremove(tree_queue);
    if (result1 != NULL)
    {
        printf("Node1 id: %d\n", result1->id);
    }
    BinaryTreeNode *result2 = (BinaryTreeNode *)qremove(tree_queue);
    if (result2 != NULL)
    {
        printf("Node2 value: %d\n", result2->id);
    }
    BinaryTreeNode *result3 = (BinaryTreeNode *)qremove(tree_queue);
    if (result3 != NULL)
    {
        printf("Node3 value: %d\n", result3->id);
    }

    // int a = 101;
    // int b = 32;

    // int *ptr = &a;
    // int *bptr = &b;

    // qadd(queue, bptr);
    // qadd(queue, ptr);

    // int *value1 = ((char *)qremove(queue));
    // printf("value: %d\n", *value1);

    // int *value2 = ((char *)qremove(queue));
    // printf("value: %d\n", *value2);

    // int value3 = ((char *)qremove(queue));
    // if (value3 != NULL)
    // {
    //     printf("value: %d\n", value3);
    // }

    return 0;
}

queue_t *qinit(int max_size, size_t item_size)
{
    queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
    queue->data = malloc(item_size * max_size);
    queue->max_size = max_size;
    queue->current_size = 0;
    queue->item_size = item_size;
    queue->front = 0;
    queue->rear = 0;
    return queue;
}

void qprint(queue_t *queue)
{
    if (queue == NULL || queue->current_size == 0)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for (int i = 0; i < queue->max_size; i++)
        {
            int value = queue->data;
        }
    }
}

int qadd(queue_t *queue, void *item)
{
    if (queue->current_size == queue->max_size)
    {
        printf("Queue is full\n");
        return -1;
    }
    else if (queue->current_size == 0)
    {
        void *target = (char *)queue->data + (queue->rear * queue->item_size);
        printf("Queue is empty\n");
        memcpy(target, item, queue->item_size);
        queue->current_size += 1;
    }
    else
    {
        printf("Queue is not empty\n");
        queue->rear = (queue->rear += 1) % queue->max_size;
        void *target = (char *)queue->data + (queue->rear * queue->item_size);
        memcpy(target, item, queue->item_size);
        queue->current_size += 1;
    }
    return 0;
}

void *qremove(queue_t *queue)
{
    if (queue->current_size == 0)
    {
        printf("Queue is empty\n");
        return NULL;
    }

    void *target = (char *)queue->data + (queue->front * queue->item_size);
    if (queue->current_size == 1)
    {
        printf("Queue has only 1 item\n");
        queue->current_size--;
        queue->front = 0;
        queue->rear = 0;
        return target;
    }
    printf("Queue has more than 1 item\n");
    queue->current_size--;
    queue->front = (queue->front += 1) % queue->max_size;
    return target;
}

int queue_init(CircularQueue *queue, uint32_t size)
{
    queue->size = size;
    printf("size: %d\n", size);
    queue->capacity = 0;
    queue->array = malloc(sizeof(uint32_t) * size);
    return 0;
}

int queue_enqueue(CircularQueue *queue, int value)
{
    if (queue->capacity == queue->size)
    {
        printf("Queue is full\n");
        return -1;
    }
    // queue is empty
    if (queue->capacity == 0)
    {
        printf("Queue is empty: adding (%d)\n", value);
        queue->head = 0;
        queue->tail = 0;
        queue->array[queue->tail] = value;
        queue->capacity++;
    }
    else
    {
        printf("Queue not empty: adding (%d)\n", value);
        queue->tail = (queue->tail += 1) % queue->size;
        queue->array[queue->tail] = value;
        queue->capacity++;
        printf("New Capacity: %d\n", queue->capacity);
    }
    return 0;
}

int queue_dequeue(CircularQueue *queue)
{
    if (queue->capacity == 0)
    {
        printf("Queue is empty! Cannot dequeue\n");
        return 0;
    }
    if (queue->head == queue->tail)
    {
        printf("One item found: (%d)\n", queue->array[queue->head]);
        int return_value = queue->array[queue->head];
        queue->head = 0;
        queue->tail = 0;
        queue->capacity = 0;
        return return_value;
    }
    int return_value = queue->array[queue->head];
    queue->head = (queue->head + 1) % queue->size;
    queue->capacity--;
    printf("Dequeued (%d)\n", return_value);
    return return_value;
}

int queue_clear(CircularQueue *queue)
{
    if (queue_is_empty(queue))
    {
        printf("Can not clear, queue is already empty\n");
        return 1;
    }

    queue->capacity = 0;
    queue->head = 0;
    queue->tail = 0;

    return 0;
}

void queue_print(CircularQueue *queue)
{
    for (int i = 0; i < queue->size; i++)
    {
        if (queue->head == i && queue->tail == i)
        {
            printf("%d: value=%d (head)(tail)\n", i, queue->array[i]);
        }
        else if (queue->head == i)
        {
            printf("%d: value=%d (head)\n", i, queue->array[i]);
        }
        else if (queue->tail == i)
        {
            printf("%d: value=%d (tail)\n", i, queue->array[i]);
        }
        else
        {
            printf("%d: value=%d\n", i, queue->array[i]);
        }
    }
}

int queue_peek(CircularQueue *queue)
{
    if (queue->capacity == 0)
    {
        printf("Peek: queue is empty!\n");
        return 1;
    }
    int value = queue->array[queue->head];
    printf("Peek: %d\n", value);
    return value;
}

int queue_is_empty(CircularQueue *queue)
{
    if (queue->capacity == 0)
    {
        return 1;
    }
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
    if (id < root->id)
    {
        printf("traversing left\n");
        tree_remove(&root->left, id);
    }
    else if (id > root->id)
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

// TODO: change binary tree so dequeue will return tree nodes
// TODO: Make a queue that can hold tree nodes
void tree_bfs_print(BinaryTreeNode *root)
{
    CircularQueue *queue = malloc(sizeof(CircularQueue));
    queue_init(queue, 32);

    if (root == NULL)
    {
        printf("Tree is empty!\n");
        return;
    }
    queue_enqueue(queue, root->id);

    while (!queue_is_empty(queue))
    {
        int node = queue_dequeue(queue);
        printf("Node value\n");
        if (1)
        {
            // enqueue left child if it exist
        }
        if (1)
        {
            // enqueue right child if it exist
        }
    }
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