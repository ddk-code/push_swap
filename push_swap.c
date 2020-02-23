/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 12:08:29 by pcharlot          #+#    #+#             */
/*   Updated: 2020/02/23 19:14:11 by pcharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_argv(char *s)
{
	int i;
	int checker;

	i = 0;
	checker = 0;
	while(s[i])
	{
		if(is09(s[i]))
			++checker;
		++i;
	}
	if (checker == 0)
	{
		write(2, "Error_2: there are no digits at least in one argument.", 54); ///проверка каждого аргв перед склейкой в общую строку. Если цифры вообще отсутствуют - выдает ошибку
		exit (0);
	}
}

int			main(int argc, char **argv)
{
	char	*s;
	int		i;
	char	*space;

	if (argc <= 1)
	{
		write(2, "Error_1: not enough arguments.", 30);
		return (0);
	}
	s = (char *)malloc(sizeof(char));
	s[0] = '\0';
//	printf("len s = %d\n", ft_strlen(s));
//	s = ft_strjoin(s, argv[1]);
//	printf("s = %s\n", s);
//	printf("len s = %d\n", ft_strlen(s));

	i = 1;
	space = (char *)malloc(sizeof(char) * 2);
	space[0] = ' ';
	space[1] = '\0';
	while (argc > i)
	{
		check_argv(argv[i]);
		s = joinfree(s, argv[i]); ///все аргументы сливаем в одну строку
		s = joinfree(s, space); ///разделяем аргументы пробелом
		++i;
	}
	free(space);
//	printf("\ns:  [%s]\n", s);
//	printf("ints: %d\n\n", int_count(s));
	nachalo_detected(s);
	free(s);







//
//	int *tab;
//	i = 0;
//	tab = ft_tab(s);
//	while (i < int_count(s))
//	{
//		printf("%d\n", tab[i]);
//		++i;
//	}

//	printf("%d\n", tab[0]);
//	printf("%d\n", tab[1]);
//	printf("%d\n", tab[2]);



//	printf("ints: %d\n", int_count(s));

//	printf("%d: %d\n", -156, ft_digcount(-156));
//	printf("%d: %d\n", 0, ft_digcount(0));


//	char *inmi = "-2147483649";
//	char *inma = "2147483647";
//	printf("%ld\n", ft_atoi(inmi));
//	printf("%ld\n", ft_atoi(inma));

//	nachalo_detected(tab, int_count(s));
//	t_stack *st;
//	st = NULL;




	return (0);
}

