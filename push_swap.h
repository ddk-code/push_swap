/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:46:31 by pcharlot          #+#    #+#             */
/*   Updated: 2020/02/13 13:41:21 by pcharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h> ///		printf
#include <stdlib.h> ///		malloc free exit
#include <unistd.h> ///		write read
#include <fcntl.h> ///		read ?


typedef struct		s_stack
{
	int				nbr;
	struct t_stack	*next;

}					t_stack;

int					ft_strlen(char *s);
char				*ft_strjoin(char *s1, char *s2);

long long			ft_atoi(char *s);

#endif


int					ft_digcount(long long nbr);

int					is_digit(char c);