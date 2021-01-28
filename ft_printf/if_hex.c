#include "ft_printf.h"

static void	if_hex_exceptions(t_flags *flags, int len)
{
	if (flags->precision >= 0)
		flags->null = 0;
	if (flags->precision == -1)
		flags->precision = 0;
	if (flags->precision > 0 && flags->precision >= len)
		flags->precision = flags->precision - len;
	else
		flags->precision = 0;
}

static void	if_hex_minus(t_flags *flags, unsigned int nb, int len)
{
	if (flags->precision)
		ft_zeros(flags->precision, flags);
	ft_puthex(nb, flags->type);
	ft_space(flags->width - len - flags->precision, flags);
	flags->counter = flags->counter + len;
}

static void	if_hex_no_minus(t_flags *flags, unsigned int nb, int len)
{
	if (flags->null == 1)
	{
		ft_zeros(flags->width - len, flags);
		ft_puthex(nb, flags->type);
		flags->counter = flags->counter + len;
	}
	else
	{
		ft_space(flags->width - len - flags->precision, flags);
		if (flags->precision)
			ft_zeros(flags->precision, flags);
		ft_puthex(nb, flags->type);
		flags->counter = flags->counter + len;
	}
}

void		if_hex(t_flags *flags)
{
	unsigned int	nb;
	int				len;

	nb = (unsigned int)va_arg(flags->ap, unsigned int);
	len = ft_hexlen(nb);
	if (flags->precision == 0 && nb == 0)
	{
		ft_space(flags->width, flags);
		return ;
	}
	if_hex_exceptions(flags, len);
	if (flags->minus == 1)
		if_hex_minus(flags, nb, len);
	else if (flags->minus == 0)
		if_hex_no_minus(flags, nb, len);
	else
	{
		ft_puthex(nb, flags->type);
		flags->counter = flags->counter + len;
	}
}
