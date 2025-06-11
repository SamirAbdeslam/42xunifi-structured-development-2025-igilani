/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segmented_runs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilani <igilani@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 22:25:55 by igilani           #+#    #+#             */
/*   Updated: 2025/06/11 17:00:25 by igilani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "segmented_runs.h"

int count_segments(const int *arr, int size) {
	int start = 0;
	int end = 0;
	int len = 1;
	int found = 0;
	int count = 0;
	int i = 0;
	int j = 0;

	while (i < size)
	{
		while (i < size && arr[i] == -1)
			i++;
		start = i;
		while (i < size && arr[i] != -1)
			i++;
		end = i;
		j = start + 1;
		while (j < end)
		{
			if (arr[j] > arr[j - 1])
			{
				len++;
				if (len >= 3) {
					found = 1;
					break;
				}
			}
			else 
				len = 1;
			j++;
		}
		if (found)
			count++;
	}
	return (count);
}

// int main() {
// 	int array[] = {3, 2, 4, -1, 5, 6, 7, -1, 1, 2, 3, 4};
// 	int size = sizeof(array) / sizeof(array[0]);

// 	printf("%d\n", count_segments(array, size));
// 	return 0;
// }