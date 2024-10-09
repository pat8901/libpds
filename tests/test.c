#include <assert.h>
#include <libpds.h>

void test();

// TODO: Look into the testing framework Unity
int main(void)
{
    test();
    return 0;
}

void test()
{
    assert(tree_create_node(5)->id == 5);
    printf("All tests have passed!\n");
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
    // BinaryTreeNode *root = NULL;

    // tree_add(&root, 8);
    // tree_add(&root, 5);
    // tree_add(&root, 7);
    // tree_add(&root, 10);
    // tree_add(&root, 9);
    // tree_add(&root, 13);
    // tree_add(&root, 2);

    // tree_dfs_inorder(root);
    // printf("=========\n");
    // tree_dfs_preorder(&root);
    // printf("=========\n");

    // tree_remove(&root, 10);
    // printf("************\n");
    // tree_dfs_preorder(&root);
    // printf("************\n");
}