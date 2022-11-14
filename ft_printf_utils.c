/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:23:27 by arabiai           #+#    #+#             */
/*   Updated: 2022/11/14 14:23:42 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd_count(char c, int fd, int *count)
{
	write(fd, &c, 1);
	(*count)++;
}

void	ft_putnbr_fd_count(int n, int fd, int *count)
{
	long	nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar_fd_count('-', fd, count);
		nb *= -1;
	}
	if (nb < 10)
		ft_putchar_fd_count(nb + '0', fd, count);
	else
	{
		ft_putnbr_fd_count(nb / 10, fd, count);
		ft_putnbr_fd_count(nb % 10, fd, count);
	}
}

void	ft_putnbr_fd_hexa_count(size_t nb, int fd, int *count, char c)
{
	size_t	hex;

	hex = 0;
	if (c != 'p')
	{
		nb = (unsigned int)nb;
		hex = (unsigned int)hex;
	}
	if (nb == 0)
		return ;
	else
	{
		hex = nb % 16;
		ft_putnbr_fd_hexa_count(nb / 16, fd, count, c);
	}
	if (hex < 10)
		ft_putchar_fd_count(hex + '0', fd, count);
	else
	{
		if (c == 'X')
			ft_putchar_fd_count(hex + 55, fd, count);
		if (c == 'x' || c == 'p')
			ft_putchar_fd_count(hex + 87, fd, count);
	}
}

void	ft_putnbr_fd_uns_count(unsigned int n, int fd, int *count)
{
	if (n < 10)
		ft_putchar_fd_count(n + '0', fd, count);
	else
	{
		ft_putnbr_fd_uns_count(n / 10, fd, count);
		ft_putnbr_fd_uns_count(n % 10, fd, count);
	}
}

void	ft_putstr_fd_count(char *s, int fd, int *count)
{
	if (!s)
		return ;
	while (*s)
	{
		ft_putchar_fd_count(*s, fd, count);
		s++;
	}
}
