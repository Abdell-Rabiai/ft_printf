/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:37:06 by arabiai           #+#    #+#             */
/*   Updated: 2022/11/13 12:22:38 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
