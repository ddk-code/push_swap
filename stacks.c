/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 13:50:04 by pcharlot          #+#    #+#             */
/*   Updated: 2020/03/01 20:38:47 by pcharlot         ###   ########.fr       */
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
	int 			a_med;
	int 			b_med;
}					t_data;

 typedef struct		s_stack
{
	int				nbr;
	int 			sort_i;
	int 			flag;
	struct s_stack	*next;

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
		printf("\nnode: %d (%d: %d) \n", temp->nbr, temp->i, temp->sort_i);
//		if (temp->next)
//			printf("next: %d(%d) ", temp->next->nbr, temp->next->sort_i);
//		else
//			printf("next: NULL ");

		temp = temp->next;
	}
}

void	print_st(t_stack *st)
{
    t_stack	*temp;

    temp = st;
    if (!temp)
        printf("stack: NULL");
    while(temp)
    {
        printf("[%d] (№ %d:sorti %d)  ", temp->nbr, temp->i, temp->sort_i);
//		if (temp->next)
//			printf("next: %d(%d) ", temp->next->nbr, temp->next->sort_i);
//		else
//			printf("next: NULL ");

        temp = temp->next;
    }
    printf("\n");
}

void	printst(t_stack *st)
{
    t_stack	*temp;

    printf("\n");
    temp = st;
    if (!temp)
        printf("stack: NULL");
    while(temp)
    {
        printf("%d[%d]  ", temp->nbr, temp->sort_i);
//		if (temp->next)
//			printf("next: %d(%d) ", temp->next->nbr, temp->next->sort_i);
//		else
//			printf("next: NULL ");

        temp = temp->next;
    }
}

t_stack	*init_node(t_data *data, int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	fatality(new);
	new->next = NULL;
	new->nbr = value;
	new->sort_i = ind(data->sort, data->size, value);
    new->i = ind(data->tabb, data->size, value);
	new->flag = 0;
	return (new);
}

void 	set_a(t_data *data)
{
	int     i;
	t_stack *new;
	t_stack *temp;

//	data->a = init_node(data, data->tabb[0]);
//	temp = data->a;
//	sort_i  = 1;
	i = 0;
	while (i < data->size)
	{
		new = init_node(data, data->tabb[i]);
		if (!data->a)
			data->a = new;
		temp->next = new;
		++i;
		temp = temp->next;
	}
	data->a_len = data->size;
	data->b_len = 0;
}


//
//#include "push_swap.h"
//
//void	print_stack(t_stack *st)
//{
//	t_stack	*temp;
//
//	temp = st;
//	if (!temp)
//		printf("\nstack: NULL");
//	while(temp)
//	{
//		printf("\n\nnode: %d(%d) \n", temp->nbr, temp->sort_i);
//		if (temp->prev)
//			printf("prev: %d(%d) ", temp->prev->nbr, temp->prev->sort_i);
//		else
//			printf("prev: NULL ");
//		if (temp->next)
//			printf("next: %d(%d) ", temp->next->nbr, temp->next->sort_i);
//		else
//			printf("next: NULL ");
//
//		temp = temp->next;
//	}
//}
//
//t_stack	*init_node(t_data *data, int value)
//{
//	t_stack	*new;
//
//	new = (t_stack *)malloc(sizeof(t_stack));
//	fatality(new);
//	new->prev = NULL;
//	new->next = NULL;
//	new->nbr = value;
//	new->sort_i = ind(data->sort, data->size, value);
//	new->flag = 0;
//	return (new);
//}






//void	ft_stackadd(t_stack *stack, t_stack *new)
//{
//	t_stack	*ptr;
//
//	if (!(stack))
//	{
//		stack = new;
//		new->prev = NULL;
//		return ;
//	}
//	ptr = stack;
//	while(ptr->next)
//		ptr = ptr->next;
//	ptr->next = new;
//	new->prev = ptr;
//}
//
//void 	set_a(t_data *data)
//{
//	int		sort_i;
//	t_stack	*new;
//
//	sort_i  = 0;
//	while (sort_i < data->size)
//	{
//		new = init_node(data, data->tabb[sort_i]);
//		fatality(new);
//		ft_stackadd(&data->a, new);
//		++sort_i;
//	}
//}

//void 	set_a(t_data *data) ///уточнить можно ли создать без инициализации корня
//{
//	int sort_i;
//	t_stack *new;
//	t_stack *temp;
//
//	data->a = init_node(data, data->tabb[0]);
//	temp = data->a;
//	sort_i  = 1;
//	while (sort_i < data->size)
//	{
//		new = init_node(data, data->tabb[sort_i]);
//		new->prev = temp;
//		temp->next = new;
//		++sort_i;
//		temp = temp->next;
//	}
//}


