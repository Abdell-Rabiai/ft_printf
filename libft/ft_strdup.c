/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:36:07 by arabiai           #+#    #+#             */
/*   Updated: 2022/10/31 13:57:26 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*copy;
	size_t	i;

	i = 0;
	copy = (char *)malloc(ft_strlen((char *)src) * sizeof(char) + 1);
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, (char *)src, ft_strlen((char *)src) + 1);
	return (copy);
}
