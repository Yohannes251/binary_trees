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
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: pointer to the root node of the tree
 * Return: 1 if it is full or 0 otherwise
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);

	left = binary_tree_is_full(tree->left);
	right = binary_tree_is_full(tree->right);

	return (MIN(left, right));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree
 * Return: 1 if it is perfect or 0 otherwise
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *left_t, *right_t;
	int left, right;

	if (!tree)
		return (0);

	left_t = tree->left;
	right_t = tree->right;

	if (!tree->left && !tree->right)
		return (1);

	if (!tree->left || !tree->right)
		return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	if (left == right)
		if (binary_tree_is_full(left_t) && binary_tree_is_full(right_t))
			return (1);
	return (0);
}
