#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: Height of tree or 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree || (!tree->left && !tree->right))
	{
		return (0);
	}
	if ((tree->left && !tree->right) || (!tree->left && tree->right))
		return (1);
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (MAX(left_height, right_height) + 1);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree
 * Return: 1 if it is perfect or 0 otherwise
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (!tree->left || !tree->right)
		return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	return (left == right ? 1 : 0);
}
