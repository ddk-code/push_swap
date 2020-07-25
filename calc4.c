
//
// Created by ddk on 24.07.2020.
//

#include "push_swap.h"
void    split_into_15(t_data *data)
{
    int     top_index;
    int     section;
    int     i;

    i = 1;
    section = data->size / 15;

    while (data->a_len > 5)
    {
        top_index = section * i;
        first_pb(data, top_index, section);
        ++i;
//        printf("\nsection = %d", section);
//        exit(0);
    }
}

void    split_into_11(t_data *data)
{
    int     top_index;
    int     section;
    int     i;

    i = 1;
    section = data->size / 11;

    while (data->a_len > 5)
    {
        top_index = section * i;
        first_pb(data, top_index, section);
        ++i;
//        printf("\nsection = %d", section);
//        exit(0);
    }
//    printf("\na:  \n");
//    print_st(data->a);
//    printf("b:  ");
//    print_st(data->b);

}

void    calc500(t_data *data)
{
///// Вариант с разделением на 2 ниже:
//
//    if (!check_stack(data->a))
//        split_by_2(data);
//    while (data->b)
//        find_max_pa(data->b_len, data);
//
///// первый вариант с разделением на 5 ниже:
//    if (!check_stack(data->a))
//        split_into5(data);
//
//    if (data->a)
//        calc_5(data);
//
//    while (data->b)
//        find_max_pa(data->b_len, data); /// maxi можно убрать, изначально по длине а можно сразу вытащить индекс максимального в б

/// разделение на 11 частей ниже:
    if (!check_stack(data->a))
        split_into_11(data);
    if (data->a)
        calc_5(data);
    while (data->b)
        find_max_pa(data->b_len, data);

///// разделение на 15 частей ниже:
//    if (!check_stack(data->a))
//        split_into_15(data);
//    if (data->a)
//        calc_5(data);
//    while (data->b)
//        find_max_pa(data->b_len, data);

}