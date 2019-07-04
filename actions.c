#include "push_swap.h"

extern bool debug;

// sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
// 	 is only one or no elements).
void sa(t_stacks **stacks)
{
	t_stack *a;
	t_stack *b;
	bool	is_checker;

	is_checker = (*stacks)->is_checker;
	a = *(*stacks)->a;
	b = *(*stacks)->b;

	ft_swap(&a);

	if (!is_checker)
		ft_putstr("sa\n");
	if (debug)
		db_delayprint("sa", stacks);
}

// sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
//      is only one or no elements).
void sb(t_stacks **stacks)
{
	t_stack *a;
	t_stack *b;
	bool	is_checker;

	is_checker = (*stacks)->is_checker;

	a = *(*stacks)->a;
	b = *(*stacks)->b;
	ft_swap(&b);

	if (!is_checker)
		ft_putstr("sb\n");
	if (debug)
		db_delayprint("sb", stacks);
}

// ss : sa and sb at the same time.
void ss(t_stacks **stacks)
{
	t_stack *a;
	t_stack *b;
	bool	is_checker;

	is_checker = (*stacks)->is_checker;
	a = *(*stacks)->a;
	b = *(*stacks)->b;

	ft_swap(&a);
	ft_swap(&b);

	if (!is_checker)
		ft_putstr("ss\n");
	if (debug)
		db_delayprint("ss", stacks);
}

// ***pa : push a - take the first element at the top of b and put it at the top of a. Do
// 	       nothing if b is empty.
void pa(t_stacks **stacks)
{
	t_stack *a;
	t_stack *b;
	bool	is_checker;

	is_checker = (*stacks)->is_checker;
	a = *(*stacks)->a;
	b = *(*stacks)->b;

	ft_push(&b, &a);

	if (!is_checker)
		ft_putstr("pa\n");
	if (debug)
		db_delayprint("pa", stacks);
}

// pb : push b - take the first element at the top of a and put it at the top of b. Do
// 	    nothing if a is empty.
void pb(t_stacks **stacks)
{
	t_stack *a;
	t_stack *b;
	bool	is_checker;

	is_checker = (*stacks)->is_checker;
	a = *(*stacks)->a;
	b = *(*stacks)->b;

	ft_push(&a, &b);

	if (!is_checker)
		ft_putstr("pb\n");
	if (debug)
		db_delayprint("pb", stacks);
}


// ra : rotate a - shift up all elements of stack a by 1. The first element becomes
// 	    the last one.
void ra(t_stacks **stacks)
{
	t_stack *a;
	t_stack *b;
	bool	is_checker;

	is_checker = (*stacks)->is_checker;
	a = *(*stacks)->a;
	b = *(*stacks)->b;

	ft_rotate(&a);

	if (!is_checker)
		ft_putstr("ra\n");
	if (debug)
		db_delayprint("ra", stacks);
}

// rb : rotate b - shift up all elements of stack b by 1. The first element becomes
// 	    the last one.
void rb(t_stacks **stacks)
{
	t_stack *a;
	t_stack *b;
	bool	is_checker;

	is_checker = (*stacks)->is_checker;
	a = *(*stacks)->a;
	b = *(*stacks)->b;

	ft_rotate(&b);

	if (!is_checker)
		ft_putstr("rb\n");
	if (debug)
		db_delayprint("rb", stacks);
}

// rr : ra and rb at the same time.
void rr(t_stacks **stacks)
{
	t_stack *a;
	t_stack *b;
	bool	is_checker;

	is_checker = (*stacks)->is_checker;
	a = *(*stacks)->a;
	b = *(*stacks)->b;

	ft_rotate(&a);
	ft_rotate(&b);
	
	if (!is_checker)
		ft_putstr("rr\n");
	if (debug)
		db_delayprint("rr", stacks);
}


// rra : reverse rotate a - shift down all elements of stack a by 1. The flast element
// becomes the first one.
void rra(t_stacks **stacks)
{
	t_stack *a;
	t_stack *b;
	bool	is_checker;

	is_checker = (*stacks)->is_checker;
	a = *(*stacks)->a;
	b = *(*stacks)->b;

	ft_reverse(&a);

	if (!is_checker)
		ft_putstr("rra\n");
	if (debug)
		db_delayprint("rra", stacks);
}


// rrb : reverse rotate b - shift down all elements of stack b by 1. The flast element
// 	  becomes the first one.
void rrb(t_stacks **stacks)
{
	t_stack *a;
	t_stack *b;
	bool	is_checker;

	is_checker = (*stacks)->is_checker;
	a = *(*stacks)->a;
	b = *(*stacks)->b;

	ft_reverse(&b);
	
	if (!is_checker)
		ft_putstr("rrb\n");
	if (debug)
		db_delayprint("rrb", stacks);
}


// rrr : rra and rrb at the same time.
void rrr(t_stacks **stacks)
{
	t_stack *a;
	t_stack *b;
	bool	is_checker;

	is_checker = (*stacks)->is_checker;
	a = *(*stacks)->a;
	b = *(*stacks)->b;

	ft_reverse(&a);
	ft_reverse(&b);

	if (!is_checker)
		ft_putstr("rrr\n");
	if (debug)
		db_delayprint("rrr", stacks);
}
