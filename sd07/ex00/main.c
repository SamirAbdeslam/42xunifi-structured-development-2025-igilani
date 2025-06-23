/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilani <igilani@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:37:17 by apeero            #+#    #+#             */
/*   Updated: 2025/06/23 18:19:23 by igilani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void display_error(const char *msg)
{
    ft_printf("Error: %s\n", msg);
}

int main(int argc, char **argv)
{
	t_book books[MAX_BOOKS];
	int count;
	int mode;
	char *query;

	if (argc != 2)
	{
		display_error("Usage: ./library <catalog_file>");
		return (1);
	}

	count = load_catalog(argv[1], books);
	if (count < 0)
	{
		display_error("Failed to open catalog file.");
		return (1);
	}

	books[0].end = false;  // Initialize the end flag
	
	while (!books[0].end)
	{
		mode = prompt_search_mode(books);
		books[0].mode = mode;
		
		if (mode == 1 || mode == 2)
		{
			query = prompt_query(books);
			if (query && !books[0].end)
			{
				books[0].query = query;
				if (mode == 1)
					search_by_title(books, count, query);
				else
					search_by_author(books, count, query);
				free(query);
			}
		}
		else if (mode == 3)
		{
			ft_printf("Exiting...\n");
			books[0].end = true;
		}
	}
	
	free_books(books, count);
	return (0);
}
