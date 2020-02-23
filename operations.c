/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 17:14:32 by pcharlot          #+#    #+#             */
/*   Updated: 2020/02/23 17:15:21 by pcharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **st_a) ///swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
{
	t_stack	*temp;

	if (*st_a && (*st_a)->next)
	{
		temp = *st_a;
		*st_a = (*st_a)->next;
		temp->next = (*st_a)->next;
		(*st_a)->next = temp;
	}
	printf("sa ");
}

void	sb(t_stack **st_b) ///swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
{
	t_stack	*temp;

	if (*st_b && (*st_b)->next)
	{
		temp = *st_b;
		*st_b = (*st_b)->next;
		temp->next = (*st_b)->next;
		(*st_b)->next = temp;
	}
	printf("sb ");
}

void	pa(t_stack **st_a, t_stack **st_b) ///pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
{
	t_stack *temp;

	if(*st_b)
	{
		temp = *st_b;
		*st_b = (*st_b)->next;
		temp->next = *st_a;
		*st_a = temp;
	}
	printf("pa ");
}

void	pb(t_stack **st_b, t_stack **st_a) ///pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
{
	t_stack *temp;

	if(*st_a)
	{
		temp = *st_a;
		*st_a = (*st_a)->next;
		temp->next = *st_b;
		*st_b = temp;
	}
	printf("pb ");
}

void	ra(t_stack **st_a) ///ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
{
	t_stack	*temp;

	if(*st_a && (*st_a)->next)
	{
		temp = *st_a;
		while(temp->next)
			temp = temp->next;
		temp->next = *st_a;
		*st_a = (*st_a)->next;
		temp->next->next = NULL;
	}
	printf("ra ");
}

void	rb(t_stack **st_b) ///rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
{
	t_stack	*temp;

	if(*st_b && (*st_b)->next)
	{
		temp = *st_b;
		while(temp->next)
			temp = temp->next;
		temp->next = *st_b;
		*st_b = (*st_b)->next;
		temp->next->next = NULL;
	}
	printf("rb ");
}

void	rra(t_stack **st_a) ///reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
{
	t_stack	*temp;
	t_stack *prev;

	if (*st_a && (*st_a)->next)
	{
		temp = *st_a;
		prev = *st_a;
		while (temp->next)
		{
			prev = temp;
			temp = temp->next;
		}
		prev->next = NULL;
		temp->next = *st_a;
		*st_a = temp;
	}
	printf("rra ");
}

void	rrb(t_stack **st_b) ///reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
{
	t_stack	*temp;
	t_stack *prev;

	if (*st_b && (*st_b)->next)
	{
		temp = *st_b;
		prev = *st_b;
		while (temp->next)
		{
			prev = temp;
			temp = temp->next;
		}
		prev->next = NULL;
		temp->next = *st_b;
		*st_b = temp;
	}
	printf("rrb ");
}

