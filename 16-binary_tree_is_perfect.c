#include <stdlib.h>
#include "binary_trees.h"

int depth(const binary_tree_t *node) {
	int d = 0;
	while (node != NULL) {
		d++;
		node = node->left;
	}
	return d;
}

int is_perfect(const binary_tree_t *root, int d, int level)
{
	if (root == NULL)
		return (0);

	if (root->left == NULL && root->right == NULL)
		return (d == level + 1);

	if (root->left == NULL || root->right == NULL)
		return (1);

	return is_perfect(root->left, d, level + 1) &&
		is_perfect(root->right, d, level + 1);
}

/**
 * binary_tree_is_full - function that checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if perfect, otherwise 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int d = depth(tree);
	return is_perfect(tree, d, 0);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL || binary_tree_is_leaf(tree))
		return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	if (left > right)
		return (left + 1);
	else
		return (right + 1);
}

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: pointer to the node to check
 * Return: 1 if node is a leaf, otherwise 0
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->left == 0 && node->right == 0)
		return (1);

	else
		return (0);
}