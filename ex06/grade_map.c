/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grade_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilani <igilani@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 22:02:04 by igilani           #+#    #+#             */
/*   Updated: 2025/06/11 23:40:23 by igilani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grade_map.h"

const char *plusminus_mapper(int score) {
    if (score >= 97) return "A+";
    else if (score >= 93) return "A";
    else if (score >= 90) return "A-";
    else if (score >= 87) return "B+";
    else if (score >= 83) return "B";
    else if (score >= 80) return "B-";
    else if (score >= 77) return "C+";
    else if (score >= 73) return "C";
    else if (score >= 70) return "C-";
    else if (score >= 67) return "D+";
    else if (score >= 63) return "D";
    else if (score >= 60) return "D-";
    else return "F";
}

const char *passfail_mapper(int score) {
    if (score >= 60) return "P";
    else return "F";
}

const char *standard_mapper(int score) {
    if (score >= 90) return "A";
    else if (score >= 80) return "B";
    else if (score >= 70) return "C";
    else if (score >= 60) return "D";
    else return "F";
}

void map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades)
{
	for (int i = 0; i < size; i++)
	{
		mapped_grades[i] = mapper(scores[i]);
	}
}

// int main()
// {
// 	int scores[] = {85, 92, 70, 60, 55};
// 	const char *mapped[5];
//     int i = 0;

// 	map_scores(scores, 5, plusminus_mapper, mapped);
    
//     while (i < 5)
//     {
//         printf("%s\n", mapped[i]);
//         i++;
//     }
// }