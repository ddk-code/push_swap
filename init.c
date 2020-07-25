/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 17:18:08 by pcharlot          #+#    #+#             */
/*   Updated: 2020/03/01 19:04:13 by pcharlot         ###   ########.fr       */
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
	struct s_stack	*prev;

}					t_stack;

*/

#include "push_swap.h"

static void	init_tdata(t_data *data)
{
	data->a = NULL;
	data->a_down = NULL;
	data->b = NULL;
	data->b_down = NULL;
	data->tabb = NULL;
	data->sort = NULL;
	data->size = 0;
	data->a_len = 0;
	data->b_len = 0;
	data->a_med = 0;
	data->b_med = 0;
}


void		nachalo_detected(char *s)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	init_tdata(data);
//	printf("%d %d %d %d %d", data->size, data->a_len, data->b_len, data->a_med, data->b_med);
	init_tab(s, data);

	free(s); ///можно фришить в мейнике/подумать

	print_tab(data->tabb, data->size);
	print_tab(data->sort, data->size);
//	printf("%d", data->size);
	set_a(data);
//	printf("%d\n", data->a->next->next->next->next->next->next->prev->prev->next->next->next->nbr);
//	printf("%d", data->a->next->next->next->next->next->next->next->sort_i);

//    printf("a: ");
//	print_stack(data->a);
//    printf("b: ");
//	print_stack(data->b);
//    sa(&data->a);
//    pb(&data->b, &data->a, data);
//    pb(&data->b, &data->a, data);
//    pb(&data->b, &data->a, data);
//    printf("a: ");
//    print_stack(data->a);
//    printf("b: ");
//    print_stack(data->b);

//    printf("max = %d min = %d", maxi(data->a), mini(data->a));
//    pb(&data->b, &data->a, data);
//    pb(&data->b, &data->a, data);
//    pb(&data->b, &data->a, data);
//    printf("max = %d min = %d", maxi(data->a), mini(data->a));
//    printf("max = %d min = %d", maxi(data->b), mini(data->b));


///	if (!check_stack(data->a)) ///чрезмерное на самом деле. Проверить. Убрать при необходимости
//	    go_calc(data);

//    printf("\na_len=%d a_med=%d b_len=%d b_med=%d", data->a_len, data->a_med, data->b_len, data->b_med);
//    pb(&data->b, &data->a, data);
//    printf("\na_len=%d a_med=%d b_len=%d b_med=%d", data->a_len, data->a_med, data->b_len, data->b_med);
//    printf("\na: ");
//    print_stack(data->a);
//    printf("b: ");
//    print_stack(data->b);

    printf("\nSIZE = %d\n", data->size);
    go_go(data);




}