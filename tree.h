/*
 * This file is tree.h
 * Binary Search Tree (BST)
 *
 */

#pragma once
#include <stdio.h>

#define FALSE 0
#define TRUE 1

typedef struct _TREE_NODE *PTREE_NODE;

typedef struct _TREE_NODE 
{
    int key;
    PTREE_NODE left, right;
} TREE_NODE;

extern FILE *g_log;

PTREE_NODE init_tree(void);

/*
 * Add new element to the BST
 * Arguments:
 * 	tree - pointer to the tree
 *	key  - value of map key
 * Returns pointer to the tree (created or existing) 
 */
PTREE_NODE add_node(PTREE_NODE tree, int key); // prototype

/*
 * Delete element from BST
 * Arguments:
 * 	tree - pointer to the tree
 *	key  - value of map key
 * Returns pointer to the tree (deleted or existing) 
 */
PTREE_NODE delete_node(PTREE_NODE tree, int key);

/*
 * Print BST
 * Arguments:
 * 	tree - pointer to the tree
 * Returns none 
 */
void print_tree(PTREE_NODE tree);

// Get the element by key
PTREE_NODE find(int key);

void destroy_tree(PTREE_NODE tree);
