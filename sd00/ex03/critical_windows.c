/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   critical_windows.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilani <igilani@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:01:03 by igilani           #+#    #+#             */
/*   Updated: 2025/06/13 10:39:12 by igilani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "critical_windows.h"

static float average(const int *arr, int size)
{
	int i = 0;
	int sum = 0;
	int div = size;

	while (i < size)
	{
		if (arr[i] >= 0 && arr[i] <= 150)
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

static int parsing_value(const int *readings, int size)
{
	int i = 0;
	int count = 0;

	while (i < size)
	{
		if (readings[i] > 150)
			return(1);
		if (readings[i] < 70)
			count++;
		i++;
	}
	if (count >= 3)
		return (1);
	return (0);
}

int count_critical_windows(const int *readings, int size)
{
	int count = 0;
	int i = 0;

	while (i < size - 4)
	{
		if (average(&readings[i], 5) >= 90 && parsing_value(&readings[i], 5) == 0)
			count++;
		i++;
	}
	return (count);
}

// int main() {
//     // Test 1: Caso dato in precedenza
//     int readings1[] = {100, 120, 95, 70, 65};
//     int size1 = 5;
//     printf("Test 1: %d finestre critiche\n", count_critical_windows(readings1, size1));

//     // // Test 2: Tutti sotto i 70
//     // int readings2[] = {60, 50, 40, 65, 69, 55, 68};
//     // int size2 = sizeof(readings2) / sizeof(readings2[0]);
//     // printf("Test 2: %d finestre critiche\n", count_critical_windows(readings2, size2));

//     // // Test 3: Tutti sopra i 70, nessuno oltre 150, ma media bassa
//     // int readings3[] = {70, 71, 72, 73, 74, 75, 76};
//     // int size3 = sizeof(readings3) / sizeof(readings3[0]);
//     // printf("Test 3: %d finestre critiche\n", count_critical_windows(readings3, size3));

//     // // Test 4: Tutte le condizioni soddisfatte, molte finestre critiche
//     // int readings4[] = {100, 120, 95, 98, 105, 110, 115, 108, 102, 101};
//     // int size4 = sizeof(readings4) / sizeof(readings4[0]);
//     // printf("Test 4: %d finestre critiche\n", count_critical_windows(readings4, size4));

//     // // Test 5: Un valore > 150 rovina tutte le finestre
//     // int readings5[] = {100, 120, 151, 98, 105, 110, 115};
//     // int size5 = sizeof(readings5) / sizeof(readings5[0]);
//     // printf("Test 5: %d finestre critiche\n", count_critical_windows(readings5, size5));

//     // // Test 6: Array troppo corto (<5 elementi)
//     // int readings6[] = {100, 110, 120};
//     // int size6 = sizeof(readings6) / sizeof(readings6[0]);
//     // printf("Test 6: %d finestre critiche\n", count_critical_windows(readings6, size6));

//     return 0;
// }
