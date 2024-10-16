#ifndef Tree_H
#define Tree_H

#include <stdint.h>

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

#endif