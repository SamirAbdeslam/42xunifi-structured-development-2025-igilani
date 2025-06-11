/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilani <igilani@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:59:32 by igilani           #+#    #+#             */
/*   Updated: 2025/06/10 22:24:10 by igilani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "first_last.h"

void first_last(int arr[], int size, int target, int *first, int *last)
{
	int i = 0;
	*first = -1;
	*last = -1;

	while (i < size)
	{
		if (arr[i] == target)
		{
			if (*first == -1)
				*first = i;
			*last = i;
		}
		i++;
	}
}

// int main() {
// 	int array[] = {5, 3, 7, 3, 9, 3, 2};
// 	int size = sizeof(array) / sizeof(array[0]);
// 	int target = 3;
// 	int first, last;

// 	first_last(array, size, target, &first, &last);

// 	printf("First: %d, Last: %d\n", first, last);

// 	return 0;
// }
