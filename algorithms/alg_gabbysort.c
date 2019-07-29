#include <push_swap.h>

int get_base_group(t_stack *stack)
{
	int group;
	t_stack *cursor;

	group = 0;
	cursor = stack->next;
	while(cursor)
	{
		if (!group)
			group = cursor->group;
		if (cursor->group < group)
			group = cursor->group;
		cursor = cursor->next;
	}
	return (group);
}

int get_top_group(t_stack *stack)
{
	int group;
	t_stack *cursor;

	group = 0;
	cursor = stack->next;
	while (cursor)
	{
		if (cursor->group > group)
			group = cursor->group;
		cursor = cursor->next;
	}
	return (group);
}

void	last_item_rec(t_stack *start, t_stack **result, int g)
{
	if (start->next)
		last_item_rec(start->next, result, g);
	if (!*result)
	{
		if (start->group == g)
			*result = start;
	}
}

t_stack *last_item_in_group(t_stack *stack, int group)
{
	t_stack *result;
	result = NULL;

	last_item_rec(stack, &result, group);
	return (result);
}

t_stack *first_item_in_group(t_stack *stack, int group)
{
	while (stack)
	{
		if (stack->group == group)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_stack *get_last_item(t_stack *stack)
{
	t_stack *result;

	result = NULL;

	// Skip the master nodes
	stack = stack->next;
	while (stack)
	{
		result = stack;
		stack = stack->next;
	}
	return (result);
}

int len_to_end(t_stack *head, t_stack *item)
{
	int i;

	i = 0;
	while (head != item)
		head = head->next;

	while (item)
	{
		i++;
		item = item->next;
	}

	return (i);
}

int len_from_start(t_stack *head, t_stack *item)
{
	int i;

	i = 0;
	while (head->next)
	{
		if (head->next == item)
			return i;
		i++;
		head = head->next;
	}
	return i;
}

void largest_to_top(t_stacks **container)
{
	t_stacks *stacks = *container;
	t_stack *b = *(stacks->b);
	t_stack *largest;
	t_stack *cursor;
	
	largest = b->next;
	cursor = b->next;
	while (cursor)
	{
		if (cursor->index > largest->index)
			largest = cursor;
		cursor = cursor->next;
	}
	
	while (b->next != largest)
	{
		if (len_from_start(b, largest) < len_to_end(b, largest))
			rb(container);
		else
			rrb(container);
	}
	pa(container);
}

void maybe(t_stacks **container)
{
	t_stacks *stacks = *container;
	t_stack *a = *(stacks->a);
	t_stack *b = *(stacks->b);
	t_stack *a_first;
	t_stack *b_first;
	t_stack *a_second;
	t_stack *b_second;

	a_first = a->next;
	b_first = b->next;	
	if (!a_first || !b_first)
		return ;
	a_second = a_first->next;
	b_second = b_first->next;
	if (!a_second || !b_second)
		return ;
}


void push_back_to_a(t_stacks **container)
{
	t_stacks *stacks = *container;
	t_stack *a = *(stacks->a);
	t_stack *b = *(stacks->b);

	t_stack *af;
	t_stack *al;
	t_stack *bf;
	t_stack *bl;
	while (b->next)
	{
		af = a->next;
		al = get_last_item(a);
		bf = b->next;
		bl = get_last_item(b);
	
		if (b->next->next)
			if ((bf->value < bf->next->value))
				sb(container);
	
		if (af && af->next)
			if (af->value > af->next->value)
				sa(container);
		
		largest_to_top(container);		
	}
}

extern int debug;

void maybe_swap_b(t_stacks **container)
{
	t_stacks *stacks = *container;
	t_stack *b = *(stacks->b);
	t_stack *first;
	t_stack *second;

	first = b->next;
	if (!first)
		return ;
	second = first->next;
	if (second)
	{
		if (first->value < second->value)
			rr(container);
		else
			ss(container);
		
	}
}


void ft_gabbysort(t_stacks **container)
{
	t_stacks *stacks = *container;
	t_stack *a = *(stacks->a);
	t_stack *first;
	t_stack *last;
	int group;

	while ((group = get_base_group(*(stacks->a))))
	{
		first = first_item_in_group(*(stacks->a), group);
		last = last_item_in_group(*(stacks->a), group);
		if (len_from_start(a, first) < len_to_end(a, last))
		{
			while (a->next != first)
				ra(container);
			pb(container);
		}
		else
		{
			while (a->next != last)
				rra(container);
			pb(container);
		}
		maybe_swap_b(container);
	}
	push_back_to_a(container);
}