/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:24:14 by arabiai           #+#    #+#             */
/*   Updated: 2022/10/30 12:03:25 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n > 0)
	{
		if ((unsigned char)c == *(unsigned char *)s)
			return ((unsigned char *)s);
		n--;
		s++;
	}
	return (NULL);
}
