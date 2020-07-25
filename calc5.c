//
// Created by ddk on 24.07.2020.
//

#include "push_swap.h"

void    sorting_a(t_data *data)
{
    while (!check_stack(data->a))
    {
        if (data->a->sort_i == 1 || data->a->sort_i - last_index(data->a) == 1)
            ra(&data->a);
        else
            pb(&data->b, &data->a, data);
    }
}

int     last_index(t_stack *st)  ///возвращает сортировочный индекс последнего элемента
{
    t_stack *temp;
    int     last;

    temp = st;
    last = 0;
    while(temp)
    {
        last = temp->sort_i;
        temp = temp->next;
    }
    return (last);
}

void    check_first_second_last(t_data *data)
{
    while (1)
    {
        if (data->a && data->a->sort_i - last_index(data->a) == 1)
        {
            ra(&data->a);
            continue ;
        }
        if (data->b && (data->b->sort_i == 1 || data->b->sort_i - last_index(data->a) == 1))
        {
            pa(&data->a, &data->b, data);
            ra(&data->a);
            continue ;
        }
        if (last_index(data->b) - last_index(data->a) == 1)
        {
            rrb(&data->b);
            pa(&data->a, &data->b, data);
            ra(&data->a);
            continue ;
        }
        if (data->a && data->a->next && data->a->sort_i - data->a->next->sort_i == 1)
        {
            sa(&data->a);
            continue ;
        }
        if (data->b && data->b->next && data->b->next->sort_i - data->b->sort_i == 1)
        {
            sb(&data->b);
            continue ;
        }
        break ;
    }

}

void    push_back(t_data *data)
{
    int min_index;

    min_index = data->b_len / 2;
    while (is_more_min_in_st(min_index, data->b))
    {
//        if (data->b->sort_i == 1 || data->b->sort_i - last_index(data->a) == 1)
//        {
//            pa(&data->a, &data->b, data);
//            ra(&data->a);
//        }
        check_first_second_last(data);
        if (data->b && data->b->sort_i > min_index)
            pa(&data->a, &data->b, data);
        else
            rb(&data->b);
    }
//    printf("\nA:   ");
//    printst(data->a);
}

int     is_more_min_in_st(int min_index, t_stack *st)
{
    t_stack *temp;

    temp = st;
    while (temp)
    {
        if (temp->sort_i > min_index)
            return (1);
        temp = temp->next;
    }
    return (0);
}

int     is_less_max_in_st(int max_index, t_stack *st)
{
    t_stack *temp;

    temp = st;
    while (temp)
    {
        if (temp->sort_i <= max_index)
            return (1);
        temp = temp->next;
    }
    return (0);
} /// если сортировочные индексы меньше или равно макс есть в стеке, возвращает 1, если нет - 0

void    first_push(t_data *data)
{
    int max_index;

    max_index = data->a_len / 2;
    while (is_less_max_in_st(max_index, data->a))
    {
        if (data->a->sort_i <= max_index)
        {
            pb(&data->b, &data->a, data);
//            if (data->b->next && data->b->next->sort_i - data->b->sort_i == 1)
//                sb(&data->b);
        }
        else
            ra(&data->a);
    }
} /// перекидывает половину наименьших значений из a в b

void    go100(t_data *data)
{
    first_push(data);
//    printf("\na_len = %d b_len = %d", data->a_len, data->b_len);
//    printf("\nA:   ");
//    printst(data->a);
    while (data->b)
    {
        while (data->b)
            push_back(data);
        if (!check_stack(data->a))
            sorting_a(data);
    }

//    while (data->b)
//        push_back(data);
//    if (!check_stack(data->a))
//        sorting_a(data);

//    sorting_a(data);
//    sorting_a(data);
//    sorting_a(data);
//    sorting_a(data);

//    printf("\nA:   ");
//    printst(data->a);

    printf("\n res %d", check_stack(data->a));
    print_stack(data->b);

//    printst(data->a);
//    printf("\n last sorti a = %d", last_index(data->a));
//    printst(data->b);
//    printf("\n last sorti b = %d", last_index(data->b));


}

void    go_go(t_data *data)
{
    if (data->size <= 3)
        calc_3(data);
    else if (data->size <= 5)
        calc_5(data);
    else// if (data->size <= 100)
        go100(data);
}