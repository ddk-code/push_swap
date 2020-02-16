/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 14:29:37 by pcharlot          #+#    #+#             */
/*   Updated: 2020/02/16 16:31:07 by pcharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *st)
{
	t_stack	*temp;

	temp = st;
	while(temp)
	{
		printf("%d\n", temp->nbr);
		temp = temp->next;
	}
}

void	add_new(t_stack **st, int digit)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	ft_fatality(new);
//	new->nbr = malloc(sizeof(int)); ///это нужно ???
	new->nbr = digit;
	new->next = *st;
	*st = new;
}

void	dell_top(t_stack **st)
{
	t_stack *temp;

	temp = *st;
	*st = (*st)->next;
	free(temp);
}

void	nachalo_detected(int *tab, int size)
{
	t_stack *st_a;
	t_stack *st_b;
	int i;

	st_a = (t_stack *)malloc(sizeof(t_stack));
	st_a->nbr = tab[0];
	st_a->next = NULL;
	st_b = (t_stack *)malloc(sizeof(t_stack));
	st_b->next = NULL;
//	print_stack(st);
	i = 1;
	while (i < size)
	{
		add_new(&st_a, tab[i]);
		++i;
	}
	printf("\nstack a:\n");
	print_stack(st_a);
	dell_top(&st_a);
	printf("\nDelTopA:\n");
	print_stack(st_a);
}