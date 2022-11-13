/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:36:58 by arabiai           #+#    #+#             */
/*   Updated: 2022/11/02 14:35:39 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned int	i;

	i = 0;
	if (dst == src)
		return (dst);
	if (dst > src)
	{
		while (n-- > 0)
			((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
