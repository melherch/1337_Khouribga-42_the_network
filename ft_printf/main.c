
#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

#define SEP "\n----------------------------------------\n"

int main(void)
{
    int r1, r2;
    void *ptr = (void *)0x12345678;

    printf(SEP "BASIC TESTS" SEP);
    r1 = ft_printf("Hello world\n");
    r2 = printf("Hello world\n");
    printf(" ft: %d | pf: %d\n", r1, r2);

    printf(SEP "PERCENT" SEP);
    r1 = ft_printf("%%\n");
    r2 = printf("%%\n");
    printf(" ft: %d | pf: %d\n", r1, r2);

    printf(SEP "CHAR" SEP);
    r1 = ft_printf("Char: [%c]\n", 'A');
    r2 = printf("Char: [%c]\n", 'A');
    printf(" ft: %d | pf: %d\n", r1, r2);

    printf(SEP "CHAR = \\0" SEP);
    r1 = ft_printf("Char: [%c]\n", '\0');
    r2 = printf("Char: [%c]\n", '\0');
    printf(" ft: %d | pf: %d\n", r1, r2);

    printf(SEP "STRING" SEP);
    r1 = ft_printf("String: [%s]\n", "Hello");
    r2 = printf("String: [%s]\n", "Hello");
    printf(" ft: %d | pf: %d\n", r1, r2);

    printf(SEP "STRING = NULL" SEP);
    r1 = ft_printf("String: [%s]\n", NULL);
    r2 = printf("String: [%s]\n", NULL);
    printf(" ft: %d | pf: %d\n", r1, r2);

    printf(SEP "INT" SEP);
    r1 = ft_printf("Int: %d %i\n", 42, -42);
    r2 = printf("Int: %d %i\n", 42, -42);
    printf(" ft: %d | pf: %d\n", r1, r2);

    printf(SEP "INT LIMITS" SEP);
    r1 = ft_printf("INT_MIN: %d\nINT_MAX: %d\n", INT_MIN, INT_MAX);
    r2 = printf("INT_MIN: %d\nINT_MAX: %d\n", INT_MIN, INT_MAX);
    printf(" ft: %d | pf: %d\n", r1, r2);

    printf(SEP "UNSIGNED" SEP);
    r1 = ft_printf("Unsigned: %u\n", UINT_MAX);
    r2 = printf("Unsigned: %u\n", UINT_MAX);
    printf(" ft: %d | pf: %d\n", r1, r2);

    printf(SEP "HEXA" SEP);
    r1 = ft_printf("Hex: %x %X\n", 42, 42);
    r2 = printf("Hex: %x %X\n", 42, 42);
    printf(" ft: %d | pf: %d\n", r1, r2);

    printf(SEP "POINTER" SEP);
    r1 = ft_printf("Pointer: %p\n", ptr);
    r2 = printf("Pointer: %p\n", ptr);
    printf(" ft: %d | pf: %d\n", r1, r2);

    printf(SEP "POINTER NULL" SEP);
    r1 = ft_printf("Pointer: %p\n", NULL);
    r2 = printf("Pointer: %p\n", NULL);
    printf(" ft: %d | pf: %d\n", r1, r2);

    printf(SEP "MIXED" SEP);
    r1 = ft_printf("Mix: %c %s %d %u %x %X %% %p\n",
            'A', "42", -42, 42, 42, 42, ptr);
    r2 = printf("Mix: %c %s %d %u %x %X %% %p\n",
            'A', "42", -42, 42, 42, 42, ptr);
    printf(" ft: %d | pf: %d\n", r1, r2);

    printf(SEP "UNDEFINED (NO CRASH EXPECTED)" SEP);
    ft_printf("%%%\n");
    ft_printf("%\n");
    ft_printf("%q\n");
    ft_printf("hello%\n");
    ft_printf("hello%\n%");
    printf("\n(If you reached this point, no crash 👍)\n");

    return (0);
}
