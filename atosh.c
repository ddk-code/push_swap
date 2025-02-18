/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atosh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:14:56 by pcharlot          #+#    #+#             */
/*   Updated: 2020/02/23 19:10:59 by pcharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	atosh(char *s, int *i) ///вытаскивает из строки число, если число не входит в формат INTa - выдает ошибку
{
	int			sign;
	long long	res;

	res = 0;
	sign = 1;
	while ((s[*i] >= 9 && s[*i] <= 13) || s[*i] == 32)
		++(*i);
	if (s[*i] == '-' || s[*i] == '+')
	{
		if(!is09(s[*i + 1]))
		{
			write(2, "Error_7:c", 55); ///Испавить воскл знаки - вариант когда кроме символов имеется хотя бы одно число, тогда именно здесь отлавливается ошибка
			exit (0);
		}
		if (s[*i] == '-')
			sign = -1;
		++(*i);
	}
	while (s[*i] && is09(s[*i]))
	{
		res = res * 10 + (s[*i] - '0');
		if ((res * sign < (long long)INT_MIN) || (res * sign > (long long)INT_MAX))
		{
			write(2, "Error_8: at least one argument is out of int.", 45);
			exit (0);
		}
		++(*i);
	}

//	if ((res * sign < (long long)INT_MIN) || (res * sign > (long long)INT_MAX))
//	{
//		write(2, "Error: among the supplied values there are non-integer numbers.", 63);
//		exit (0);
//	}
	return ((int)(res * sign));
}

