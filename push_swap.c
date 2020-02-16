/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:46:24 by pcharlot          #+#    #+#             */
/*   Updated: 2020/02/16 12:11:16 by pcharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	main(int argc, char **argv)
{
	char	*s;
	int		i;
	char	*sp;

	if (argc <= 1)
	{
		write(2, "Error: not enough arguments.", 28);
		return (0);
	}
	s = malloc(1);
	s[0] = '\0';
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
		check_argv(argv[i]);
		s = ft_strjoin(s, argv[i]); ///все аргументы сливаем в одну строку
		s = ft_strjoin(s, sp); ///разделяем аргументы пробелом
		++i;
	}
	printf("\ns:%s\n", s);
	printf("ints: %d\n", intnum(s));


	int *tab;
	i = 0;
	tab = ft_tab(s);
	while (i < intnum(s))
	{
		printf("%d\n", tab[i]);
		++i;
	}

//	printf("%d\n", tab[0]);
//	printf("%d\n", tab[1]);
//	printf("%d\n", tab[2]);



//	printf("ints: %d\n", intnum(s));

//	printf("%d: %d\n", -156, ft_digcount(-156));
//	printf("%d: %d\n", 0, ft_digcount(0));


//	char *inmi = "-2147483649";
//	char *inma = "2147483647";
//	printf("%ld\n", ft_atoi(inmi));
//	printf("%ld\n", ft_atoi(inma));

	t_stack *st;
	st = NULL;

	return (0);
}
