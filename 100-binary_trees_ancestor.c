#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 *
 * Return: depth of tree
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->parent == NULL)
		return (0);

	return (1 + binary_tree_depth(tree->parent));
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 *
 * Return: a pointer to the lowest common ancestor node of the two given node
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *fparent, *sparent;
	// int fdepth, sdepth;

	// fdepth = binary_tree_depth(first);
	// sdepth = binary_tree_depth(second);

	// if (fdepth != sdepth)
	// {
	// 	if (fdepth > sdepth)
	// 	{
	// 		fparent = first;
	// 		sparent = second->parent;
	// 	}
	// 	else
	// 	{
	// 		fparent = first->parent;
	// 		sparent = second;
	// 	}
	// }
	// else if (first == second)
	// {
	// 	fparent = first;
	// 	return (fparent);
	// }
	// else
	// {
		fparent = first->parent;
		sparent = second->parent;
	// }

	if (fparent == sparent)
	{
		return (fparent);
	}
	else if (fparent == NULL || sparent == NULL)
	{
		return (NULL);
	}
	else
	{
		return (binary_trees_ancestor(fparent, sparent));
	}
}
