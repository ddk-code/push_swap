/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:46:24 by pcharlot          #+#    #+#             */
/*   Updated: 2020/02/15 19:03:30 by pcharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	set_value_to_stack(t_stack **stack, int nbr)
//{
//	t_stack	*temp;
//
//	temp = *stack;
//	while (temp->next)
//    {
//	    temp->nbr = nbr;
//	    temp = temp->next;
//    }
//}

void	check_chars(char *s) ///если есть что-то, кроме цифр/знаков/пробелов - выдает ошибку
{
	int i;

	i = 0;
	while(s[i])
	{
		if(ft_isspace(s[i]) || s[i] == '-' || s[i] == '+' || is_digit09(s[i]))
			++i;
		else
		{
			write(2, "Error: among the supplied values there are non-integer numbers.", 63);
			exit (0);
		}
	}
}

int intnum(char *s) ///подсчитывает количество цифр в строке, если количество цифр 0 - выдает ошибку
{
	int i;
	int dig_numbers;

	i = 0;
	dig_numbers = 0;
	while(s[i])
	{
		if(is_digit09(s[i]) && (ft_isspace(s[i + 1]) || s[i + 1] == '\0'))
			++dig_numbers;
		++i;
	}
	if (dig_numbers == 0)
	{
		write(2, "Error: passed values are not integer.", 37);
		exit (0);
	}
	return (dig_numbers);
}

int *ft_tab(char *s) ///собирает массив интов, состоящий из переданных аргументов
{
	int size;
	int *tab;
	int i;
	int j;

	j = 0;
	i = 0;
	size = intnum(s);
	tab = malloc(sizeof(int) * size);
	while (j < size)
	{
		tab[j] = atosh(s, &i);
		if (!ft_isspace(s[i]))
		{
			write(2, "Error: among the supplied values there are non-integer numbers!", 63); ///Испавить воскл знак
			exit (0);
		}
		++j;
	}
	return (tab);
}

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
//	printf("\ns:%s\n", s);
//	printf("ints: %d\n", intnum(s));


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

	return (0);
}
