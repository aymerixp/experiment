#include <unistd.h>
#include <stdlib.h>
#include "../libraire/libft.h"

typedef struct		s_file
{
	int data;
	struct s_file *next;
}					t_file;

void	file_enqueue(t_file **p_file, int data)
{
	t_file *p_new;
	p_new = malloc(sizeof *p_new);
	if (p_new != NULL)
	{
		p_new->next = NULL;
		p_new->data = data;
		if (*p_file == NULL)
			*p_file = p_new;
		else
		{
			t_file *p_tmp;
			p_tmp = *p_file;
			while (p_tmp->next != NULL)
				p_tmp = p_tmp->next;
			p_tmp->next = p_new;
		}
	}
}

void	print_file(t_file *p_file)
{
	t_file *tmp;

	tmp = p_file;
	while (tmp != NULL)
	{
		ft_putnbr(tmp->data);
		ft_putchar(' ');
		tmp = tmp->next;
	}
}

int			croissant(int a, int b)
{
	return (a <= b);
}

t_file		*sort_list(t_file *lst, int (*cmp)(int, int))
{
	t_file		*tmp;
	tmp = lst;
	int stop;
	int tmp2;
	stop = 0;
	while (stop != 1)
	{
		stop = 1;
		tmp = lst;
		while (tmp->next)
		{
			if (!cmp(tmp->data, tmp->next->data))
			{
				tmp2 = tmp->data;
				tmp->data = tmp->next->data;
				tmp->next->data = tmp2;
				stop = 0;
			}
			tmp = tmp->next;
		}
		print_file(lst);
		ft_putchar('\n');
	}
	return (lst);
}


int		main(void)
{
	int tab[] = {5, 11, 54, 65, 78, 55, 88, 95, 14, 12};
	int i;
	i = 0;
	t_file *pointeur_file;
	pointeur_file = NULL;
	while (i < 10)
	{
		file_enqueue(&pointeur_file, tab[i]);
		i++;
	}
	pointeur_file = sort_list(pointeur_file, croissant);
	print_file(pointeur_file);
	return (0);
}
