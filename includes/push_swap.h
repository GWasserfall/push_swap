#ifndef __STDBOOL_H
# define true	1
# define false	0
typedef int bool;
#endif

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <libft.h>
# include <limits.h>
# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define RESET "\x1B[0m"
# define LEFT -1
# define BOTH 0
# define RIGHT 1



typedef struct		s_stack
{
	int 			value;
	int				index;
	int				group;
	bool			master;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

enum e_action
{
	PA, PB, RA, RB, RR, SA, SB, SS, RRA, RRB, RRR, START, INVALID
};

typedef struct		s_action
{
	struct s_action	*next;
	struct s_action	*prev;
	enum e_action	action;
}					t_action;

typedef struct		s_stacks 
{
	bool			is_checker;
	t_action		*v_actions;
	t_stack 		**a;
	t_stack 		**b;
}					t_stacks;

typedef struct	s_moves
{
	t_stack		*elem;
	int			a_moves;
	int			b_moves;
	int			total;
}				t_moves;

// actions_backend
void			ft_swap(t_stack **stack);
void			ft_rotate(t_stack **stack);
void			ft_reverse(t_stack **stack);
void			ft_push(t_stack **sender, t_stack **receiver);

// actions
void			sa(t_stacks **stacks);
void			sb(t_stacks **stacks);
void			ss(t_stacks **stacks);
void			pa(t_stacks **stacks);
void			pb(t_stacks **stacks);
void			ra(t_stacks **stacks);
void			rb(t_stacks **stacks);
void			rr(t_stacks **stacks);
void			rra(t_stacks **stacks);
void			rrb(t_stacks **stacks);
void			rrr(t_stacks **stacks);


t_action	*new_action(enum e_action action);
void	append_new_action(t_action **previous, enum e_action a);

// debug
void				db_printstacks(t_stack **a, t_stack **b);

void				largest_to_top(t_stacks **container);
int					slen(t_stack *stack);

// stack
bool				ft_appendelem(t_stack **stack, int value);
t_stack				*ft_newelem(int value);
t_stack				*ft_stackinit();
bool				ft_sorted(t_stack **stack, t_stack **helper);

// helpers
bool				ft_hasdupe(t_stack **stack);

// push_swap
t_stacks			*ft_containstacks(t_stack **a, t_stack **b, bool is_checker);

int					visi(t_stacks *container);

// alogos
void				gsort(t_stacks **container, t_moves **moves, int a_max);
void				ft_kaksort(t_stacks **container);
void				ft_sort_three(t_stacks **container);
void				ft_slowsort(t_stacks **container);
void				ft_gabbysort(t_stacks **container);
void				ft_sort_four(t_stacks **container);
void				ft_sort_five(t_stacks **container);
void				ft_sort_two(t_stacks **container);
void				flabbysort(t_stacks **container);
void				slottysort(t_stacks **container);
int min_index(t_stack *stack);

int max_index(t_stack *stack);
int stack_is_long(t_stack *stack);

int					get_value_at_index(t_stack **stack, int index);

void				show_stack(t_stack *head);

int					index_of(t_stack **stack, int number);
int					stack_len(t_stack *stack);
int					get_min(t_stack **stack);
void				ft_midsplit(t_stacks **container);

void push_back_to_a(t_stacks **container);
void largest_to_top(t_stacks **container);
void ft_sort_three_b(t_stacks **container);

long				ft_atol(char *string);

bool ft_single_sorted(t_stack *head);
void	ft_sort_below_five(t_stacks **container);


int len_from_start(t_stack *head, t_stack *item);
void	ft_anotherway(t_stacks **container);
int len_to_end(t_stack *head, t_stack *item);

// Sanatise Input 
bool				input_sane(int argc, char **argv);
t_stack *get_last_item(t_stack *stack);
bool	preflight(int argc, char **argv);
bool	args_are_digits(int argc, char **argv);
bool	args_fit_int(int argc, char **argv);

int visualize_stacks(t_stacks *container);
void normalise(t_stack *stacka, int count);
bool	ft_act(t_stacks **container, char *str);

#endif