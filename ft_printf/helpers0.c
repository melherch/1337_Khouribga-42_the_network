#include "ft_printf.h"

int ft_putchar(char c)
{
	write(1, &c, 1);
	return 1;
}

int ft_putstr(char *s)
{
	int i = 0;

	if (!s)
		s = "(null)";
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int ft_putnbr(int n)
{
	long nbr = n;
	int counter = 0;

	if (nbr < 0)
	{
		counter += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > 9)
		counter += ft_putnbr(nbr / 10);
	counter += ft_putchar((nbr % 10) + '0');
	return (counter);
}
int ft_putunbr(unsigned int n)
{
	int counter = 0;

	if (n >= 10)
		counter += ft_putunbr(n / 10);
	counter += ft_putchar((n % 10) + '0');
	return (counter);
}
