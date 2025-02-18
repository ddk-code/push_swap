/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digcount.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 11:58:29 by pcharlot          #+#    #+#             */
/*   Updated: 2020/02/23 11:58:31 by pcharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	digcount(long long nbr)
{
	int i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		++i;
		nbr = nbr / 10;
	}
	return (i);
}
