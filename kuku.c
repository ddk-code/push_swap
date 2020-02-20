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
	int temp;

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
	printf("\nposition of %d: %d", tab[3], pos(*a, tab[3]));

	i = 0;
	temp = 0;
	while (i < size)
	{
		if (pos(*a, sort[i]) == 1)
			pb(b, a);
		else if (pos(*a, sort[i]) == 2)
		{
			sa(a);
			pb(b, a);
		}
		else if (pos(*a, sort[i]) <= (int)(size / 2))
		{
			temp = pos(*a, sort[i]) - 1;
			while(temp > 0)
			{
				ra(a);
				--temp;
			}
			pb(b, a);
		}
		else if (pos(*a, sort[i]) > (int)(size / 2))
		{
			temp = pos(*a, sort[i]) - 1;
			while(temp > 0)
			{
				rra(a);
				--temp;
			}
			pb(b, a);
		}
		++i;
	}
	printf("\nstack a after sorting:\n");
	print_stack(*a);

	printf("\nstack b after sorting:\n");
	print_stack(*b);
	i = 0;
	while (i < size)
	{
		pa(a, b);
		++i;
	}
	printf("\n");
	printf("\nstack a at final:\n");
	print_stack(*a);

	printf("\nstack b at final:\n");
	print_stack(*b);

}
