/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 17:18:08 by pcharlot          #+#    #+#             */
/*   Updated: 2020/02/23 17:18:48 by pcharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
typedef struct		s_data
{
	t_stack 		*a;
	t_stack 		*a_down;
	t_stack 		*b;
	t_stack 		*b_down;
	int 			*sort;
	int 			size;
	int				a_len;
	int 			b_len;
	int 			a_mid;
	int 			b_mid;
}					t_data;
*/

#include "push_swap.h"

static void	init_tdata(t_data **data)
{
	(*data)->a = malloc(sizeof(t_stack));
	(*data)->a = NULL;
	(*data)->a_down = malloc(sizeof(t_stack));
	(*data)->a_down = NULL;
	(*data)->b = malloc(sizeof(t_stack));
	(*data)->b = NULL;
	(*data)->b_down = malloc(sizeof(t_stack));
	(*data)->b_down = NULL;
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

	data = malloc(sizeof(t_data));
	init_tdata(&data);
	init_tab(s, &data);
//	print_tab(data->sort, data->size);
	sort_tab(&data->sort, data->size);
	print_tab(data->sort, data->size);
	printf("\n%d", data->size);




}