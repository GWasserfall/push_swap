#include "push_swap.h"

int get_value_at_index(t_stack **stack, int index)
{
    t_stack *cursor;
    int i;

    i = 0;
    cursor = (*stack)->next;
    while (cursor)
    {
        if (i == index)
        {
            return (cursor->value);
        }
        i++;
        cursor = cursor->next;
    }
    return -1;
}

void sort_three(t_stacks **container)
{
    t_stacks *stacks = *container;
	t_stack *a = *(stacks->a);
	t_stack *b = *(stacks->b);

    int one;
    int two;
    int thr;

    while (!(ft_sorted(&a, &b)))
    {
        one = get_value_at_index(&a, 0);
        two = get_value_at_index(&a, 1);
        thr = get_value_at_index(&a, 2);
        if (one > two && one < thr)   
            sa(container);
        else if (one > two && one > thr)
            ra(container);
        else if (one < two && two > thr)
            rra(container);
        else if (one > two && one > thr)
            sa(container);
        else if (one < two && two > thr)
            sa(container);
    }
}

void sort_two(t_stacks **container)
{
	t_stacks *stacks = *container;
	t_stack *a = *(stacks->a);
	t_stack *b = *(stacks->b);
	
	while (!(ft_sorted(&a, &b)))
    {
            sa(container);
    }
}
