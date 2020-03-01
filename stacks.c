/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 13:50:04 by pcharlot          #+#    #+#             */
/*   Updated: 2020/03/01 18:01:21 by pcharlot         ###   ########.fr       */
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
	if (!temp)
		printf("\nstack: NULL");
	while(temp)
	{
		printf("\n\nnode: %d(%d) \n", temp->nbr, temp->i);
		if (temp->prev)
			printf("prev: %d(%d) ", temp->prev->nbr, temp->prev->i);
		else
			printf("prev: NULL ");
		if (temp->next)
			printf("next: %d(%d) ", temp->next->nbr, temp->next->i);
		else
			printf("next: NULL ");

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


void	ft_stackadd(t_stack *stack, t_stack *new)
{
	t_stack	*ptr;

	if (!(stack))
	{
		stack = new;
		new->prev = NULL;
		return ;
	}
	ptr = stack;
	while(ptr->next)
		ptr = ptr->next;
	ptr->next = new;
	new->prev = ptr;
}

void 	set_a(t_data *data)
{
	int		i;
	t_stack	*new;

	i  = 0;
	while (i < data->size)
	{
		new = init_node(data, data->tabb[i]);
		fatality(new);
		ft_stackadd(&data->a, new);
		++i;
	}
}

//void 	set_a(t_data *data) ///уточнить можно ли создать без инициализации корня
//{
//	int i;
//	t_stack *temp;
//	t_stack *prev;
//
//	data->a = init_node(data, data->tabb[0]);
//	prev = data->a;
//	i  = 1;
//	while (i < data->size)
//	{
//		temp = init_node(data, data->tabb[i]);
//		temp->prev = prev;
//		prev->next = temp;
//		++i;
//		prev = prev->next;
//	}
//}

