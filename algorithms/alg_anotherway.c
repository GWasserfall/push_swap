#include <push_swap.h>
#include <curses.h>

int first_index(t_stack *stack)
{
	stack = stack->next;
	if (stack)
		return (stack->index);
	return 0;
}

int last_index(t_stack *stack)
{
	stack = stack->next;
	if (!stack)
		return (0);
	
	while (stack->next)
		stack = stack->next;
	return stack->index;
}

int slen(t_stack *stack)
{
	int count;
	count = 0;

	stack = stack->next;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void rrr_check(t_stacks **container)
{
	t_stacks *stacks = *container;
	t_stack *a = *(stacks->a);
	t_stack *b = *(stacks->b);

	t_stack *a_last;
	t_stack *b_last;

	if (!b->next || !b->next->next)
		return ;
	if (!b->next || !b->next->next)
		return;
	a_last = a->next;
	while (a_last->next)
		a_last = a_last->next;

	b_last = b->next;
	while (b_last->next)
		b_last = b_last->next;
	
	// if (a->next->index > a_last->index)
	// 	rra(container);
	// //if (b->next->index < b_last->index)
	// 	rb(container);

}

t_stack *highest_index_in_stack(t_stack *head)
{
	t_stack *max;
	head = head->next;
	max = head;
	while (head)
	{
		if (head->index > max->index)
			max = head;
		head = head->next;
	}
	return (max);
}


void	ft_anotherway(t_stacks **container)
{
	t_stacks *stacks = *container;
	t_stack *a = *(stacks->a);
	t_stack *b = *(stacks->b);

	int mid = slen(a) / 2;
	int total;

	total = slen(a);
	while (a->next)
	{
		rrr_check(container);
		if (a->next->index > mid)
		{
			pb(container);
		}
		ra(container);
		if (slen(a) <= mid)
			mid = mid / 2;
	}

	// Slot insert
	rrb(container);
	pa(container);

	int index;
	t_stack *alast;
	int direction = 1;
	while (b->next)
	{
		alast = a->next;
		while (alast->next)
			alast = alast->next;
		index = a->next->index;
		if (index + 1 > total)
			index = 0;
		if (index - 1 < 1)
			index = total;

		if (a->next->index - 1 == b->next->index)
		{
			pa(container);
			direction = !direction;
		}
		// Lasty oney at the endy
		if (alast->index + 1 == b->next->index)
		{
			//getchar();
			pa(container);
			rr(container);
			direction = !direction;
		}
		if (b->next->index == total && a->next->index == 1)
		{
			pa(container);
			ra(container);
			direction = !direction;
		}
		if  (a->next->index == 1)
		{
			//getchar();	
		}
		if (direction)
			rrb(container);
		else
			rb(container);
		
		//getchar();
	}
}