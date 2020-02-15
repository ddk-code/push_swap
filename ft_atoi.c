/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:40:58 by pcharlot          #+#    #+#             */
/*   Updated: 2020/02/13 13:33:49 by pcharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi(char *s)
{
	int			sign;
	int			i;
	long long	res;

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
//	if ((res < −2147483648) || (res > 2147483647))
//		exit (0);
	return (res * sign);
}
