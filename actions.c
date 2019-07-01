#include "push_swap.h"

// sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
// 	 is only one or no elements).
void sa(t_stacks **stacks)
{
	t_stack *a;
	t_stack *b;

	a = *(*stacks)->a;
	b = *(*stacks)->b;

	ft_swap(&a);
	printf("\n\n~~~~~~~~~~~~~~~~~~~~~~ EXEC : sa ~~~~~~~~~~~~~~~~~~~~~~~~");
}

// sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
//      is only one or no elements).
void sb(t_stacks **stacks)
{
	t_stack *a;
	t_stack *b;

	a = *(*stacks)->a;
	b = *(*stacks)->b;
	ft_swap(&b);
	printf("\n\n~~~~~~~~~~~~~~~~~~~~~~ EXEC : sb ~~~~~~~~~~~~~~~~~~~~~~~~");
}

// ss : sa and sb at the same time.
void ss(t_stacks **stacks)
{
	t_stack *a;
	t_stack *b;

	a = *(*stacks)->a;
	b = *(*stacks)->b;

	ft_swap(&a);
	ft_swap(&b);
	printf("\n\n~~~~~~~~~~~~~~~~~~~~~~ EXEC : ss ~~~~~~~~~~~~~~~~~~~~~~~~");
}

// ***pa : push a - take the first element at the top of b and put it at the top of a. Do
// 	       nothing if b is empty.
void pa(t_stacks **stacks)
{
	t_stack *a;
	t_stack *b;

	a = *(*stacks)->a;
	b = *(*stacks)->b;

	ft_push(&b, &a);
	printf("\n\n~~~~~~~~~~~~~~~~~~~~~~ EXEC : pa ~~~~~~~~~~~~~~~~~~~~~~~~");
}

// pb : push b - take the first element at the top of a and put it at the top of b. Do
// 	    nothing if a is empty.
void pb(t_stacks **stacks)
{
	t_stack *a;
	t_stack *b;

	a = *(*stacks)->a;
	b = *(*stacks)->b;

	ft_push(&a, &b);
	printf("\n\n~~~~~~~~~~~~~~~~~~~~~~ EXEC : pb ~~~~~~~~~~~~~~~~~~~~~~~~");
}


// ra : rotate a - shift up all elements of stack a by 1. The first element becomes
// 	    the last one.
void ra(t_stacks **stacks)
{
	t_stack *a;
	t_stack *b;

	a = *(*stacks)->a;
	b = *(*stacks)->b;

	ft_rotate(&a);
	printf("\n\n~~~~~~~~~~~~~~~~~~~~~~ EXEC : ra ~~~~~~~~~~~~~~~~~~~~~~~~");
}

// rb : rotate b - shift up all elements of stack b by 1. The first element becomes
// 	    the last one.
void rb(t_stacks **stacks)
{
	t_stack *a;
	t_stack *b;

	a = *(*stacks)->a;
	b = *(*stacks)->b;

	ft_rotate(&b);
	printf("\n\n~~~~~~~~~~~~~~~~~~~~~~ EXEC : rb ~~~~~~~~~~~~~~~~~~~~~~~~");
}

// rr : ra and rb at the same time.
void rr(t_stacks **stacks)
{
	t_stack *a;
	t_stack *b;

	a = *(*stacks)->a;
	b = *(*stacks)->b;

	ft_rotate(&a);
	ft_rotate(&b);
	printf("\n\n~~~~~~~~~~~~~~~~~~~~~~ EXEC : rr ~~~~~~~~~~~~~~~~~~~~~~~~");
}


// rra : reverse rotate a - shift down all elements of stack a by 1. The flast element
// becomes the first one.
void rra(t_stacks **stacks)
{
	t_stack *a;
	t_stack *b;

	a = *(*stacks)->a;
	b = *(*stacks)->b;

	ft_reverse(&a);
	printf("\n\n~~~~~~~~~~~~~~~~~~~~~~ EXEC : rra ~~~~~~~~~~~~~~~~~~~~~~~");
}


// rrb : reverse rotate b - shift down all elements of stack b by 1. The flast element
// 	  becomes the first one.
void rrb(t_stacks **stacks)
{
	t_stack *a;
	t_stack *b;

	a = *(*stacks)->a;
	b = *(*stacks)->b;

	ft_reverse(&b);
	printf("\n\n~~~~~~~~~~~~~~~~~~~~~~ EXEC : rrb ~~~~~~~~~~~~~~~~~~~~~~~");
}


// rrr : rra and rrb at the same time.
void rrr(t_stacks **stacks)
{
	t_stack *a;
	t_stack *b;

	a = *(*stacks)->a;
	b = *(*stacks)->b;

	ft_reverse(&a);
	ft_reverse(&b);
	printf("\n\n~~~~~~~~~~~~~~~~~~~~~~ EXEC : rrr ~~~~~~~~~~~~~~~~~~~~~~~");
}
