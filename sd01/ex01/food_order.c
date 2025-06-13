/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   food_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilani <igilani@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:07:54 by igilani           #+#    #+#             */
/*   Updated: 2025/06/13 11:19:55 by igilani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "food_order.h"

void free_all(struct OrderRequest *request, struct OrderConfirmation *confirmation)
{
	if (request)
	{
		free(request->restaurant_name);
		free(request->order_details);
		free(request);
	}
	if (confirmation)
	{
		free(confirmation->confirmation_id);
		free(confirmation->message);
		free(confirmation);
	}
}

int process_food_order(struct OrderRequest *request)
{
	int status;
	OrderConfirmation *confirmation;
	
	if (!request || !request->restaurant_name || !request->order_details)
		return -1;
	status = check_restaurant_status(request);

	if (status == 0)
	{
		confirmation = create_preorder_confirmation();
		if (!confirmation)
		{
			free_all(request, NULL);
			return -1;
		}
	}
	else if (status == 1)
	{
		confirmation = create_standard_confirmation();
		if (!confirmation)
		{
			free_all(request, NULL);
			return -1;
		}
	}
	else
	{
		free_all(request, NULL);
		return -1;
	}
	send_confirmation_notification(confirmation);
	free_all(request, confirmation);
	return 0;
}