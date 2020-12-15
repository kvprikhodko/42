/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khotah <khotah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:02:15 by khotah            #+#    #+#             */
/*   Updated: 2020/12/06 15:37:22 by khotah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_percent_minus(t_flags *flags, int n)
{
	n = flags->width - 1;
	write(1, "%", 1);
	ft_space(n, flags);
	flags->counter++;
}

static void	ft_percent_no_minus(t_flags *flags, int n)
{
	n = flags->width - 1;
	if (flags->null == 1)
		ft_zeros(n, flags);
	else if (flags->null == 0)
		ft_space(n, flags);
	write(1, "%", 1);
	flags->counter++;
}

void		if_percent(t_flags *flags)
{
	int	n;

	n = 0;
	if (flags->width && flags->minus == 1)
		ft_percent_minus(flags, n);
	else if (flags->width && flags->minus == 0)
		ft_percent_no_minus(flags, n);
	else
	{
		write(1, "%", 1);
		flags->counter++;
	}
}
