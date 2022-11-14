/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:23:27 by arabiai           #+#    #+#             */
/*   Updated: 2022/11/14 19:02:08 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd_count(char c, int fd, int *count)
{
	write(fd, &c, 1);
	(*count)++;
}

void	ft_putnbr_base16(size_t nb, int fd, int *count, char c)
{
	size_t	base_len;
	char	*base16;

	base_len = 16;
	if (c == 'X')
		base16 = "0123456789ABCDEF";
	else if (c == 'x' || c == 'p')
		base16 = "0123456789abcdef";
	if (c != 'p')
		nb = (unsigned int)nb;
	if (nb < base_len)
		ft_putchar_fd_count(base16[nb % base_len], fd, count);
	else
	{
		ft_putnbr_base16(nb / base_len, fd, count, c);
		ft_putnbr_base16(nb % base_len, fd, count, c);
	}
}

void	ft_putnbr_base10(int n, int fd, int *count)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd_count('-', fd, count);
		nb *= -1;
	}
	if (nb < 10)
		ft_putchar_fd_count(nb + 48, fd, count);
	else
	{
		ft_putnbr_base10(nb / 10, fd, count);
		ft_putnbr_base10(nb % 10, fd, count);
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
	{
		ft_putstr_fd_count("(null)", fd, count);
		return ;
	}
	while (*s)
	{
		ft_putchar_fd_count(*s, fd, count);
		s++;
	}
}
