/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:40:58 by pcharlot          #+#    #+#             */
/*   Updated: 2020/02/13 13:21:29 by pcharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

intmax_t	ft_atoi(char *s)
{
	int			sign;
	int			i;
	intmax_t	res;

	res = 0;
	i = 0;
	sign = 1;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		++i;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		++i;
	}
	while (s[i] && is_digit(s[i]))
	{
		res = res * 10 + (s[i] - '0');
		++i;
	}
	return (res * sign);
}
