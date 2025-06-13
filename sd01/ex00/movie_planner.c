/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movie_planner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilani <igilani@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:40:15 by igilani           #+#    #+#             */
/*   Updated: 2025/06/13 11:07:28 by igilani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movie_planner.h"

void free_all(struct Preferences *prefs, struct MovieList *movies, struct Plan *plan)
{
	if (prefs)
	{
		free(prefs->genre);
		free(prefs);
	}
	if (movies)
	{
		for (size_t i = 0; i < movies->count; i++)
		{
			free(movies->movies[i].title);
			free(movies->movies[i].genre);
		}
		free(movies->movies);
		free(movies);
	}
	if (plan)
	{
		for (size_t i = 0; i < plan->count; i++)
		{
			free(plan->selected_movies[i].title);
			free(plan->selected_movies[i].genre);
		}
		free(plan->selected_movies);
		free(plan);
	}
}

struct Plan *create_movie_night_plan(void)
{
	struct Preferences *prefs = get_user_preferences();
	if (!prefs)
	{
		fprintf(stderr, "Error: Could not get user preferences.\n");
		return NULL;
	}

	struct MovieList *movies = find_movies(prefs);
	if (!movies)
	{
		fprintf(stderr, "Error: No movies found matching preferences.\n");
		free_all(prefs, NULL, NULL);
		return NULL;
	}

	struct Plan *plan = build_plan(movies);
	if (!plan)
	{
		fprintf(stderr, "Error: Could not build movie night plan.\n");
		free_all(prefs, movies, NULL);
		return NULL;
	}
	return plan;
}