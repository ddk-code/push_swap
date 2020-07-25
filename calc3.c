//
// Created by ddk on 24.07.2020.
//

#include "push_swap.h"

void    smart_pa(t_data *data)
{

}

void    first_push_b(t_data *data, int top_index)
{
    int count;
    int section;

    section = data->a_len / 2;
    count = 0;
    while (!check_stack(data->a) || data->a_len > 5)
    {
        if (data->a->sort_i <= top_index)
        {
            pb(&data->b, &data->a, data);
            ++count;
            if (count == section)
                break ;
        }
        else
            ra(&data->a);
    }
}

void    split_by_2(t_data *data)
{
    while (data->a_len > 5)
//        first_push_b(data, data->a_len / 2 + data->b_len); ///новое
    first_pb(data, data->a_len / 2 + data->b_len, data->a_len / 2); ///старое
    if (data->a)
        calc_5(data);
}

void    calc_100_new (t_data *data)
{
    if (!check_stack(data->a))
        split_by_2(data);
//    printf("a_len = %d, b_len = %d", data->a_len, data->b_len);
//    print_st(data->a);
    while (data->b)
        find_max_pa(data->b_len, data);
}