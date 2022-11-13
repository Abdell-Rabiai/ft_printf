/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:42:33 by arabiai           #+#    #+#             */
/*   Updated: 2022/11/01 11:49:46 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	c;

	if (size >= SIZE_MAX || count >= SIZE_MAX)
		return (NULL);
	c = size * count;
	p = (char *)malloc(c);
	if (!p)
		return (0);
	ft_bzero(p, c);
	return (p);
}
