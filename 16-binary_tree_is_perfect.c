#include "binary_trees.h"

/**
 * maxValue - Returns the maximum of two numbers
 * @n1: first number
 * @n2: second number
 *
 * Return: The maximum number
 */

int maxValue(int n1, int n2)
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
	int leftHeight, rightHeight;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);

	leftHeight = binary_tree_height(tree->left);
	rightHeight = binary_tree_height(tree->right);

	return (1 + maxValue(leftHeight, rightHeight));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is perfect, 0 otherwise
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int leftHeight, rightHeight, leftPerfect, rightPerfect;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	leftHeight = binary_tree_height(tree->left);
	rightHeight = binary_tree_height(tree->right);

	if (leftHeight == rightHeight)
	{
		leftPerfect = binary_tree_is_perfect(tree->left);
		rightPerfect = binary_tree_is_perfect(tree->right);
		return (leftPerfect * rightPerfect);
	}
	else
	{
		return (0);
	}
}
