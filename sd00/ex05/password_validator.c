/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   password_validator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilani <igilani@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 21:20:35 by igilani           #+#    #+#             */
/*   Updated: 2025/06/11 22:00:49 by igilani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "password_validator.h"

int ft_strlen(const char *s)
{
	int i = 0;

	if (!s)
		return (0);
	while (s[i])
		i++;
	return(i);
}

int ft_strcmp(const char *s1,const char *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
int ft_alphnum(const char *s)
{
	int i = 0;
	int j = 0;
	int found_num = 0;
	int found_upper = 0;
	int found_lower = 0;
	int found_special = 0;
	const char *special = "@#$%^&*";
	
	if (!s)
		return (0);
	while (s[i])
	{
		j = 0;
		if (s[i] >= '0' && s[i] <= '9' && found_num == 0)
			found_num = 1;
		if (s[i] >= 'a' && s[i] <= 'z' && found_lower == 0)
			found_lower = 1;
		if (s[i] >= 'A' && s[i] <= 'Z' && found_upper == 0)
			found_upper = 1;
		while (j < 7)
		{
			if (s[i] == special[j])
			{
				found_special = 1;
				break;
			}
			j++;
		}
		i++;
	}
	if (found_lower && found_upper && found_num && found_special)
		return (1);
	return(0);
}

PwStatus validate_password(const char *new_pw, const char *curr_pw)
{
	if (ft_strlen(new_pw) >= 8 && ft_alphnum(new_pw) && ft_strcmp(new_pw, curr_pw))
		return(VALID);
	return (INVALID);
}

// int main() {
//     const char *curr_pw[] = {
//         "OldPass123!",
//         "Something123@",
//         "Password@2024",
//         "StartHere1!",
//         "MyPass123@",
//         "Qwerty@123",
//         "Strong@123",
//         "Summer@2023",
//         "MyPass2023@"
//     };

//     const char *new_pw[] = {
//         "NewPass456@",
//         "S1@a",
//         "newpass123@",
//         "NEWPASS123@",
//         "MyPassword@",
//         "Qwerty1234",
//         "Strong@123",
//         "Winter#2024",
//         "MyNew^Pass1"
//     };

//     int num_tests = sizeof(curr_pw) / sizeof(curr_pw[0]);

//     for (int i = 0; i < num_tests; ++i) {
//         PwStatus result = validate_password(new_pw[i], curr_pw[i]);

//         printf(" Corrente: \"%s\"\n", curr_pw[i]);
//         printf(" Nuova:    \"%s\"\n", new_pw[i]);
//         printf(" Risultato: %s\n\n", result == VALID ? "VALIDA" : "NON VALIDA");
//     }

//     return 0;
// }
