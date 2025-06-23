/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilani <igilani@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:51:26 by igilani           #+#    #+#             */
/*   Updated: 2025/06/23 19:34:43 by igilani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARY_H
# define LIBRARY_H

# include "tha_supreme_lib/tha_supreme_lib.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
# define MAX_BOOKS 1000

typedef struct s_book
{
	int		id;
	char	*title;
	char	*author;
	char	*query;
	int		mode;
	bool	end;
}	t_book;

//------------ ui
int prompt_search_mode(t_book *library);
char *prompt_query(t_book *library);
void display_error(const char *msg);
void flush_stdin(void);

//------------ search
void search_by_title(t_book *books, int count, const char *query);
void search_by_author(t_book *books, int count, const char *query);

//------------ catalog
int load_catalog(const char *filename, t_book *books);
void free_books(t_book *books, int count);

//------------ print_ui
void print_ui();
void search_result_header();
void search_result_not_found();
void print_book(t_book *book);
void search_term();

#endif