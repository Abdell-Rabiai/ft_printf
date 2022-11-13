/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:35:20 by arabiai           #+#    #+#             */
/*   Updated: 2022/10/19 15:15:14 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dest_length;
	size_t	src_length;

	i = 0;
	if ((!dst && !dstsize))
		return (0);
	dest_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	if (dstsize <= dest_length)
		return (src_length + dstsize);
	while (i < dstsize - dest_length - 1 && src[i] != '\0')
	{
		dst[i + dest_length] = src[i];
		i++;
	}
	dst[i + dest_length] = '\0';
	return (dest_length + src_length);
}
