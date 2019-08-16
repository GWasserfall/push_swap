#include <push_swap.h>

int len_to_end(t_stack *head, t_stack *item)
{
	int i;

	i = 0;
	while (head != item)
		head = head->next;

	while (item)
	{
		i++;
		item = item->next;
	}
	return (i);
}

int len_from_start(t_stack *head, t_stack *item)
{
	int i;

	i = 0;
	while (head->next)
	{
		if (head->next == item)
			return i;
		i++;
		head = head->next;
	}
	return i;
}