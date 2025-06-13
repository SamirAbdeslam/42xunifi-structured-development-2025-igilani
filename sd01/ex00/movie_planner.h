/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movie_planner.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilani <igilani@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:40:10 by igilani           #+#    #+#             */
/*   Updated: 2025/06/13 11:09:33 by igilani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVIE_PLANNER_H
#define MOVIE_PLANNER_H

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct Preferences
{
	char *genre;
	int min_rating;
	int max_duration; // in minutes
} Preferences;

typedef struct Movie
{
	char *title;
	char *genre;
	int rating; // out of 10
	int duration; // in minutes
} Movie;

typedef struct MovieList
{
	Movie *movies;
	size_t count;
} MovieList;

typedef struct Plan
{
	Movie *selected_movies;
	size_t count;
} Plan;

// Returns user preferences. Returns NULL on failure.
struct Preferences *get_user_preferences(void);
// Returns a list of movies matching the given preferences. Returns NULL on failure.
struct MovieList *find_movies(struct Preferences *prefs);
// Returns a movie night plan from the given list. Returns NULL on failure.
struct Plan *build_plan(struct MovieList *list);

struct Plan *create_movie_night_plan(void);
void free_all(struct Preferences *prefs, struct MovieList *movies, struct Plan *plan);

#endif