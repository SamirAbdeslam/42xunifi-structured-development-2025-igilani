/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilani <igilani@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:36:29 by igilani           #+#    #+#             */
/*   Updated: 2025/06/11 22:01:02 by igilani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filesystem.h"

FSNode *create_file(const char *name, int size)
{
	FSNode *file;

	file = malloc(sizeof(FSNode));
	if (!file)
		return (NULL);
	file->name = strdup(name);
	if (!file->name)
	{
		free(file);
		return (NULL);
	}
	file->size = size;
	file->child = NULL;
	file->next_sibling = NULL;
	return (file);
}

FSNode *create_folder(const char *name)
{
	FSNode *folder;

	folder = malloc(sizeof(FSNode));
	if (!folder)
		return (NULL);
	folder->name = strdup(name);
	if (!folder->name)
	{
		free(folder);
		return (NULL);
	}
	folder->size = 0;
	folder->child = NULL;
	folder->next_sibling = NULL;
	return (folder);
}

void add_child(FSNode *parent, FSNode *child)
{
	if (!parent)
		return ;
	if (!parent->child)
		parent->child = child;
	else
	{
		FSNode *curr = parent->child;
		while (curr->next_sibling)
			curr = curr->next_sibling;
		curr->next_sibling = child;
	}
}

FSNode *get_children(const FSNode *parent)
{
	return(parent->child);
}

FSNode *get_sibling(const FSNode *node)
{
	return (node->next_sibling);
}

void print_tree(FSNode *root, int size)
{
	while (root)
	{
		int i = size;
		while (i)
		{
			printf("  ");
			i--;
		}
		printf("%s", root->name);
		if (root->size == 0)
		{
			printf("/\n");
			print_tree(root->child, size + 1);
		}
		else
			printf(" [%d]\n", root->size);
		root = root->next_sibling;	
	}
}

// int main()
// {
// 	FSNode *root;
// 	FSNode *file = create_file("readme", 100);
// 	FSNode *folder = create_folder("Documents");
// 	FSNode *file2 = create_file("readme", 200);
// 	FSNode *folder2 = create_folder("Desktop");

// 	root = create_folder("root");
// 	add_child(root, file);
// 	add_child(root, folder);
// 	add_child(folder, file2);
// 	add_child(folder, folder2);

// 	print_tree(root, 0);
// 	return (0);
// }