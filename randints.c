#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <libft.h>

void print_array(int *arr, int size)
{
	int j;

	j = 0;
	while (j < size)
	{
		ft_putnbr(arr[j]);
		j++;
		if (j != size)
			ft_putchar(' ');
	}
	write(1, "\n", 1);
}

int	is_unique(int suggested, int *array, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (suggested == array[i])
			return (0);
		i++;
	}
	return (1);
}

int main(int ac, char **av)
{
	int *array;
	int current;
	int max;
	int i;

	srand(time(NULL));
	if (ac == 2)
	{
		max = ft_atoi(av[1]);
		array = (int *)malloc(sizeof(int) * max);
		i = 0;
		while (i < max)
		{
			current = rand() % (max * 2);
			if (is_unique(current, array, i))
			{
				array[i] = current;
				i++;
			}
		}
		print_array(array, max);
	}
	else
		write(1, "How many numbers should we generate? Huh? ./randint {int:count}\n", 64);
   return 0;
}