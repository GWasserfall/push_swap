#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# define true	1
# define false	0

typedef int bool;
typedef struct		s_stack
{
	int 			value;
	bool			master;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct	s_stacks 
{
	t_stack 	*a;
	t_stack 	*b;
}				t_stacks;

// actions_backend
void	ft_swap(t_stack **stack);
void	ft_rotate(t_stack **stack);
void	ft_reverse(t_stack **stack);
void	ft_push(t_stack **sender, t_stack **receiver);

// actions
void sa(t_stacks **stacks);
void sb(t_stacks **stacks);
void ss(t_stacks **stacks);
void pa(t_stacks **stacks);
void pb(t_stacks **stacks);


// debug
void				db_printstacks(t_stack **a, t_stack **b);



// stack
bool				ft_appendelem(t_stack **stack, int value);
t_stack				*ft_newelem(int value);
t_stack				*ft_stackinit();

#endif