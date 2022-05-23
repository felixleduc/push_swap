
#include "push_swap.h"

int find_index(t_intlist **stack, int c)
{
    t_intlist   *iterate;
    int         i;

    iterate = *stack;
    i = 1;
    while (iterate->content != c)
    {
        ++i;
        iterate = iterate->next;
    }
    return (i);
}

int list_len(t_intlist **stack)
{
    t_intlist   *iterate;
    int i;

    iterate = *stack;
    i = 0;
    while (iterate)
    {
        iterate = iterate->next;
        ++i;
    }
    return (i);
}