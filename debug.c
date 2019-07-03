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


void db_delayprint(char *action_name, t_stacks **stacks)
{
	t_stack *a;
	t_stack *b;

	if (!debug)
		return ;

	a = *(*stacks)->a;
	b = *(*stacks)->b;

	acount++;

	const char str1[] = "~~~~~~~~~~~~~~~~~~~~~~ EXEC : ";
	const char str2[] = "~~~~~~~~~~~~~~~~~~~~~~~~\n";	


	usleep(50000);
	system("clear");
	db_printstacks(&a, &b);

	// write(1, str1, strlen(str1));
	// write(1, action_name, strlen(action_name));
	// write(1, str2, strlen(str2));
	
}