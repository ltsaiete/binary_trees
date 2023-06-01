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

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is perfect, 0 otherwise
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	int left_height = binary_tree_height(tree->left);
	int right_height = binary_tree_height(tree->right);

	if (left_height == right_height)
	{
		int left_perfect = binary_tree_is_perfect(tree->left);
		int right_perfect = binary_tree_is_perfect(tree->right);
		return (left_perfect * right_perfect);
	}
	else
	{
		return (0);
	}
}
