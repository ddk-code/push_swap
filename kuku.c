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
//void 	printab(int *t, int s);

void 	printab(int *t, int s)
{
	int i;

	i = 0;
	while(i < s)
	{
		printf("\n massiv: %d", t[i]);
		++i;
	}
	printf("\n");
}

void	swapi(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
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
	printab(tab, size);
	printab(sort, size);
}
