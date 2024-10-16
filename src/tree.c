#include <tree.h>
#include <queue.h>
#include <stdio.h>
#include <stdlib.h>

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