//
// Created by ddk on 22.07.2020.
//

#include "push_swap.h"

int     check_stack(t_stack *a) ///проверяет, отсортирован ли стек
{
    t_stack *temp;

    temp = a;
    while (temp->next && temp)
    {
        if (temp->sort_i > temp->next->sort_i)
            return (0);
        else
            temp = temp->next;
    }
    return (1);
}

int     check_stack_rev(t_stack *st) ///проверяет, отсортирован ли стек в обратном порядке
{
    t_stack *temp;

    temp = st;
    while (temp->next && temp)
    {
        if (temp->sort_i < temp->next->sort_i)
            return (0);
        else
            temp = temp->next;
    }
    return (1);
}

void    find_med(t_data *data, int stack_number) /// ищет центр, от которого будет произведен расчет, в какую сторону двигать числа
{
    if (stack_number == 1)
    {
        if (data->a_len != 0)
            data->a_med = data->a_len / 2 + 1;
        else
            data->a_med = 0;
    }
    if (stack_number == 2)
    {
        if (data->b_len != 0)
            data->b_med = data->b_len / 2 + 1;
        else
            data->b_med = 0;
    }
}

void    calc_3 (t_data *data)
{
    while (!check_stack(data->a))
    {
        if (data->a->sort_i - data->a->next->sort_i == 1 || data->a->sort_i - data->a->next->sort_i == -2)
            sa(&data->a);
        else if (data->a->sort_i - data->a->next->sort_i == 2)
            ra(&data->a);
        else if (data->a->sort_i - data->a->next->sort_i == -1)
            rra(&data->a);
    }
}

int     mini(t_stack *st)
{
    int     min;
    t_stack *temp;

    min = st->sort_i;
    temp = st;
    while (temp)
    {
        if (min > temp->sort_i)
            min = temp->sort_i;
        temp = temp->next;
    }
    return (min);
}


void    find_min_pb(int si, t_data *data)
{
    int     count;
    int     count2;
    int     f_ra;
    t_stack *temp;

    temp = data->a;
    count = 1;
    f_ra = 0;
//    printf(")))%d", si);
    while (temp && temp->sort_i != si)
    {
        ++count;
        temp = temp->next;
    }
    if (data->a_len == 5)
    {
        count2 = 1;
        temp = data->a;
        while (temp && temp->sort_i != si + 1)
        {
            ++count2;
            temp = temp->next;
        }
        if (count - count2 == -1 || count - count2 == -2)
            f_ra = 1;
    }
//    printf("count = %d count2 = %d", count, count2);

    if (count <= data->a_len / 2 + 1)
        pb_up(count - 1, data, f_ra);
    else if (count > data->a_len / 2 + 1)
        pb_down(data->a_len - count + 1, data);
}

void    pb_up(int i, t_data *data, int f_ra)
{
    while (i > 1)
    {
        ra(&data->a);
        --i;
    }
    if (i == 1)
        f_ra ? ra(&data->a) : sa(&data->a);
    pb(&data->b, &data->a, data);
}

void    pb_down(int i, t_data *data)
{
    while (i != 0)
    {
        rra(&data->a);
        --i;
    }
    pb(&data->b, &data->a, data);
}

void    calc_5 (t_data *data)
{
    if (!check_stack(data->a) /*&& !data->b*/)
    {
        int var;

        var = data->b_len;
//        printf("a len = %d", data->a_len);
//        printf("b len = %d", data->b_len);
        while (data->a_len > 3)
            find_min_pb(mini(data->a), data);
//                printf("a len = %d", data->a_len);
//        printf("b len = %d", data->b_len);
        calc_3(data);
        while (data->b_len - var > 0)
            pa(&data->a, &data->b, data);
    }
//    printf("\na после сортировки 5ти:  \n");
//    print_st(data->a);
}

//void    go_rev(t_data *data) ///пока только переворачивает стек а, переделать для любого стека. Когда буду менять операции под любой стек
//{
//    int i;
//
//    i = 1;
//    printf("\n i = %d len = %d", i, data->a_len);
//    while (i < data->a_len)
//    {
//        ra(&data->a);
//        ++i;
//        printf("\n i = %d len = %d", i, data->a_len);
//    }
//}

void    go_calc(t_data *data)
{
//    printf("\nРазмер массива %d", data->size);
//    printf("\nРазмер a %d", data->a_len);
//    printf("\nРазмер b %d", data->b_len);

//    printf("\n %d", data->a->sort_i );
//    printf("\n %d", data->a->next->sort_i );
//    printf("\n %d", data->a->next->next->sort_i );
//    printf("\n%d", check_stack(data->a));
//


//    printf("a: ");
//    print_stack(data->a);

//    printf("\nlast of a %d   last of b %d", last_sort_i(data->a), last_sort_i(data->b));
    if (data->size <= 3)
        calc_3(data);
    else if (data->size <= 5)
        calc_5(data);
    else if (data->size <= 100)
        calc_100_new(data);
//        calc_100(data);
    else if (data->size <= 500)
        calc500(data);

    printf("\n res %d", check_stack(data->a));
//    print_stack(data->b);

//    printf("\nlast of a %d   last of b %d", last_sort_i(data->a), last_sort_i(data->b));
//    exit(0);
//    printf("a: ");
//    print_st(data->a);
//    printf("b: ");
//    print_stack(data->b);

}
