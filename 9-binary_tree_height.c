#include "binary_trees.h"

/**
 * max - Returns the maximum of two numbers
 * @n1: first number
 * @n2: second number
 *
 * Return: The maximum number
 */

int max(int n1, int n2)
{
	if (n1 >= n2)
	{
		return (n1);
	}
	else
	{
		return (n2);
	}
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree:  pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);

	int leftHeight = binary_tree_height(tree->left);
	int rightHeight = binary_tree_height(tree->right);

	return (1 + max(leftHeight, rightHeight));
}
