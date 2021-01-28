#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	t_flags flags;

	flags.i = 0;
	flags.counter = 0;
	va_start(flags.ap, str);
	while (str[flags.i] != '\0')
	{
		zero_flags(&flags);
		while (str[flags.i] && str[flags.i] != '%')
		{
			write(1, &str[flags.i], 1);
			flags.i++;
			flags.counter++;
		}
		if (str[flags.i] == '%')
			ft_parser(str, &flags);
	}
	va_end(flags.ap);
	return (flags.counter);
}
