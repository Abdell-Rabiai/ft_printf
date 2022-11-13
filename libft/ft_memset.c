/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:39:56 by arabiai           #+#    #+#             */
/*   Updated: 2022/11/04 13:48:24 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdio.h>
#include<string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str_b;
	unsigned char x;

	str_b = b;
	x = (unsigned char)c;
	while (len--)
		*str_b++ = x;
	return (b);
}
