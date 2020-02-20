/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kuku.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:21:55 by pcharlot          #+#    #+#             */
/*   Updated: 2020/02/19 13:38:34 by pcharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	swapi(int *a, int *b);
//void	kuku(int *tab, int size, t_stack **a, t_stack **b);
//void 	print_tab(int *t, int s);

void 	print_tab(int *t, int s)
{
	int i;

	i = 0;
	printf("\narray:");
	while(i < s)
	{
		printf(" %d", t[i]);
		++i;
	}
	printf("\n");
}

//void	swapi(int *a, int *b)
//{
//	int tmp;
//
//	tmp = *a;
//	*a = *b;
//	*b = tmp;
//}

int		pos(t_stack *st, int nbr)
{
	int 	i;
	t_stack *temp;

	i = 1;
	temp = st;
	while(temp)
	{
		if(temp->nbr != nbr)
			++i;
		else
			break ;
		temp = temp->next;
	}
	return (i);
}

void	kuku(int *tab, int size, t_stack **a, t_stack **b)
{
	int	sort[size];
	int i;

	i = 0;
	while(i < size)
	{
		sort[i] = tab[i];
		++i;
	}
	i = 0;
	while(i < size - 1)
	{
		if (sort[i] > sort[i + 1])
		{
			swapi(&sort[i], &sort[i + 1]);
			i = -1;
		}
		++i;
	}
    print_tab(tab, size);
    print_tab(sort, size);
	printf("\nposition of %d: %d", tab[5], pos(*a, tab[5]));
	printf("\nposition of %d: %d", tab[1], pos(*a, tab[1]));
	printf("\nposition of %d: %d", tab[0], pos(*a, tab[0]));

}
