#include "ft_printf.h"

int ft_puthexa(unsigned long n, char format)
{
	int counter = 0;
	char *base;

	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";

	if (n >= 16)
		counter += ft_puthexa(n / 16, format);
	counter += ft_putchar(base[n % 16]);
	return (counter) ;
}

int ft_putaddress(void *ptr)
{
	int counter = 0;

	if (!ptr)
		return ft_putstr("(nil)");
	counter += ft_putstr("0x");
	counter += ft_puthexa((unsigned long)ptr, 'x');
	return (counter);
}