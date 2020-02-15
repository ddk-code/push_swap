/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atosh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:46:24 by pcharlot          #+#    #+#             */
/*   Updated: 2020/02/15 19:21:32 by pcharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	atosh(char *s, int *i) ///вытаскивает из строки число, если число не входит в формат INTa - выдает ошибку
{
	int			sign;
	long long	res;

	res = 0;
	sign = 1;
	while ((s[*i] >= 9 && s[*i] <= 13) || s[*i] == 32)
		++(*i);
	if (s[*i] == '-' || s[*i] == '+')
	{
		if(!is_digit09(s[*i + 1]))
		{
			write(2, "Error: among the supplied values there are non-integer numbers!!!", 65); ///Испавить воскл знаки
			exit (0);
		}
		if (s[*i] == '-')
			sign = -1;
		++(*i);
	}
	while (s[*i] && is_digit09(s[*i]))
	{
		res = res * 10 + (s[*i] - '0');
		++(*i);
	}

	if ((res * sign < (long long)INT_MIN) || (res * sign > (long long)INT_MAX))
	{
		write(2, "Error: among the supplied values there are non-integer numbers.", 63);
		exit (0);
	}
	return (res * sign);
}
