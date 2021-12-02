/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellacroi <ellacroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:04:50 by ellacroi          #+#    #+#             */
/*   Updated: 2021/06/09 12:03:55 by ellacroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static size_t	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	*ft_free_split(char **tab, int index)
{
	while (index--)
		free(tab[index]);
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char		**tab;
	size_t		index;
	size_t		i;

	index = 0;
	tab = malloc(sizeof(*tab) * (word_count(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	tab[word_count(s, c)] = 0;
	while (*s)
	{
		i = 0;
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		tab[index] = malloc(sizeof(char) * ((word_len(s, c) + 1)));
		if (tab[index] == NULL)
			return (ft_free_split(tab, index));
		while (*s && *s != c)
			tab[index][i++] = *s++;
		tab[index++][i] = '\0';
	}
	return (tab);
}
