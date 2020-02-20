/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 14:29:37 by pcharlot          #+#    #+#             */
/*   Updated: 2020/02/19 13:37:05 by pcharlot         ###   ########.fr       */
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
/*	new->nbr = malloc(sizeof(int)); */ ///это нужно ???
	new->nbr = digit;
	new->next = *st;
	*st = new;
}

void	dell_top(t_stack **st)
{
	t_stack *temp;

	if (*st)
	{
		temp = *st;
		*st = (*st)->next;
		free(temp);
	}
}

void	add_new_down(t_stack **st, int digit)
{
	t_stack	*temp;
//	t_stack *prev;
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	ft_fatality(new);
	temp = *st;
	new->nbr = digit;
	new->next = NULL;

	while(temp->next)
	{
//		prev = temp;
		temp = temp->next;
	}
	temp->next = new;
}

void	dell_down(t_stack **st)
{
	t_stack	*temp;
	t_stack *prev;

	if (*st)
	{
		if ((*st)->next)
		{
			temp = *st;
			prev = *st;
			while (temp->next) {
				prev = temp;
				temp = temp->next;
			}
			prev->next = NULL;
			free(temp);
		}
		else
			{
			free(*st);
			*st = NULL; ///без этой строки ну просто трындец как все ломается =(
			}

	}
}

void	nachalo_detected(int *tab, int size)
{
	t_stack *st_a;
	t_stack *st_b;
	int i;

//	st_a = (t_stack *)malloc(sizeof(t_stack));
//	st_a->nbr = tab[0];
//	st_a->next = NULL;

	st_a = NULL;

//	st_b = (t_stack *)malloc(sizeof(t_stack));
//	st_b->next = NULL;
	st_b = NULL;
//	print_stack(st);
	i = 0;
	while (i < size)
	{
		add_new(&st_a, tab[i]);
		++i;
	}
	printf("\nstack a:\n");
	print_stack(st_a);

	printf("\nstack b:\n");
	print_stack(st_b);

//	dell_top(&st_a);
//	printf("\nDelTopA:\n");
//	print_stack(st_a);

//	printf("\nstack b:\n");
//	print_stack(st_b);

//	dell_top(&st_a);
//	printf("\nDelTopA:\n");
//	print_stack(st_a);
//
//	dell_top(&st_a);
//	printf("\nDelTopA:\n");
//	print_stack(st_a);
//
//	dell_top(&st_a);
//	printf("\nDelTopA:\n");
//	print_stack(st_a);

//	sa(&st_a);
//	printf("\nstack a after sa:\n");
//	print_stack(st_a);

//	pa(&st_a, &st_b);
//	printf("\n____pa____");
//
//	printf("\nstack a:\n");
//	print_stack(st_a);
//
//	printf("\nstack b:\n");
//	print_stack(st_b);

//	pb(&st_b, &st_a);
//	pb(&st_b, &st_a);
//	printf("\n____pb*2____");
//	printf("\nstack a:\n");
//	print_stack(st_a);
//	printf("\nstack b:\n");
//	print_stack(st_b);
//
//	pa(&st_a, &st_b);
//	pa(&st_a, &st_b);
//	printf("\nstack a:\n");
//	print_stack(st_a);
//
//	printf("\nstack b:\n");
//	print_stack(st_b);

//	add_new_down(&st_a, 1000);
//	printf("\nstack a after add_new_down:\n");
//	print_stack(st_a);
//
//	add_new(&st_a, -1000);
//	printf("\nstack a after add_new:\n");
//	print_stack(st_a);


//	ra(&st_a);
//	printf("\nstack a after ra:\n");
//	print_stack(st_a);

//	rb(&st_b);

//	dell_down(&st_a);
//	dell_down(&st_a);
//	dell_down(&st_a);
//	dell_down(&st_a);
//	dell_down(&st_a);
//	dell_down(&st_a);
//	dell_down(&st_a);
//	printf("\nstack a after dell_down:\n");
//	print_stack(st_a);



//	dell_top(&st_a);
//	dell_top(&st_a);
//	dell_top(&st_a);
//	dell_top(&st_a);
//	dell_top(&st_a);
//	dell_top(&st_a);
//	printf("\nstack a after dell_top:\n");
//	print_stack(st_a);


//	ra(&st_a);
//	printf("\nstack a after ra:\n");
//	print_stack(st_a);

//	rra(&st_a);
//	printf("\nstack a after rra:\n");
//	print_stack(st_a);



	sa(&st_a);
	pb(&st_b, &st_a);
	pb(&st_b, &st_a);
	pb(&st_b, &st_a);
	ra(&st_a);
	rb(&st_b);
	rra(&st_a);
	rrb(&st_b);
	sa(&st_a);
	pa(&st_a, &st_b);
	pa(&st_a, &st_b);
	pa(&st_a, &st_b);

	printf("\nstack a:\n");
	print_stack(st_a);

	printf("\nstack b:\n");
	print_stack(st_b);

	kuku(tab, size, &st_a, &st_b);

}