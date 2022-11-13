/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:14:33 by arabiai           #+#    #+#             */
/*   Updated: 2022/11/04 15:31:59 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "libft.h"

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*strjoin;
// 	size_t	i;
// 	size_t	len_total;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	i = 0;
// 	len_total = ft_strlen(s1) + ft_strlen(s2);
// 	strjoin = (char *)malloc(sizeof(char) * (len_total + 1));
// 	if (!strjoin)
// 		return (NULL);
// 	ft_strlcpy(strjoin, s1, ft_strlen(s1) + 1);
// 	ft_strlcat(strjoin, s2, len_total + 1);
// 	return (strjoin);
// }
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	strjoin = (char *)malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!strjoin)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		strjoin[i] = s1[i];
		i++;
	}
	while (i < ft_strlen(s1) + ft_strlen(s2))
	{
		strjoin[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	strjoin[i] = '\0';
	return (strjoin);
}
