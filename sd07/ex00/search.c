/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilani <igilani@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:41:38 by apeero            #+#    #+#             */
/*   Updated: 2025/06/23 18:53:12 by igilani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

static int str_contains_case_insensitive(const char *haystack, const char *needle)
{
	int i, j;
	bool found = false;

	if (!needle || !haystack)
		return (0);

	i = 0;
	while (haystack[i] && !found)
	{
		j = 0;
		while (needle[j] && haystack[i + j] && ft_tolower(haystack[i + j]) == ft_tolower(needle[j]))
		{
			j++;
		}
		if (needle[j] == '\0')
			found = true;
		else
			i++;
	}
	if (found)
		return (1);
	else
		return (0);
}

void search_by_title(t_book *books, int count, const char *query)
{
	int found = 0;

	search_result_header();
	for (int i = 0; i < count; i++)
	{
		if (str_contains_case_insensitive(books[i].title, query))
		{
			print_book(&books[i]);
			found = 1;
		}
	}
	if (!found)
		search_result_not_found();
}

void search_by_author(t_book *books, int count, const char *query)
{
	int found = 0;

	search_result_header();
	for (int i = 0; i < count; i++)
	{
		if (str_contains_case_insensitive(books[i].author, query))
		{
			print_book(&books[i]);
			found = 1;
		}
	}
	if (!found)
		search_result_not_found();
}
