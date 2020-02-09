/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:46:24 by pcharlot          #+#    #+#             */
/*   Updated: 2020/02/04 16:46:25 by pcharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	main(int argc, char **argv)
{
	char	*s;

	if (argc <= 1)
	{
		printf("Аргументов недостаточно");
		return (0);
	}
	s = malloc(0);

	printf("len s = %d\n", ft_strlen(s));
	s = ft_strjoin(s, argv[1]);
	printf("s = %s\n", s);
	printf("len s = %d\n", ft_strlen(s));
	
}
