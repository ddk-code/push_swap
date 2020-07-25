//
// Created by ddk on 23.07.2020.
//

#include "push_swap.h"

int     maxi(t_stack *st)
{
    int     max;
    t_stack *temp;

    max = st->sort_i;
    temp = st;
    while (temp)
    {
        if (max < temp->sort_i)
            max = temp->sort_i;
        temp = temp->next;
    }
    return (max);
}

void    find_max_pa(int si, t_data *data)
{
    int     count;
    t_stack *temp;

    temp = data->b;
    count = 1;
    while (temp && temp->sort_i != si)
    {
        ++count;
        temp = temp->next;
    }
    if (count <= data->b_len / 2 + 1)
        pa_up(count - 1, data);
    else if (count > data->b_len / 2 + 1)
        pa_down(data->b_len - count + 1, data);
}

void    pa_up(int i, t_data *data)
{
    while (i - 1 > 0)
    {
        rb(&data->b);
        --i;
    }
    if (data->b_len >= 2 && i == 1)
    {
        if (data->b->sort_i == data->b->next->sort_i - 1)
            sb(&data->b);
        else
            rb(&data->b);
    }
    pa(&data->a, &data->b, data);
}

void    pa_down(int i, t_data *data)
{
    while (i != 0)
    {
        rrb(&data->b);
        --i;
    }
    pa(&data->a, &data->b, data);
}

int     check_ind_inside(int top_index, t_stack *st) /// пробежать по стеку и проверить сортировочные индексы. Если находит индекс <= топ индексу - возврщает 1, иначе 0
{
    t_stack *temp;

    temp = st;
    while(temp)
    {
        if (temp->sort_i <= top_index)
            return (1);
        temp = temp->next;
    }
    return (0);
}

void    first_pb(t_data *data, int top_index, int section)
{

    int b;

    if (data->a_len <= section)
        top_index = data->size - 5;
    else if (data->a_len - section < 5)
        top_index = top_index - (5 - (data->a_len - section));
//    printf("\ntop index = %d a_len = %d", top_index, data->a_len);


    b = first_pb_ra_or_rra(data, top_index); /// определяет направление по часовой стрелке ra или против rra
    while (check_ind_inside(top_index, data->a))
    {
        if (data->a->sort_i <= top_index)
            pb(&data->b, &data->a, data);
        else
            //   printf("cost %d", first_pb_ra_or_rra(data, top_index));
            b ? ra(&data->a) : rra(&data->a);
    }


//    while (check_ind_inside(top_index, data->a))
//    {
//        if (data->a->sort_i <= top_index)
//            pb(&data->b, &data->a, data);
//        if (last_sort_i(data->a) <= top_index && last_sort_i(data->a) > 0)
//        {
//            rra(&data->a);
//            pb(&data->b, &data->a, data);
//        }
//        else
//            ra(&data->a);
//    }
}

int     first_pb_ra_or_rra(t_data *data, int top_index)
{
    int begin;
    int end;
    int b_cost;
    int e_cost;
    int count;
    t_stack *temp;

    count = 1;
    temp = data->a;
    while (temp)
    {
        if (temp->sort_i <= top_index)
        {
            begin = count;
            break;
        }
        temp = temp->next;
        ++count;
    }
    count = 1;
    temp = data->a;
    while (temp)
    {
        if (temp->sort_i <= top_index)
            end = count;
        temp = temp->next;
        ++count;
    }
    if (begin <= data->a_len / 2 + 1)
        b_cost = begin;
    else
        b_cost = data->a_len - begin + 2;
    if (end <= data->a_len / 2 + 1)
        e_cost = end;
    else
        e_cost = data->a_len - end + 2;
    if ((b_cost <= e_cost) && (begin <= data->a_len / 2 + 1))
        return (1); ///ra
    if ((b_cost <= e_cost) && (begin > data->a_len / 2 + 1))
        return (0); ///rra
    if ((b_cost > e_cost) && (end <= data->a_len / 2 + 1))
        return (1); /// ra
    if ((b_cost > e_cost) && (end > data->a_len / 2 + 1))
        return (0); /// rra
}


int     last_sort_i(t_stack *st) /// возвращает sort_i последнего нижнего элемента стека
{
    t_stack *temp;
    int     last_si;

    temp = st;
    last_si = -1;
    while (temp)
    {
        last_si = temp->sort_i;
        temp = temp->next;
    }
    return (last_si);
}

void    split_into5(t_data *data)
{
    int     top_index;
    int     section;
    int     i;

    i = 1;
    section = (data->size / 5 > 5 ? data->size / 5 : 5);
//    printf("\nsize = %d", data->size);
//    printf("\nsection = %d", section);
//    exit(0);
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


void    calc_100 (t_data *data)
{
    if (!check_stack(data->a))
        split_into5(data);
//    printf("\n[a]:");
//    print_st(data->a);
//    exit(0);
    if (data->a)
        calc_5(data);
//    printf("\n[a]:");
//    print_st(data->a);
//    printf("maxi = %d", maxi(data->b));
//    exit(0);

//    printf("\nB:");
//    print_st(data->b);
    while (data->b)
        find_max_pa(data->b_len, data); /// maxi можно убрать, изначально по длине а можно сразу вытащить индекс максимального в б
//    printf("\nA:");
//    print_st(data->a);

}