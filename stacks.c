/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 13:50:04 by pcharlot          #+#    #+#             */
/*   Updated: 2020/02/23 17:23:46 by pcharlot         ###   ########.fr       */
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

void	print_stack(t_stack *st)
{
	t_stack	*temp;

	temp = st;
	while(temp)
	{
		printf("%d ", temp->nbr);
		temp = temp->next;
	}
}

void 	set_stack(t_data **data)
{
	t_stack *temp;
	temp = (*data)->a;

}