#include "push_swap.h"

void    swap_a(t_intlist **stack)
{
    t_intlist   *tmp;

    tmp = (*stack)->next;
    (*stack)->next = tmp->next;
    tmp->next = (*stack);
    (*stack) = tmp;
    write(1, "sa\n", 3);
}

void    push_a(t_intlist **stack_a, t_intlist **stack_b)
{
    t_intlist   *new;
    t_intlist   *tmp;

    if (!stack_a || !stack_b)
        return ;
    new_node(&new);
    new->next = (*stack_a);
    new->content = (*stack_b)->content;
    (*stack_a) = new;
    tmp = (*stack_b);
    (*stack_b) = (*stack_b)->next;
    free(tmp);
    write(1, "pa\n", 3);
}

void    rotate_a(t_intlist **stack)
{
    t_intlist   *iterate;
    t_intlist   *rot;
    t_intlist   *first_node;

    iterate = *stack;
    new_node(&rot);
    rot->content = (*stack)->content;
    while (iterate->next != NULL)
        iterate = iterate->next;
    iterate->next = rot;
    first_node = *stack;
    *stack = (*stack)->next;
    free(first_node);
    write(1, "ra\n", 3);
}

void    reverse_rotate_a(t_intlist **stack)
{
    t_intlist   *iterate;
    t_intlist   *rot;
    t_intlist   *last_node;

    iterate = *stack;
    while (iterate->next->next != NULL)
        iterate = iterate->next;
    rot = malloc(sizeof(t_intlist));
    rot->content = iterate->next->content;
    rot->next = (*stack);
    (*stack) = rot;
    last_node = iterate->next;
    iterate->next = NULL;
    free(last_node);
    write(1, "rra\n", 4);
}