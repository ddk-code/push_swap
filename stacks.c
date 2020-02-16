/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 14:29:37 by pcharlot          #+#    #+#             */
/*   Updated: 2020/02/16 15:18:10 by pcharlot         ###   ########.fr       */
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

void	nachalo_detected(int *tab, int size)
{
	t_stack *st;
	int i;

	st = (t_stack *)malloc(sizeof(t_stack));
	st->nbr = tab[0];
	st->next = NULL;
//	print_stack(st);
	i = 1;
	while (i < size)
	{
		add_new(&st, tab[i]);
		++i;
	}
	printf("\nstack:\n");
	print_stack(st);

}