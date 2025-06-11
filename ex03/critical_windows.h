/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   critical_windows.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilani <igilani@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:01:00 by igilani           #+#    #+#             */
/*   Updated: 2025/06/11 17:02:03 by igilani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CRITICAL_WINDOWS_H
# define CRITICAL_WINDOWS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int count_critical_windows(const int *readings, int size);

# endif