/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 13:50:04 by pcharlot          #+#    #+#             */
/*   Updated: 2020/03/01 14:10:35 by pcharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
typedef struct		s_data
{
	t_stack 		*a;
	t_stack 		*a_down;
	t_stack 		*b;
	t_stack 		*b_down;
	int 			*tabb;
	int 			*sort;
	int 			size;
	int				a_len;
	int 			b_len;
	int 			a_mid;
	int 			b_mid;
}					t_data;

 typedef struct		s_stack
{
	int				nbr;
	int 			i;
	int 			flag;
	struct s_stack	*next;
	struct s_stack	*prev;

}					t_stack;

*/

#include "push_swap.h"

void	print_stack(t_stack *st)
{
	t_stack	*temp;

	temp = st;
	while(temp)
	{
		printf("%d(%d) ", temp->nbr, temp->i);
		temp = temp->next;
	}
}

t_stack	*init_node(t_data *data, int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	fatality(new);
	new->prev = NULL;
	new->next = NULL;
	new->nbr = value;
	new->i = ind(data->sort, data->size, value);
	new->flag = 0;
	return (new);

}

void 	set_a(t_data **data)
{
	int i;
	t_stack *temp;

	(*data)->a = init_node(*data, (*data)->tabb[0]);
	temp = (*data)->a;
	i  = 1;

}