/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grade_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilani <igilani@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 22:02:16 by igilani           #+#    #+#             */
/*   Updated: 2025/06/11 23:37:48 by igilani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GRADE_MAP_H
# define GRADE_MAP_H

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef const char *(*GradeMapper)(int score);

void map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades);

# endif