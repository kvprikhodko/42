/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khotah <khotah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 21:22:14 by khotah            #+#    #+#             */
/*   Updated: 2020/12/06 15:49:42 by khotah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_string_minus(t_flags *flags, const char *str, int len)
{
	ft_putstr(str, len);
	ft_space(flags->width - len, flags);
	flags->counter = flags->counter + len;
}

static void	ft_string_no_minus(t_flags *flags, const char *str, int len)
{
	if (flags->null == 1)
		ft_zeros(flags->width - len, flags);
	else if (flags->null == 0)
		ft_space(flags->width - len, flags);
	ft_putstr(str, len);
	flags->counter = flags->counter + len;
}

void		if_string(t_flags *flags)
{
	const char	*str;
	int			len;

	if (!(str = (const char *)va_arg(flags->ap, char *)))
		str = "(null)";
	len = ft_strlen(str);
	if (flags->precision >= 0 && flags->precision <= len)
		len = flags->precision;
	if (flags->width && flags->minus == 1)
		ft_string_minus(flags, str, len);
	else if (flags->width && flags->minus == 0)
		ft_string_no_minus(flags, str, len);
	else
	{
		ft_putstr(str, len);
		flags->counter = flags->counter + len;
	}
}
