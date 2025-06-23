/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilani <igilani@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 18:48:37 by igilani           #+#    #+#             */
/*   Updated: 2025/06/23 18:54:40 by igilani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void print_ui()
{
	ft_printf("\n╔══════════════════════════════════╗\n");
	ft_printf("║        Digital Library           ║\n");
	ft_printf("╠══════════════════════════════════╣\n");
	ft_printf("║  Search Options:                 ║\n");
	ft_printf("║  [1] Search by Title             ║\n");
	ft_printf("║  [2] Search by Author            ║\n");
	ft_printf("║  [3] Exit                        ║\n");
	ft_printf("╚══════════════════════════════════╝\n");
	ft_printf("Enter your choice (1-3): ");
}

void search_result_header()
{
	ft_printf("\n╔═══════════════════════════════════════════════╗\n");
	ft_printf("║              SEARCH RESULTS                   ║\n");
	ft_printf("╚═══════════════════════════════════════════════╝\n");
}

void search_result_not_found()
{
	ft_printf("┌─────────────────────────────────────────────┐\n");
	ft_printf("│           No matching books found.          │\n");
	ft_printf("└─────────────────────────────────────────────┘\n");
}

void search_term()
{
	ft_printf("\n┌─────────────────────────────────┐\n");
	ft_printf("│  Enter search term below:       │\n");
	ft_printf("└─────────────────────────────────┘\n");
	ft_printf("Search: ");
}

void print_book(t_book *book)
{
	ft_printf("──────────────────────────────────────────────────────\n");
	ft_printf("ID: %d \n", book->id);
	ft_printf("Title: %s \n", book->title);
	ft_printf("Author: %s \n", book->author);
	ft_printf("──────────────────────────────────────────────────────\n");
}