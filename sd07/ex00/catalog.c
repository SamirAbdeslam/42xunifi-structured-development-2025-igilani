/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catalog.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilani <igilani@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:41:11 by apeero            #+#    #+#             */
/*   Updated: 2025/06/23 19:31:35 by igilani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void ft_free_split(char **split)
{
    int i = 0;

    if (!split)
        return;

    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

static int	ft_atoi_strict(const char *str)
{
	int i = 0;
	int res = 0;

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

static int parse_line(char *line, t_book *book)
{
	char **parts;
	int id;

	parts = ft_split(line, ',');
	if (!parts)
		return (0);
	if (!parts[0] || !parts[1] || !parts[2] || parts[3])
	{
		ft_free_split(parts);
		return (0);
	}

	// Trim fields
	char *trim_id = ft_strtrim(parts[0], " \t\n\v\f\r");
	char *trim_title = ft_strtrim(parts[1], " \t\n\v\f\r");
	char *trim_author = ft_strtrim(parts[2], " \t\n\v\f\r");

	ft_free_split(parts);

	if (!trim_id || !trim_title || !trim_author)
	{
		free(trim_id);
		free(trim_title);
		free(trim_author);
		return (0);
	}

	id = ft_atoi_strict(trim_id);
	free(trim_id);
	if (id < 0)
	{
		free(trim_title);
		free(trim_author);
		return (0);
	}

	book->id = id;
	book->title = trim_title;
	book->author = trim_author;
	book->end = false;

	return (1);
}

int load_catalog(const char *filename, t_book *books)
{
	int fd;
	char *line = NULL;
	int count = 0;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (count < MAX_BOOKS && (line = get_next_line(fd)) != NULL)
	{
		if (*line)
		{
			if (parse_line(line, &books[count]))
				count++;
		}
		free(line);
	}
	close(fd);
	return (count);
}

void free_books(t_book *books, int count)
{
	for (int i = 0; i < count; i++)
	{
		if (books[i].title)
			free(books[i].title);
		if (books[i].author)
			free(books[i].author);
	}
}
