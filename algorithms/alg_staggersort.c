#include <push_swap.h>

int contains_index(t_stack *stack, int index)
{
	stack = stack->next;
	while (stack)
	{
		if (stack->index == index)
			return 1;
		stack = stack->next;
	}
	return (0);
}

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

t_stack *largest_in_group(t_stack *stack, int group)
{
	t_stack *result;

	result = NULL;
	while (stack)
	{
		if (stack->group == group)
		{
			if (!result)
				result = stack;
			if (stack->index > result->index)
				return (result);
				//result = stack;
		}
		stack = stack->next;
	}
	return (result);
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

void push_back_to_a(t_stacks **container)
{
	t_stacks *stacks = *container;
	t_stack *b = *(stacks->b);

	while (b->next)
		largest_to_top(container);
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
			{
				rra(container);
			}
			pb(container);
		}
	}
	push_back_to_a(container);
}


void flabbysort(t_stacks **container)
{
	t_stacks *stacks = *container;
	t_stack *a = *(stacks->a);
	t_stack *first;
	int group;

	while ((group = get_base_group(*(stacks->a))))
	{
		first = largest_in_group(*(stacks->a), group);
		if (len_from_start(a, first) < len_to_end(a, first))
		{
			while (a->next != first)
				ra(container);
			pb(container);
		}
		else
		{
			while (a->next != first)
			{
				rra(container);
			}
			pb(container);
		}
	}
	push_back_to_a(container);
}


int start(t_stack *stack)
{
	stack = stack->next;
	if (stack)
		return (stack->index);
	else
		return (0);
}

int end(t_stack *stack)
{
	stack = stack->next;
	while (stack->next)
		stack = stack->next;
	return (stack->index);
}

int min_index(t_stack *stack)
{
	int min;

	stack = stack->next;
	if (!stack)
		return (0);
	min = stack->index;
	while (stack->next)
	{
		if (stack->index < min)
			min = stack->index;
		stack = stack->next;
	}
	return min;
}


int max_index(t_stack *stack)
{
	int max;

	stack = stack->next;
	if (stack)
		max = stack->index;
	else
		return 0;

	while (stack->next)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return max;
}

int is_optimal(t_stacks **container, int index)
{
	t_stack *a;
	t_stack *b;

	a = *(*container)->a;
	b = *(*container)->b;

	if (index > max_index(b) && b->next->index == max_index(b))
		return 1;
	
	if (index < min_index(b) && b->next->index == min_index(b))
		return 1;

	if (index > start(b) && index < end(b))
		return 1;

	if (index < start(b))
		return -1;
	
	return (-1);
}

int direction(t_stack *stack, int index)
{
	t_stack *start;
	t_stack *end;
	int distance;

	distance = 0;
	start = stack->next;
	end = start;
	while (end->next)
		end = end->next;
		
	while (1)
	{
		if (index < end->index && index > start->index)
			break;
		if (index < start->index && index > start->next->index)
			break;
		distance++;
		start = start->next;
	}
	return distance;
}



void min_to_b(t_stacks **container, t_stack *a)
{
	t_stack *start;
	start = a;
	a = a->next;
	while (a)
	{
		if (a->index == 1)
			break;
		a = a->next;
	}
	if (len_from_start(start, a) < len_to_end(start, a))
		while (start->next != a)
			ra(container);
	else
		while (start->next != a)
			rra(container);
	pb(container);
}

void max_to_b(t_stacks **container, t_stack *a, int max_index)
{
	t_stack *start;

	start = a;
	a = a->next;
	while (a)
	{
		if (a->index == max_index)
			break;
		a = a->next;
	}
	if (len_from_start(start, a) < len_to_end(start, a))
		while (start->next != a)
			ra(container);
	else
		while (start->next != a)
			rra(container);
	pb(container);
}

int stack_is_long(t_stack *stack)
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


int	up(t_stack *b, int index)
{
	t_stack *start;
	int len;
	int dist;

	start = b;
	len = stack_is_long(b);
	dist = 0;
	b = b->next;

	while (b->next)
	{
		// if (index == 22)
		// {
		// 	printf("%d > %d && < %d\n", index,  b->index, b->next->index);
		// 	printf("distance : %d and answer is %d\n", dist, (dist <= (len / 2)));
		// 	getchar();
		// }

		if ((b->index == 1) && stack_is_long(start) > 2)
		{
			//printf("Skipping one\n");
			b = b->next;
		}
		if (index < b->index && index > b->next->index)
			break;
		dist++;
		b = b->next;
		if (!b)
			break;
	}
	//printf("dist = %d, len = %d, answer = %d\n", dist, len, (dist >= (len / 2)));
	return ((dist <= (len / 2)));
}

void slottysort(t_stacks **container)
{
	t_stack *a;
	t_stack *b;
	int max_index;

	a = *(*container)->a;
	b = *(*container)->b;

	max_index = stack_is_long(a);
	min_to_b(container, a);
	max_to_b(container, a, max_index);

	int s_start;
	int s_end;
	int this;

	while (a->next)
	{
		s_start = start(b);
		s_end  = end(b);
		this = a->next->index;
		//getchar();d
		if (this > s_start && this < s_end)
		{
			pb(container);
			continue;
		}
		
		int dir = up(b, this);

		if (stack_is_long(b) > 10 && stack_is_long(a) > 10)
		{
			if (a->next->index < 15)
				rr(container);
		}
		dir = up(b, this);
		if (dir)
			rb(container);
		else
			rrb(container);
	}
	push_back_to_a(container);
}