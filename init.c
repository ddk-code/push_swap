/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 17:18:08 by pcharlot          #+#    #+#             */
/*   Updated: 2020/03/01 15:06:11 by pcharlot         ###   ########.fr       */
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

static void	init_tdata(t_data **data)
{
//	(*data)->a = malloc(sizeof(t_stack));
	(*data)->a = NULL;
//	(*data)->a_down = malloc(sizeof(t_stack));
	(*data)->a_down = NULL;
//	(*data)->b = malloc(sizeof(t_stack));
	(*data)->b = NULL;
//	(*data)->b_down = malloc(sizeof(t_stack));
	(*data)->b_down = NULL;
	(*data)->tabb = NULL;
	(*data)->sort = NULL;
	(*data)->size = 0;
	(*data)->a_len = 0;
	(*data)->b_len = 0;
	(*data)->a_mid = 0;
	(*data)->b_mid = 0;
}

void		nachalo_detected(char *s)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	init_tdata(&data);
	init_tab(s, &data);
	free(s); ///можно фришить в мейнике/подумать
	print_tab(data->tabb, data->size);
	print_tab(data->sort, data->size);
//	printf("%d", data->size);
	set_a(&data);
//	printf("%d\n", data->a->next->next->next->next->next->next->next->nbr);
//	printf("%d", data->a->next->next->next->next->next->next->next->i);
	print_stack(data->a);
	print_stack(data->b);






}