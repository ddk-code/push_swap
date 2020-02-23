/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joinfree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 11:57:36 by pcharlot          #+#    #+#             */
/*   Updated: 2020/02/23 11:57:37 by pcharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*joinfree(char *s1, char *s2)
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
	free(s1);
	return (res);
}
