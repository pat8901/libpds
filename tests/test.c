#include <assert.h>
#include <libpds.h>
#include <stdlib.h>

void test_linkedlist_single();
void test_tree();
void test_hashmap();
void test_queue();

// TODO: Look into the testing framework Unity
int main(void)
{
    return 0;
}

void test_linkedlist_single()
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
}

void test_tree()
{
    // Binary Tree
    assert(tree_create_node(5)->id == 5);
    printf("All tests have passed!\n");

    BinaryTreeNode *root = tree_init();
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
}

void test_hashmap()
{
    /* hashmap test
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
}

void test_queue()
{
    CircularQueue *queue = malloc(sizeof(CircularQueue));
    printf("Queue: array-address=%p \n", queue->array);
    queue_init(queue, 10);
    printf("Queue: array-address=%p \n", queue->array);

    queue_enqueue(queue, 0);
    queue_enqueue(queue, 1);
    queue_enqueue(queue, 2);
    queue_enqueue(queue, 4);
    queue_enqueue(queue, 8);
    queue_enqueue(queue, 16);
    queue_enqueue(queue, 32);
    queue_enqueue(queue, 64);
    queue_enqueue(queue, 128);
    queue_enqueue(queue, 256);

    queue_dequeue(queue);
    queue_enqueue(queue, 88);
    queue_dequeue(queue);
    queue_enqueue(queue, 100);
    queue_dequeue(queue);
    queue_dequeue(queue);
    queue_dequeue(queue);

    queue_enqueue(queue, 200);
    queue_enqueue(queue, 300);
    queue_enqueue(queue, 400);
    queue_enqueue(queue, 500);
    queue_print(queue);
    queue_peek(queue);

    queue_clear(queue);
    queue_print(queue);
    queue_peek(queue);
}