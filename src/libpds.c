#include <libpds.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

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

    return 0;
}
