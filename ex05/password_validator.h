/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   password_validator.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilani <igilani@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 21:20:38 by igilani           #+#    #+#             */
/*   Updated: 2025/06/11 21:24:49 by igilani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PASSWORD_VALIDATOR_H
#define PASSWORD_VALIDATOR_H

#include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef enum {
	VALID,
	INVALID
} PwStatus;

PwStatus validate_password(const char *new_pw, const char *curr_pw);

#endif