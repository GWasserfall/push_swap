#include <push_swap.h>

int get_value_at_indexb(t_stack **stack, int index)
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

void ft_sort_three_b(t_stacks **container)
{
    t_stacks *stacks = *container;
	t_stack *b = *(stacks->b);

    int one;
    int two;
    int thr;

    while (!(ft_single_sorted(b)))
    {
        one = get_value_at_indexb(&b, 0);
        two = get_value_at_indexb(&b, 1);
        thr = get_value_at_indexb(&b, 2);
        if (one > two && one < thr)   
            sb(container);
        else if (one > two && one > thr)
            rb(container);
        else if (one < two && two > thr)
            rrb(container);
        else if (one > two && one > thr)
            sb(container);
        else if (one < two && two > thr)
            sb(container);
    }
}