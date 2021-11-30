#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Function deletes an entire binary tree
 * @node: pointer to the node to be checked
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if(!node)
		return(0);

	if(node->left || node->right)
		return(0);
	else
		return(1);
}
