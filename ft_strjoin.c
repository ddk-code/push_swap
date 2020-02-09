/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 20:33:46 by pcharlot          #+#    #+#             */
/*   Updated: 2020/02/09 20:33:48 by pcharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		len1;

	i = 0;
	len1 = ft_strlen(s1);
	res = (char *)malloc(len1 + ft_strlen(s2) + 1);
	while (s1[i])
	{
		res[i] = s1[i];
		++i;
	}
	while (s2[i - len1])
	{
		res[i] = s2[i - len1];
		++i;
	}
	res[i] = '\0';
	return (res);
}
