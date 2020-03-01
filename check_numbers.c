/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 13:57:44 by pcharlot          #+#    #+#             */
/*   Updated: 2020/03/01 17:46:45 by pcharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_chars(char *s) ///если есть что-то, кроме цифр/знаков/пробелов - выдает ошибку
{
	int i;

	i = 0;
	while(s[i])
	{
		if(issp(s[i]) || s[i] == '-' || s[i] == '+' || is09(s[i]))
			++i;
		else
		{
			write(2, "Error_3: invalid characters in arguments.", 41);
			exit (0);
		}
	}
	i = 0;
	while (s[i])
	{
		if ((s[i] == '-' || s[i] == '+') && !is09(s[i + 1]))
		{
			write(2, "Error_4: plus or minus signs are separate from numbers(1).", 58);
			exit (0);
		}
		++i;
	}
}

int int_count(char *s) //подсчитывает количество цифр в строке, если количество цифр 0 - выдает ошибку
{
	int i;
	int dig_numbers;

	i = 0;
	dig_numbers = 0;
	while(s[i])
	{
		if(is09(s[i]) && (issp(s[i + 1]) || s[i + 1] == '\0'))
			++dig_numbers;
		if(is09(s[i]) && !(is09(s[i + 1]) || issp(s[i + 1]) || s[i + 1] == '\0')) ///если после цифры идет что-то, отличное от цифры или пробела или \0 - ошибка!!!
		{
			write(2, "Error_5: incorrect argument composition.", 40);
			exit(0);
		}
		++i;
	}
	if (dig_numbers == 0)
	{
		write(2, "Error_6: passed values are not integer.", 39); ///Вариант, когда строка состоит только символов + - и пробелов ///НЕ НУЖНА!!! УБРАТЬ
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
				write(2, "Error_10: among the arguments there are identical numbers.", 58);
				exit (0);
			}
		}
		++i;
	}
}

void	init_tab(char *s, t_data *data) ///собирает массив интов, состоящий из переданных аргументов, если есть некорректные числа/сборные числа - выдает ошибку
{
	int i;
	int j;

	j = 0;
	i = 0;
	check_chars(s);
	data->size = int_count(s);
	data->tabb = malloc(sizeof(int) * data->size);
	fatality(data->tabb);
	while (j < data->size)
	{
		data->tabb[j] = atosh(s, &i);
		if (!issp(s[i]))
		{
			write(2, "Error_9: среди переданных чисел есть некорректные!", 84); /// Тут вариант чисел, когда внутри цифр есть +/- Другие варианты отсеиваются при проверке символов по строке
			exit (0);
		}
		++j;
	}
	check_tab(data->tabb, data->size);
	init_sort(data);
}

void	init_sort(t_data *data)
{
	int	i;

	data->sort = malloc(sizeof(int) * data->size);
	fatality(data->sort);
	i = 0;
	while (i < data->size)
	{
		data->sort[i] = data->tabb[i];
		++i;
	}
	sort_tab(data->sort, data->size);
}
