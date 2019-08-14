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

int move_count(t_stack *stack, int norm)
{
	int count;
	int start;
	int end;
	int len;
	int max;

	len = stack_is_long(stack);

	count = 0;
	end = end_index(stack);
	max = max_index(stack);

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
		printf("%.2d is bigger than %.2d and %.2d is on top for %d moves\n", norm, max, max, iters);
		return (0);
	}

	while (stack)
	{
		if (stack->index == next)
			break;
		count++;
		stack = stack->next;
	}

	printf("count for %d is %d\n", norm, count);
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
		else
		{
			total = (amoves - bmoves > 0) ? amoves - bmoves : (amoves - bmoves) * -1;
			//total += (amoves > bmoves) ? bmoves : amoves;
		}
		
		if (total < m->total)
		{
			m->a_moves = amoves;
			m->b_moves = bmoves;
			m->elem = a;
			m->total = total;
		}
		printf("\tI [%d]  T [%d]  A [%d]  B[%d]\n", a->index, m->total, m->a_moves, m->b_moves);
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

	pb(container);
	pb(container);

	if (b->next->index < b->next->next->index)
		sb(container);

	main_max = max_index(a);

	while (a->next)
	{


		if (a->next->index > max_index(b) && b->next->index == max_index(b))
		{
			pb(container);
			continue;
		}

		best_move(&this, a, b, main_max);

		print_stacks_old(a, b);
		printf("\n\nbest Move:: for %d\n", this->elem->index);
		printf("a_moves = %d\n", this->a_moves);
		printf("b_moves = %d\n", this->b_moves);
		printf("total = %d\n", this->total);
		getchar();
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
				if (this->a_moves > 0)
				{
					ra(container);
					this->a_moves--;
				}
				else
				{
					rra(container);
					this->a_moves++;
				}
			}	
			else
			{
				if (this->b_moves > 0)
				{
					rrb(container);
					this->b_moves--;
				}
				else
				{
					rb(container);
					this->b_moves++;
				}
			}
		}
		pb(container);
	}
	push_back_to_a(container);
}