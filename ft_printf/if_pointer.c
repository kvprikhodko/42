/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khotah <khotah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 21:22:10 by khotah            #+#    #+#             */
/*   Updated: 2020/12/06 15:37:25 by khotah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	if_pointer_zero(t_flags *flags)
{
	if (flags->minus == 0)
		ft_space(flags->width - 2, flags);
	write(1, "0x", 2);
	if (flags->minus == 1)
		ft_space(flags->width - 2, flags);
	flags->counter = flags->counter + 2;
}

static void	if_pointer_exceptions(t_flags *flags)
{
	if (flags->precision >= 0)
		flags->null = 0;
	if (flags->precision == -1)
		flags->precision = 0;
}

static void	if_pointer_minus(t_flags *flags, unsigned long int ptr, int len)
{
	write(1, "0x", 2);
	if (flags->precision)
		ft_zeros(flags->precision, flags);
	ft_puthex(ptr, flags->type);
	ft_space(flags->width - len - flags->precision - 2, flags);
	flags->counter = flags->counter + len + 2;
}

static void	if_pointer_no_minus(t_flags *flags, unsigned long int ptr, int len)
{
	if (flags->null == 1)
	{
		write(1, "0x", 2);
		ft_zeros(flags->width - len - 2, flags);
		ft_puthex(ptr, flags->type);
		flags->counter = flags->counter + len + 2;
	}
	else
	{
		ft_space(flags->width - len - flags->precision - 2, flags);
		write(1, "0x", 2);
		if (flags->precision)
			ft_zeros(flags->precision, flags);
		ft_puthex(ptr, flags->type);
		flags->counter = flags->counter + len + 2;
	}
}

void		if_pointer(t_flags *flags)
{
	unsigned long int	ptr;
	int					len;

	ptr = (unsigned long int)va_arg(flags->ap, unsigned long int);
	len = ft_hexlen(ptr);
	if (ptr == 0 && flags->precision == 0)
	{
		if_pointer_zero(flags);
		return ;
	}
	if_pointer_exceptions(flags);
	if (flags->precision > 0 && flags->precision >= len)
		flags->precision = flags->precision - len;
	else
		flags->precision = 0;
	if (flags->minus == 1)
		if_pointer_minus(flags, ptr, len);
	else if (flags->minus == 0)
		if_pointer_no_minus(flags, ptr, len);
	else
	{
		write(1, "0x", 2);
		ft_puthex(ptr, flags->type);
		flags->counter = flags->counter + len + 2;
	}
}
