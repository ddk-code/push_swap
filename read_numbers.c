/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 11:13:21 by pcharlot          #+#    #+#             */
/*   Updated: 2020/02/16 13:31:47 by pcharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	check_chars(char *s);
//int 	intnum(char *s);
//void	check_tab(int *tab, int size);
//int		*ft_tab(char *s);

void	check_zero(char *s)
{
	int i;
	int zs;

	i = 0;
	while(s[i])
	{
		zs = 0;
		if(s[i] == '0')
		{
			while (s[i] && s[i] == '0')
			{
				++i;
				++zs;
			}
			if (zs > 1 && (ft_isspace(s[i]) || s[i] == '\0'))
			{
				write(2, "Error: ноль представлен несколькими нолями.", 75);
				exit (0);
			}
			--i;
		}
		++i;
	}
}

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
			write(2, "Error: среди переданных данных имеются не числа либо представленные не в десятичной системе счисления.", 184);
			exit (0);
		}
	}
	check_zero(s);
}

int intnum(char *s) //подсчитывает количество цифр в строке, если количество цифр 0 - выдает ошибку
{
	int i;
	int dig_numbers;

	i = 0;
	dig_numbers = 0;
	while(s[i])
	{
		if(is_digit09(s[i]) && (ft_isspace(s[i + 1]) || s[i + 1] == '\0'))
			++dig_numbers;
		if(is_digit09(s[i]) && !(is_digit09(s[i + 1]) || ft_isspace(s[i + 1]) || s[i + 1] == '\0')) ///если после цифры идет что-то, отличное от цифры или пробела или \0 - ошибка!!!
		{
			write(2, "Error: некорректное продолжение числа.", 66);
			exit(0);
		}
		++i;
	}
	if (dig_numbers == 0)
	{
		write(2, "Error: passed values are not integer.", 37); ///Вариант, когда строка состоит только символов + - и пробелов
		exit (0);
	}
	return (dig_numbers);
}

void	check_tab(int *tab, int size)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (size - i > 0)
	{
		j = i + 1;
		tmp = tab[i];
		while(size - j > 0)
		{
			if(tmp != tab[j])
				++j;
			else
			{
				write(2, "Error: среди переданных чисел есть одинаковые.", 80);
				exit (0);
			}
		}
		++i;
	}
}

int *ft_tab(char *s) ///собирает массив интов, состоящий из переданных аргументов, если есть некорректные числа/сборные числа - выдает ошибку
{
	int size;
	int *tab;
	int i;
	int j;

	j = 0;
	i = 0;
	check_chars(s);
	size = intnum(s);
	tab = malloc(sizeof(int) * size);
	while (j < size)
	{
		tab[j] = atosh(s, &i);
		if (!ft_isspace(s[i]))
		{
			write(2, "Error: среди переданных чисел есть некорректные!", 84); /// Тут вариант чисел, когда внутри цифр есть +/- Другие варианты отсеиваются при проверке символов по строке
			exit (0);
		}
		++j;
	}
	check_tab(tab, size);
	return (tab);
}

