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
	
	int maxb;
	stack = stack->next;
	while (stack->next)
	{
		start = stack->index;
		cur = starts;

		if (norm > max && start == max)
			break;
		if (norm > start && norm < end)
			break;

		count++;
		end = start;
		stack = stack->next;

		if (!stack)
			break;
	}

	return count;
}

void	best_move(t_moves **move, t_stack *a, t_stack *b, int max)
{
	t_moves *m;
	int position;
	int len;
	int lenb;

	len = stack_is_long(a);
	lenb = stack_is_long(b);
	m = *move;
	a = a->next;

	m->a_moves = 50;
	m->b_moves = 50;
	m->total = 100;
	m->elem = a;

	position = 0;
	int amoves;
	int bmoves;
	int total;
	while (a)
	{
		
		amoves = (position > len / 2) ? position - len : position;
		bmoves = move_count(b, a->index);
		if (bmoves > lenb / 2)
			bmoves = bmoves - lenb;
		total = (amoves - bmoves > 0) ? amoves - bmoves : (amoves - bmoves) * -1;

		if (total < m->total)
		{
			m->a_moves = amoves;
			m->b_moves = bmoves;
			m->elem = a;
			m->total = total;
		}
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
					rb(container);
					this->b_moves--;
				}
				else
				{
					rrb(container);
					this->b_moves++;
				}
			}
		}
		pb(container);
	}
	push_back_to_a(container);
}