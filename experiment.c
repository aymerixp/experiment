#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	while(*s != '\0')
		ft_putchar(*s++);
}

void	ft_line(int i)
{
	while(i > 0)
	{
		ft_putchar('=');
		i--;
	}
}

void	ft_colonne(int i, int j)
{
	int k;

	while (j > 0)
	{
		k = 0;
		while(k < i)
		{
			if (k == 0)
				ft_putchar('|');
			else if (k == i)
			{
				ft_putchar('|');
				ft_putchar('\n');
			}
			else
				ft_putchar(' ');
			k++;
		}
		j--;
	}
}

int		main(int ac, char **av)
{
	if (ac < 2)
	{
		ft_putchar('\n');
		return (0);
	}
	else
		ft_putstr(av[1]);
	ft_line(8);
	ft_colonne(8, 5);
	return (0);
}
