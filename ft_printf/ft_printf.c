#include "ft_printf.h"

int ft_check(char specifier, va_list args)
{
	if (specifier == 'c')
		return ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		return ft_putstr(va_arg(args, char *));
	else if (specifier == 'p')
		return ft_putaddress(va_arg(args, void *));
	else if (specifier == 'd' || specifier == 'i')
		return ft_putnbr(va_arg(args, int));
	else if (specifier == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (specifier == 'x' || specifier == 'X')
		return ft_puthexa(va_arg(args, unsigned int), specifier);
	else if (specifier == '%')
		return ft_putchar('%');
    else
    {
        ft_putchar('%');
        ft_putchar(specifier);
        return (2);
    }
	return 0;
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int i;
    int counter;

    if (!format)
		return (-1);
    i = 0;
    counter = 0;
    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            if (!format[i + 1])
                return (-1);
            i++;
            counter += ft_check(format[i], args);
        }
        else
            counter += ft_putchar(format[i]);
        i++;
    }
    va_end(args);
    return (counter);
}

