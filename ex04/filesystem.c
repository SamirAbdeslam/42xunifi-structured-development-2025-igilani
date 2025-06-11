/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilani <igilani@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:36:29 by igilani           #+#    #+#             */
/*   Updated: 2025/06/11 19:00:29 by igilani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filesystem.h"

FSNode *create_file(const char *name, int size)
{
	FSNode *file = malloc(sizeof(FSNode));
	if (!file)
		return NULL;
	file->name = strdup(name);
	if (!file->name)
	{
		free(file);
		return NULL;
	}
	file->size = size;
	file->parent = NULL;
	file->children = NULL;
	file->next_sibling = NULL;
	return file;
}

FSNode *create_folder(const char *name)
{
	FSNode *folder = malloc(sizeof(FSNode));
	if (!folder)
		return NULL;
	folder->name = strdup(name);
	if (!folder->name)
	{
		free(folder);
		return NULL;
	}
	folder->size = 0;
	folder->parent = NULL;
	folder->children = NULL;
	folder->next_sibling = NULL;
	return folder;
}

void add_child(FSNode *parent, FSNode *child)
{
	if (!parent || !child)
		return;

	child->parent = parent;
	child->next_sibling = parent->children;
	parent->children = child;
}