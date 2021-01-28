#include "ft_printf.h"

void	zero_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->null = 0;
	flags->width = 0;
	flags->precision = -1;
	flags->type = 0;
}

void	ft_flags(const char *str, t_flags *flags)
{
	if (str[flags->i] == ' ')
	{
		write(1, " ", 1);
		flags->counter++;
	}
	while (str[flags->i] == ' ')
		flags->i = flags->i + 1;
	while (ft_strchr("-0", str[flags->i]))
	{
		if (str[flags->i] == '-')
		{
			flags->minus = 1;
			flags->null = 0;
		}
		if (str[flags->i] == '0')
		{
			if (flags->minus != 1)
				flags->null = 1;
			else
				flags->null = 0;
		}
		flags->i++;
	}
}

int		ft_specifiers(const char *str, t_flags *flags)
{
	int nb;

	nb = 0;
	if (str[flags->i] == '*')
	{
		nb = va_arg(flags->ap, int);
		while (str[flags->i] == '*')
			flags->i++;
	}
	while (str[flags->i] >= '0' && str[flags->i] <= '9')
	{
		nb = nb * 10 + str[flags->i] - 48;
		flags->i++;
	}
	return (nb);
}

void	ft_parser(const char *str, t_flags *flags)
{
	flags->i = flags->i + 1;
	ft_flags(str, flags);
	flags->width = ft_specifiers(str, flags);
	if (flags->width < 0)
	{
		flags->width = -(flags->width);
		flags->minus = 1;
		flags->null = 0;
	}
	if (str[flags->i] == '.')
	{
		flags->i = flags->i + 1;
		flags->precision = ft_specifiers(str, flags);
	}
	if (str[flags->i])
	{
		flags->type = str[flags->i];
		flags->i++;
	}
	ft_type(flags);
}
