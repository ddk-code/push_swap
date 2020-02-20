#include "push_swap.h"

//#include "ft_list.h"

void swapi(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

t_stack	*sort_list(t_stack* lst)
{
    t_stack	*temp;
    t_stack	*begin;

    temp = lst;
    begin = lst;

    while(lst)
    {
        temp = lst->next;
        if(temp)
        {
            if(!ascending(lst->nbr, temp->nbr))
            {
                swapi(&lst->nbr, &temp->nbr);
                lst = begin;
            }
            else
                lst = lst->next;
        }
        else
            break ;
    }
    return (begin);
}

int		ascending(int a, int b)
{
    return (a <= b);
}