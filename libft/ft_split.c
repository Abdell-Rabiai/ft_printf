/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:36:34 by arabiai           #+#    #+#             */
/*   Updated: 2022/10/31 13:05:22 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_how_many_words(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			i++;
		while (*s && *s != c)
			s++;
	}
	return (i);
}

static char	**ft_free_split(char **strings)
{
	int	i;

	i = 0;
	while (strings[i] != 0)
	{
		free(strings[i]);
		i++;
	}
	free(strings);
	return (NULL);
}

static int	ft_get_length_of_word(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s && *s == c)
		s++;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

static char	*return_the_first_word(const char *s, char c)
{
	int		i;
	int		length;
	char	*word;

	i = 0;
	length = ft_get_length_of_word(s, c);
	word = (char *)malloc(sizeof(char) * length + 1);
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, length + 1);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	strings = (char **)malloc(sizeof(char *) * (ft_how_many_words(s, c) + 1));
	if (!strings)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			strings[i] = return_the_first_word(s, c);
			if (!strings[i])
				return (ft_free_split(strings));
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	strings[i] = 0;
	return (strings);
}
