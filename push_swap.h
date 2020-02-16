/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:46:31 by pcharlot          #+#    #+#             */
/*   Updated: 2020/02/16 18:40:28 by pcharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h> ///		!!!!! printf !!!!!
#include <stdlib.h> ///		malloc free exit
#include <unistd.h> ///		write read
#include <fcntl.h> ///		read ?
#include <limits.h>


typedef struct		s_stack
{
	int				nbr;
	struct s_stack	*next;

}					t_stack;

int					ft_strlen(char *s);
char				*ft_strjoin(char *s1, char *s2);


#endif


int					ft_digcount(long long nbr);
int					is_digit09(char c);
int					is_digit19(char c);
void				ft_bzero(void *s, size_t n);
int					ft_isspace(char c);

long long			atosh(char *s, int *i); ///подумать над обработкой максимального и минимального интов ? возможно - решено


void				check_chars(char *s);
int					intnum(char *s);
void				check_tab(int *tab, int size);
int					*ft_tab(char *s);
void				check_argv(char *s);
void				check_zero(char *s); ///Представления ноля через несколько нолей считаем ошибкой

int					ft_strcmp(char *s1, char *s2);

void				ft_fatality(void *t);

void	nachalo_detected(int *tab, int size);
void	print_stack(t_stack *st);
void	add_new(t_stack **st, int digit);
void	dell_top(t_stack **st);
void	add_new_down(t_stack **st, int digit);


void	sa(t_stack **st_a);
void	sb(t_stack **st_b); ///удалить в будущем

void	pa(t_stack **st_a, t_stack **st_b);
void	pb(t_stack **st_b, t_stack **st_a); ///удалить в будущем