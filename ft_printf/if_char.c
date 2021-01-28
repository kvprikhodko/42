#include "ft_printf.h"

static void	ft_char_minus(t_flags *flags, unsigned char c, int n)
{
	n = flags->width - 1;
	write(1, &c, 1);
	ft_space(n, flags);
	flags->counter++;
}

static void	ft_char_no_minus(t_flags *flags, unsigned char c, int n)
{
	n = flags->width - 1;
	if (flags->null == 1)
		ft_zeros(n, flags);
	else if (flags->null == 0)
		ft_space(n, flags);
	write(1, &c, 1);
	flags->counter++;
}

void		if_char(t_flags *flags)
{
	unsigned char	c;
	int				n;

	n = 0;
	c = (unsigned char)va_arg(flags->ap, int);
	if (flags->width && flags->minus == 1)
		ft_char_minus(flags, c, n);
	else if (flags->width && flags->minus == 0)
		ft_char_no_minus(flags, c, n);
	else
	{
		write(1, &c, 1);
		flags->counter++;
	}
}
