#include "push_swap.h"

void ft_swap(t_stack **stack)
{
	//sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
	// is only one or no elements).
	t_stack *elem1;
	t_stack *elem2;
	t_stack	*temp;

	if ((*stack)->next && (*stack)->next->next)
	{
		elem1 = (*stack)->next;
		elem2 = elem1->next;
		elem1->next = elem2->next;
		elem2->prev = elem1->prev;
		elem1->prev = elem2;
		elem2->next = elem1;
		(*stack)->next = elem2;
	}
}

void ft_rotate(t_stack **stack)
{
	//ra : rotate a - shift up all elements of stack a by 1. The first element becomes
	// the last one.
	t_stack	*master;
	t_stack *first;
	t_stack *last;

	master = (*stack);
	first = master->next;
	last = first->next;

	if (first && last)
	{
		while (last->next)
			last = last->next;
	
		if (first->next == last)
			return ft_swap(stack);
			
		// second is now first
		master->next = first->next;
		first->next->prev = master;
		

		last->next = first;
		first->prev = last;
		first->next = NULL;


	}
}

void ft_reverse(t_stack **stack)
{
	//rra : reverse rotate a - shift down all elements of stack a by 1. The flast element
	//becomes the first one.
	t_stack *master;
	t_stack *first;
	t_stack *last;

	master = *stack;
	first = master->next;
	last = first->next;

	if (first && last)
	{
		while (last->next)
			last = last->next;

		if (first->next == last)
			return ft_swap(stack);

		master->next = last;
		last->prev->next = NULL;
		last->prev = master;
		last->next = first;
		first->prev = last;
	}
}

void	ft_push(t_stack **sender, t_stack **receiver)
{
	// ***pa : push a - take the first element at the top of b and put it at the top of a. Do
	//  nothing if b is empty.
	t_stack *s_first;
	t_stack *r_first;
	
	s_first = (*sender)->next;
	r_first = (*receiver)->next;

	if (!s_first)
		return ;

	// remove senders first item
	(*sender)->next = s_first->next;
	if ((*sender)->next)
		(*sender)->next->prev = (*sender); 

	// Put it ontop of receiver
	(*receiver)->next = s_first;
	s_first->prev = (*receiver);

	if (!r_first)
		s_first->next = NULL;
	else
	{
		r_first->prev = s_first;
		s_first->next = r_first;
	}
}