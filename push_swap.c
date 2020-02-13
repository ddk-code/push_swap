/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:46:24 by pcharlot          #+#    #+#             */
/*   Updated: 2020/02/13 11:47:09 by pcharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_value_to_stack(t_stack **stack, int nbr)
{
	t_stack	*temp;

	temp = *stack;
	while (temp->next)
    {
	    temp->nbr = nbr;
	    temp = temp->next;
    }
}

void    set_stack()
{

}


int 	main(int argc, char **argv)
{
	char	*s;
	int		i;
	char	*sp;

	if (argc <= 1)
	{
		printf("Аргументов недостаточно");
		return (0);
	}
	s = malloc(0);
//	printf("len s = %d\n", ft_strlen(s));
//	s = ft_strjoin(s, argv[1]);
//	printf("s = %s\n", s);
//	printf("len s = %d\n", ft_strlen(s));

	i = 1;
	sp = malloc(2);
	sp[0] = ' ';
	sp[1] = '\0';
	while (argc > i)
	{
		s = ft_strjoin(s, argv[i]); ///все аргументы сливаем в одну строку
		s = ft_strjoin(s, sp); ///разделяем аргументы пробелом
		++i;
	}
	printf("s = %s\n", s);
}
