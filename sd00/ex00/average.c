/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   average.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilani <igilani@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:45:46 by igilani           #+#    #+#             */
/*   Updated: 2025/06/11 17:57:32 by igilani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "average.h"

float average(const int *arr, int size)
{
	int i = 0;
	int sum = 0;
	int div = size;

	while (i < size)
	{
		if (arr[i] >= 0 && arr[i] <= 100)
		{
			sum += arr[i];
			i++;
		}
		else
		{
			div--;
			i++;
		}
	}
	return ((float)sum / div);
}

// int main()
// {
// 	const int *arr = (int[]){1, 2, 3, 4, 200};
// 	int size = 5;
// 	float avg = average(arr, size);
// 	printf("Average: %.2f\n", avg);
// 	return 0;
// }