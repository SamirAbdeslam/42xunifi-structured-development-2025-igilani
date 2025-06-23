/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilani <igilani@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:42:58 by apeero            #+#    #+#             */
/*   Updated: 2025/06/23 19:32:33 by igilani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int prompt_search_mode(t_book *library)
{
	char *line;
	int choice = 0;
	bool valid_choice = false;

	while (!library->end && !valid_choice)
	{
		print_ui();
		line = get_next_line(STDIN_FILENO);
		if (line)
		{
			char *trimmed = ft_strtrim(line, " \t\n\v\f\r");
			free(line);
			if (trimmed)
			{
				if (ft_strlen(trimmed) == 1 && (trimmed[0] == '1' || trimmed[0] == '2' || trimmed[0] == '3'))
				{
					choice = trimmed[0] - '0';
					valid_choice = true;
					if (choice == 3)
						library->end = true;
				}
				else
				{
					ft_printf("\nInvalid input. Please enter 1, 2, or 3.\n");
				}
				free(trimmed);
			}
		}
	}
	return choice;
}

char *prompt_query(t_book *library)
{
	char *line;
	char *trimmed = NULL;
	char *result = NULL;

	while (!library->end && !result)
	{
		search_term();
		line = get_next_line(STDIN_FILENO);
		if (line)
		{
			trimmed = ft_strtrim(line, " \t\n\v\f\r");
			free(line);
			if (trimmed && *trimmed)
			{
				result = trimmed;
			}
		}
	}
	return result;
}
