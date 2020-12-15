#include "ft_printf.h"
#include <stdio.h>

// gcc -Wall -Wextra -Werror main.c ft_printf.c ft_parser.c ft_type.c if_char.c if_string.c if_percent.c if_uns_int.c if_hex.c if_pointer.c if_int.c libft.c
// gcc main.c ft_printf.c ft_parser.c ft_type.c if_char.c if_string.c if_percent.c if_uns_int.c if_hex.c if_pointer.c if_int.c libft.c

// gcc -Wall -Wextra -Werror main.c libftprintf.a

int	main(void)
{
//	%
//	int i = printf("%010.5%%%\n");
//	int k = ft_printf("%010.5%%%\n");
//	printf("\ncounter1 = %d\n", i);
//	printf("counter2 = %d\n", k);

//	char
	int i = printf("%10c%c\n", 'r', 'a');
	int k = ft_printf("%10c%c\n", 'r', 'a');
	printf("\ncounter1 = %d\n", i);
	printf("counter2 = %d\n", k);

//	string
//	char *str = "qwerty";
//	ft_printf("%.*s\n", 15, &str);
//	int i = printf("%15s\n", NULL);
//	int k = ft_printf("%15s\n", NULL);
//	printf("\ncounter1 = %d\n", i);
//	printf("counter2 = %d\n", k);

//	unsigned int
//	int i = printf("prtf = %-3.7u\n", 2345);
//	int k = ft_printf("ft_p = %-3.7u\n", 2345);
//	printf("counter1 = %d\n", i);
//	printf("counter2 = %d\n", k);

//	unsigned int
//	int i = printf("prtf = %-30.u\n", 2345);
//	int k = ft_printf("ft_p = %-30.u\n", 2345);
//	int I = printf("prtf = %-3.7X\n", -2345);
//	int K = ft_printf("ft_p = %-3.7X\n", -2345);
//	printf("counter1 = %d\n", i);
//	printf("counter2 = %d\n", k);
//	printf("counter1 = %d\n", I);
//	printf("counter2 = %d\n", K);

//	pointer
//	char *str = "qwerty";
//	int i = printf("prtf = %-15p\n", &str);
//	int k = ft_printf("ft_p = %-15p\n", &str);
//	int i = printf("prtf = %-15.p\n", NULL);
//	int k = ft_printf("ft_p = %-15.p\n", NULL);
//	printf("counter1 = %d\n", i);
//	printf("counter2 = %d\n", k);

//	int
//	int i = printf("prtf = %-4.0i, %-4.0d, %-4.0d, %-4.0d, %-4.0d, %-4.0s, %-4.0c, %-4.0d, %-4.0u, %-4.0x, %-4.0X\n", 8, -12, 123456789, 0, -12345678, "abcdefghijklmnop", 'a', 97, 4294967284, 4294967284, 4294967284);
//	int k = ft_printf("ft_p = %-4.0i, %-4.0d, %-4.0d, %-4.0d, %-4.0d, %-4.0s, %-4.0c, %-4.0d, %-4.0u, %-4.0x, %-4.0X\n", 8, -12, 123456789, 0, -12345678, "abcdefghijklmnop", 'a', 97, 4294967284, 4294967284, 4294967284);
//	int i = printf("prtf = %0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d\n", 8, -12, 123456789, 0, -12345678, 97, -2147483648, 2147483647);
//	int k = ft_printf("ft_p = %0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d\n", 8, -12, 123456789, 0, -12345678, 97, -2147483648, 2147483647);
//	printf("counter1 = %d\n", i);
//	printf("counter2 = %d\n", k);
//	printf("%*.*p\n", 10, 5, 12345);
//	ft_printf("%*.*p\n", 10, 5, 12345);

//	int i = ft_printf("test1%-----15.1%7test2%00000.16test3%0-0-017test4%*.*\n", -16, 17);
//	printf("counter = %d\n", i);

	return (0);
}
