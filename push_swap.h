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
	int 			sort_i; ///индекс как должны стоять
	int             i;      /// индекс, как стоят изначально
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
	int 			a_med;
	int 			b_med;
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
//void	pa(t_stack **st_a, t_stack **st_b);
//void	pb(t_stack **st_b, t_stack **st_a); ///удалить в будущем

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


void    go_calc(t_data *data);
void    calc_mid (t_data *data);
void    calc_3 (t_data *data);
int     check_stack(t_stack *a);
void    calc_5 (t_data *data);

void	pa(t_stack **st_a, t_stack **st_b, t_data *data);
void	pb(t_stack **st_b, t_stack **st_a, t_data *data);
///void	sa(t_stack *st_a);
void    find_med(t_data *data, int stack_number);
int     mini(t_stack *st); /// возвращает минимальный сортированный индекс в стеке, то есть sort_i минимального элемента в стеке
int     maxi(t_stack *st); /// возвращает максимальный сортированный индекс в стеке, то есть si максимального элемента в стеке
void    find_min_pb(int si, t_data *data); /// по индексу находит порядковый номер минимального элемента и принимает решение, как именно передвинуть в б
void    pb_up(int i, t_data *data, int f_ra); /// поднимает i раз в стеке а и перекидывает в стек б f_ra показывает лучше оставить ротацию или использовать sa
void    pb_down(int i, t_data *data); /// опускает i раз и перекидывает в стек б

void    calc_100 (t_data *data);
/// int     check_stack_rev(t_stack *st); ///проверяет, отсортирован ли стек в обратном порядке
void    first_pb(t_data *data, int top_index, int section); /// из стека а, все элементы с сортировочным индексом меньше или равно top_index перетаскиваем в б
void    find_max_pa(int si, t_data *data);
void    pa_up(int i, t_data *data);
void    pa_down(int i, t_data *data);
void	print_st(t_stack *st);
int     check_ind_inside(int top_index, t_stack *st);
int     last_sort_i(t_stack *st);
int     first_pb_ra_or_rra(t_data *data, int top_index);

void    split_into5(t_data *data);

void    calc_100_new (t_data *data);
void    split_by_2(t_data *data);
void    first_push_b(t_data *data, int top_index);
void    smart_pa(t_data *data);

void    calc500(t_data *data);
void    split_into_11(t_data *data);
void    split_into_15(t_data *data);


void    go_go(t_data *data);
void    go100(t_data *data);
void    first_push(t_data *data);
int     is_less_max_in_st(int max_index, t_stack *st);
int     is_more_min_in_st(int min_index, t_stack *st);
void    push_back(t_data *data);
void	printst(t_stack *st);
int     last_index(t_stack *st);
void    check_first_second_last(t_data *data);

#endif

