/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khotah <khotah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 21:22:21 by khotah            #+#    #+#             */
/*   Updated: 2020/12/06 15:37:35 by khotah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *str, int len)
{
	while (*str != '\0' && len > 0)
	{
		write(1, str++, 1);
		len--;
	}
}

void	ft_putnbr(unsigned int nb)
{
	long int n;

	n = nb;
	if (n < 0)
		n = -n;
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

void	ft_putchar_hex(int c, char type)
{
	if (c >= 0 && c <= 9)
		c = c + 48;
	else if (type == 'X')
		c = c + 55;
	else if (type == 'x' || type == 'p')
		c = c + 87;
	write(1, &c, 1);
}

void	ft_puthex(unsigned long int n, char type)
{
	if (n >= 16)
	{
		ft_puthex(n / 16, type);
		ft_putchar_hex(n % 16, type);
	}
	else
		ft_putchar_hex(n, type);
}
