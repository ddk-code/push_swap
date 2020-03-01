/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:57:26 by pcharlot          #+#    #+#             */
/*   Updated: 2020/03/01 18:02:17 by pcharlot         ###   ########.fr       */
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
	int 			i;
	int 			flag;
	struct s_stack	*next;

}					t_stack;

typedef struct		s_data
{
	t_stack 		*a;
	t_stack 		*a_down;
	t_stack 		*b;
	t_stack 		*b_down;
	int 			*tabb;
	int 			*sort;
	int 			size;
	int				a_len;
	int 			b_len;
	int 			a_mid;
	int 			b_mid;
}					t_data;


void	ft_stackadd(t_stack *stack, t_stack *new);

int					is09(char c);
int					is19(char c);
char				*joinfree(char *s1, char *s2);
int					digcount(long long nbr);
int					ft_strlen(char *s);
void				fatality(void *t);
int					issp(char c);
void				swapi(int *a, int *b);
void				ft_bzero(void *s, size_t n); ///она нужна вообще?
int					ft_strcmp(char *s1, char *s2); ///она нужна вообще?

void				nachalo_detected(char *s);

int					atosh(char *s, int *i); ///подумать над обработкой максимального и минимального интов ? возможно - решено

void				check_chars(char *s);
int					int_count(char *s);
void				check_tab(int *tab, int size);

void				init_tab(char *s, t_data *data); //////=============
void				init_sort(t_data *data); //////=============
void    			print_tab(int *tab, int size);
void				sort_tab(int *tab, int size); //////=============

int					ind(int *tab, int size, int value); ///возвращает индекс в массиве +1 когда число == value


t_stack				*init_node(t_data *data, int value);
void				set_a(t_data *data); //////=============





void	print_stack(t_stack *st);
void	add_new(t_stack **st, int digit);
void	dell_top(t_stack **st);
void	add_new_down(t_stack **st, int digit);
void	dell_down(t_stack **st);


void	sa(t_stack **st_a);
void	sb(t_stack **st_b); ///удалить в будущем
/// !!!! дописать ss
void	pa(t_stack **st_a, t_stack **st_b);
void	pb(t_stack **st_b, t_stack **st_a); ///удалить в будущем

void	ra(t_stack **st_a);
void	rb(t_stack **st_b);
/// !!! дописать rr
void	rra(t_stack **st_a);
void	rrb(t_stack **st_b);
/// rrr



void	kuku(int *tab, int size, t_stack **a, t_stack **b);


//typedef	struct		s_list
//{
//    int				data;
//    struct s_list	*next;
//}					t_list;

int		pos(t_stack *st, int nbr);
int		issort(t_stack *st);

///exam:
t_stack	*sort_list(t_stack* lst);
int		ascending(int a, int b);

#endif

