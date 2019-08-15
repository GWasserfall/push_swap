#include <push_swap.h>

typedef struct	s_moves
{
	t_stack		*elem;
	int			a_moves;
	int			b_moves;
	int			total;
}				t_moves;

int end_index(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack->index);
}

int closest_lower_index(t_stack *stack, int index)
{
	int i;

	i = 0;

	stack = stack->next;
	while (stack)
	{
		if (stack->index > i && stack->index < index)
			i = stack->index;
		stack = stack->next;
	}
	return i;
}

int closest_higher_index(t_stack *stack, int index)
{
	int i;
	int min;

	i = max_index(stack);
	min = min_index(stack);

	//printf("Max index is %d", i);

	stack = stack->next;
	while (stack)
	{
		if (stack->index < i && i > min)
		{
			i = stack->index;
			//printf("New min for %d is %d\n", index, i);
		}
		stack = stack->next;
	}
	return i;
}

int move_count(t_stack *stack, int norm)
{
	int count;
	int start;
	int end;
	int len;
	int max;
	int min;

	len = stack_is_long(stack);

	count = 0;
	end = end_index(stack);
	max = max_index(stack);
	min = min_index(stack);

	t_stack *cur;
	t_stack *starts;

	starts = stack->next;
	
	int next;
	int iters;

	iters = 0;
	next = closest_lower_index(stack, norm);
	stack = stack->next;
	if (norm > max && start == max)
	{
		//printf("%.2d is bigger than %.2d and %.2d is on top for %d moves\n", norm, max, max, iters);
		return (0);
	}

	if (norm < min)
	{
		next = closest_higher_index(stack, norm);
		//printf("%d Next == %d\n", norm, next);
	}


	while (stack)
	{
		if (stack->index == next)
			break;
		count++;
		stack = stack->next;
	}

	//printf("count for %d is %d\n", norm, count);
	if (count > len / 2)
	{
		
		return count - len;
	}
	else
	{
		return count;
	}
	


	// while (stack->next)
	// {
		
	// 	start = stack->index;
	// 	cur = starts;

	// 	if (stack->index == next)
	// 	{
	// 		printf("%.2d should go ontop of %.2d for %d moves\n", norm, next, iters);
	// 		break;
	// 	}

	// 	iters++;

	// 	// if (norm > start && norm < end)
	// 	// {
	// 	// 	printf("%d will fit between start %d and end %d\n", norm, start, end);
	// 	// 	break;
	// 	// }



	// 	count++;
	// 	end = start;
	// 	stack = stack->next;

	// 	if (!stack)
	// 		break;
	// }

	return count;
}

void	best_move(t_moves **move, t_stack *a, t_stack *b, int max)
{
	t_moves *m;
	int position;
	int len;
	int lenb;
	int amoves;
	int bmoves;
	int total;

	int big;

	big = max_index(a);

	bmoves = 0;
	len = stack_is_long(a);
	lenb = stack_is_long(b);
	m = *move;
	a = a->next;

	m->a_moves = 50;
	m->b_moves = 50;
	m->total = 100;
	m->elem = a;

	position = 0;
	
	while (a)
	{
		amoves = (position > len / 2) ? position - len : position;
		bmoves = move_count(b, a->index);
		if (bmoves > lenb / 2)
			bmoves = bmoves - lenb;
	

		if (bmoves == amoves)
		{
			total = (bmoves > 0) ? bmoves : bmoves * -1;
		}
		else if (amoves > 0 && bmoves > 0)
		{
			total = (amoves > bmoves ? amoves : bmoves);
		}
		else if (amoves < 0 && bmoves < 0)
		{
			total = (amoves < bmoves) ? amoves * -1 : bmoves * -1;
			
		}
		else
		{
			total = (amoves - bmoves > 0) ? amoves - bmoves : (amoves - bmoves) * -1;
			//total += (amoves > bmoves) ? bmoves : amoves;
		}
		
		if (a->index > big - 3)
		{
			//printf("Stack max == %d\n", big);
			total += 200;
		}

		if (total < m->total)
		{
			m->a_moves = amoves;
			m->b_moves = bmoves;
			m->elem = a;
			m->total = total;
		}
		//printf("\tI [%d]  T [%d]  A [%d]  B[%d]\n", a->index, m->total, m->a_moves, m->b_moves);

		position++;
		a = a->next;
	}
}


void print_stacks_old(t_stack *a, t_stack *b)
{
	a = a->next;
	b = b->next;
	while (a || b)
	{
		if (a)
		{
			printf("   %d    ", a->index);
			a = a->next;
		}
		else
		{
			printf("         ");
		}
		
		if (b)
		{
			printf("   %d    ", b->index);
			b = b->next;
		}
		printf("\n");

	}

}

void ft_rotate_a(t_stacks **container, t_moves **moves)
{
	if ((*moves)->a_moves > 0)
	{
		ra(container);
		(*moves)->a_moves--;
	}
	else
	{
		rra(container);
		(*moves)->a_moves++;
	}
}

void ft_rotate_b(t_stacks **container, t_moves **moves)
{
	if ((*moves)->b_moves > 0)
	{
		rb(container);
		(*moves)->b_moves--;
	}
	else
	{
		rrb(container);
		(*moves)->b_moves++;
	}
}

void gsort(t_stacks **container)
{
	t_stack *a;
	t_stack *b;
	t_moves *this;
	int offset;

	a = *(*container)->a;
	b = *(*container)->b;

	offset = 0;

	int main_max;
	
	this = malloc(sizeof(t_moves));
	main_max = max_index(a);


	int push_count = 0;
	while (push_count < 3)
	{
		if (a->next->index >= main_max - 3)
			ra(container);
		else
		{
			pb(container);
			push_count++;
		}	
	}


	while (a->next)
	{

		if (stack_is_long(a) == 3)
		{
			ft_sort_three(container);
			break;
		}

		best_move(&this, a, b, main_max);

		while (this->a_moves || this->b_moves)
		{
			if (this->b_moves > 0 && this->a_moves > 0)
			{
				rr(container);
				this->a_moves--;
				this->b_moves--;
			}
			else if (this->b_moves < 0 && this->a_moves < 0)
			{
				rrr(container);
				this->a_moves++;
				this->b_moves++;
			}
			else if (!this->b_moves && this->a_moves)
			{
				ft_rotate_a(container, &this);
				// if (this->a_moves > 0)
				// {
				// 	ra(container);
				// 	this->a_moves--;
				// }
				// else
				// {
				// 	rra(container);
				// 	this->a_moves++;
				// }
			}	
			else
			{
				ft_rotate_b(container, &this);
				// if (this->b_moves > 0)
				// {
				// 	rb(container);
				// 	this->b_moves--;
				// }
				// else
				// {
				// 	rrb(container);
				// 	this->b_moves++;
				// }
			}
		}
		pb(container);
	}
	push_back_to_a(container);
}