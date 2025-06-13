/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   food_order.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilani <igilani@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:07:52 by igilani           #+#    #+#             */
/*   Updated: 2025/06/13 11:34:04 by igilani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FOOD_ORDER_H
#define FOOD_ORDER_H

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct OrderRequest {
	char *restaurant_name; // Name of the restaurant
	char *order_details;    // Details of the food order
	int is_preorder;        // 1 if it's a pre-order, 0 if it's an immediate order
} OrderRequest;

typedef struct OrderConfirmation {
	char *confirmation_id; // Unique ID for the order confirmation
	char *message;         // Confirmation message
} OrderConfirmation;

// Checks if the restaurant is open based on the order. Returns 1 if open, 0 if closed.
int check_restaurant_status(struct OrderRequest *request);
// Creates a confirmation for an immediate order. Returns NULL on failure.
struct OrderConfirmation *create_standard_confirmation(void);
// Creates a confirmation for a future (pre-order). Returns NULL on failure.
struct OrderConfirmation *create_preorder_confirmation(void);
// Sends the confirmation to the user.
void send_confirmation_notification(struct OrderConfirmation *confirmation);

int process_food_order(struct OrderRequest *request);
void free_all(struct OrderRequest *request, struct OrderConfirmation *confirmation);

#endif