#include "ft_printf.h"

void	ft_type(t_flags *flags)
{
	if (flags->type == 'c')
		if_char(flags);
	else if (flags->type == 's')
		if_string(flags);
	else if (flags->type == 'p')
		if_pointer(flags);
	else if (flags->type == 'd' || flags->type == 'i')
		if_int(flags);
	else if (flags->type == 'u')
		if_uns_int(flags);
	else if (flags->type == 'x' || flags->type == 'X')
		if_hex(flags);
	else if (flags->type == '%')
		if_percent(flags);
	else
		write(1, &flags->type, 1);
}

void	ft_space(int n, t_flags *flags)
{
	while (n > 0)
	{
		write(1, " ", 1);
		n--;
		flags->counter++;
	}
}

void	ft_zeros(int n, t_flags *flags)
{
	while (n > 0)
	{
		write(1, "0", 1);
		n--;
		flags->counter++;
	}
}
