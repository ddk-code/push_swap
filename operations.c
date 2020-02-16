/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 14:28:22 by pcharlot          #+#    #+#             */
/*   Updated: 2020/02/16 17:57:23 by pcharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **st_a) ///swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
{
	t_stack	*temp;

	if (*st_a && (*st_a)->next)
	{
		temp = *st_a;
		*st_a = temp->next;
		temp->next = (*st_a)->next;
		(*st_a)->next = temp;
	}
}

void	sb(t_stack **st_b) ///swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
{
	t_stack	*temp;

	if (*st_b && (*st_b)->next)
	{
		temp = *st_b;
		*st_b = temp->next;
		temp->next = (*st_b)->next;
		(*st_b)->next = temp;
	}
}

