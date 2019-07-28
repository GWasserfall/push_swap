#include "push_swap.h"

//INT_MIN = -2147483648

#define LTC "\u250F"
#define LBC "\u2517"
#define RBC "\u251B"
#define RTC "\u2513"
#define HOR "\u2501"
#define VER "\u2503"

extern int acount;
extern bool debug;


void show_stack(t_stack *head)
{
	int i;

	i = 0;

	while (head)
	{
		i++;
		if (i > 10)
			return ;
		printf("[%d][%d] = %d -> %p\n", head->master, head->index, head->value, head->next);
		head = head->next;
	}
}


void db_reprint(char *str, int count)
{
	while (count)
	{
		printf("%s", str);
		count--;
	}
}

void db_header()
{
	printf("\n" LTC);
	db_reprint(HOR, 11);
	printf(" A ");
	db_reprint(HOR, 12);
	printf(RTC " " LTC);
	db_reprint(HOR, 11);
	printf(" B ");
	db_reprint(HOR, 12);
	printf(RTC);
	printf("\n");	
}

void db_footer()
{
	printf(LBC);
	db_reprint(HOR, 26);
	printf(RBC " " LBC);
	db_reprint(HOR, 26);
	printf(RBC);
	printf("\n\n");	
}

void db_printstacks(t_stack **a, t_stack **b)
{
	t_stack *ca;
	t_stack *cb;
	int		ia;
	int		ib;

	if (!debug)
		return ;

	db_header();
	
	ca = (*a)->next;
	cb = (*b)->next;
	
	ia = 0;
	ib = 0;

	if (!ca && !cb) {
		printf(VER " %10d : %-11s | | %10d : %-11s\n", 0, "empty", 0, "empty");
		return ;
	}

	while (ca || cb)
	{
		if (ca && cb)
		{
			printf(VER " %10d : %-11d " VER " " VER " %10d : %-11d " VER "\n", ia++, ca->value, ib++, cb->value);
			ca = ca->next;
			cb = cb->next;
		}
		else if (ca && !cb)
		{
			printf(VER " %10d : %-11d " VER " " VER " %10d : %-11s " VER "\n", ia++, ca->value, ib++, "empty");
			ca = ca->next;
		}
		else if (!ca && cb)
		{
			printf(VER " %10d : %-11s " VER " " VER " %10d : %-11d " VER "\n" , ia++, "empty", ib++, cb->value);
			cb = cb->next;
		}
		else
		{
			printf("Error of some kind :(\n");
			return ;
		}
	}
	db_footer();
}


t_actions *new_actionitem(enum actions action)
{
	t_actions *new;

	if (!(new = (t_actions *)malloc(sizeof(t_actions))))
		return (NULL);

	new->next = NULL;
	new->action = action;
	return (new);
}

void append_action(t_actions *list, enum actions action)
{
	t_actions *new;

	if (!(new = new_actionitem(action)))
		return ;

	while (list->next)
	{
		list = list->next;
	}
	list->next = new;
}

void db_delayprint(enum actions action, t_stacks **stacks)
{
	t_stack *a;
	t_stack *b;
	static t_actions *action_list;

	if (!action_list)
		action_list = new_actionitem(action);
	else
		append_action(action_list, action);
	

	if (!debug)
		return ;

	a = *(*stacks)->a;
	b = *(*stacks)->b;

	acount++;

	const char str1[] = "~~~~~~~~~~~~~~~~~~~~~~ EXEC : ";
	const char str2[] = "~~~~~~~~~~~~~~~~~~~~~~~~\n";	


	usleep(1000);
	//getchar();
	
	system("clear");
	db_printstacks(&a, &b);
	t_actions *cursor;

	cursor = action_list;
	int i;
	i = 0;
	// while (cursor)
	// {
	// 	if (cursor->action == a_ra)
	// 		printf(" -> ra");
	// 	if (cursor->action == a_rb)
	// 		printf(" -> rb");
	// 	if (cursor->action == a_rr)
	// 		printf(" -> rr");
	// 	if (cursor->action == a_sa)
	// 		printf(" -> sa");
	// 	if (cursor->action == a_sb)
	// 		printf(" -> sb");
	// 	if (cursor->action == a_ss)
	// 		printf(" -> ss");
	// 	if (cursor->action == a_pa)
	// 		printf(" -> pa");
	// 	if (cursor->action == a_pb)
	// 		printf(" -> rpb");
	// 	if (cursor->action == a_rra)
	// 		printf(" -> rra");
	// 	if (cursor->action == a_rrb)
	// 		printf(" -> rrb");
	// 	if (cursor->action == a_rrr)
	// 		printf(" -> rrr");
	
	// 	cursor = cursor->next;
	// 	i++;
	// 	if (i > 12)
	// 		break;
	// }

	// write(1, str1, strlen(str1));
	// write(1, action_name, strlen(action_name));
	// write(1, str2, strlen(str2));
	
}