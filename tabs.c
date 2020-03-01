/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:20:29 by pcharlot          #+#    #+#             */
/*   Updated: 2020/03/01 13:22:18 by pcharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_tab(int *tab, int size)
{
	int i;

	i = 0;
	printf("\narray:");
	while(i < size)
	{
		printf(" %d", tab[i]);
		++i;
	}
	printf("\n");
}

void	sort_tab(int *tab, int size)
{
	int i;
//	int *temp;

//	temp = *tab;
	i = 0;
	while(i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			swapi(&tab[i], &tab[i + 1]);
			i = -1;
		}
		++i;
	}
}

int		ind(int *tab, int size, int value)
{
	int i;

	i = 0;
	while(i < size)
	{
		if (tab[i] == value)
			break ;
		++i;
	}
	return (i + 1);
}