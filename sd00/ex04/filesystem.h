/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilani <igilani@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:32:57 by igilani           #+#    #+#             */
/*   Updated: 2025/06/11 21:20:46 by igilani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct FSNode {
	char *name;
	int size;
	struct FSNode *child;
	struct FSNode *next_sibling;
} FSNode;

void add_child(FSNode *parent, FSNode *child);
FSNode *create_file(const char *name, int size);
FSNode *create_folder(const char *name);
FSNode *get_children(const FSNode *parent);
FSNode *get_sibling(const FSNode *node);

#endif