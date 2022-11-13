/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:37:29 by arabiai           #+#    #+#             */
/*   Updated: 2022/11/13 12:46:14 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
