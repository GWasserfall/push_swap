#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# define true	1
# define false	0

typedef int bool;
typedef struct		s_stack
{
	int 			value;
	int				index;
	int				group;
	bool			master;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_stacks 
{
	bool			is_checker;
	t_stack 		**a;
	t_stack 		**b;
}					t_stacks;

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
void ra(t_stacks **stacks);
void rb(t_stacks **stacks);
void rr(t_stacks **stacks);
void rra(t_stacks **stacks);
void rrb(t_stacks **stacks);
void rrr(t_stacks **stacks);

// debug
void				db_printstacks(t_stack **a, t_stack **b);
void				db_delayprint(char *action_name, t_stacks **stacks);

// stack
bool				ft_appendelem(t_stack **stack, int value);
t_stack				*ft_newelem(int value);
t_stack				*ft_stackinit();
bool				ft_sorted(t_stack **stack, t_stack **helper);

// helpers
bool				ft_hasdupe(t_stack **stack);

// push_swap
t_stacks			*ft_containstacks(t_stack **a, t_stack **b, bool is_checker);

// alogos
void				ft_kaksort(t_stacks **container);
void				sort_three(t_stacks **container);
void				ft_slowsort(t_stacks **container);
void				ft_gabbysort(t_stacks **container, int group);

int					get_value_at_index(t_stack **stack, int index);

int					index_of(t_stack **stack, int number);
int					stack_len(t_stack *stack);
int					get_min(t_stack **stack);

// Sanatise Input 
bool				input_sane(int argc, char **argv);


#endif