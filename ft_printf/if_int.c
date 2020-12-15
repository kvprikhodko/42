/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khotah <khotah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 21:22:07 by khotah            #+#    #+#             */
/*   Updated: 2020/12/06 15:37:20 by khotah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	if_int_exceptions(t_flags *flags, int nb, int len)
{
	if (flags->precision >= 0)
		flags->null = 0;
	if (flags->precision == -1)
		flags->precision = 0;
	if (flags->precision > 0 && flags->precision >= len)
	{
		if (nb < 0)
			flags->precision = flags->precision - len + 1;
		else
			flags->precision = flags->precision - len;
	}
	else
		flags->precision = 0;
}

static void	if_int_minus(t_flags *flags, int nb, int len)
{
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	if (flags->precision)
		ft_zeros(flags->precision, flags);
	ft_putnbr(nb);
	ft_space(flags->width - len - flags->precision, flags);
	flags->counter = flags->counter + len;
}

static void	if_int_no_minus(t_flags *flags, int nb, int len)
{
	if (flags->null == 1)
	{
		if (nb < 0)
		{
			nb = -nb;
			write(1, "-", 1);
		}
		ft_zeros(flags->width - len, flags);
		ft_putnbr(nb);
		flags->counter = flags->counter + len;
	}
	else
	{
		ft_space(flags->width - len - flags->precision, flags);
		if (nb < 0)
		{
			nb = -nb;
			write(1, "-", 1);
		}
		if (flags->precision)
			ft_zeros(flags->precision, flags);
		ft_putnbr(nb);
		flags->counter = flags->counter + len;
	}
}

void		if_int(t_flags *flags)
{
	int nb;
	int len;

	nb = (int)va_arg(flags->ap, int);
	len = ft_intlen(nb);
	if (flags->precision == 0 && nb == 0)
	{
		ft_space(flags->width, flags);
		return ;
	}
	if_int_exceptions(flags, nb, len);
	if (flags->minus == 1)
		if_int_minus(flags, nb, len);
	else if (flags->minus == 0)
		if_int_no_minus(flags, nb, len);
	else
	{
		if (nb < 0)
		{
			nb = -nb;
			write(1, "-", 1);
		}
		ft_putnbr(nb);
		flags->counter = flags->counter + len;
	}
}
