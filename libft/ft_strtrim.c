/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellacroi <ellacroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:15:07 by ellacroi          #+#    #+#             */
/*   Updated: 2021/06/16 14:24:24 by ellacroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrim;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1);
	if (len)
		while (s1[len - 1] && ft_strchr(set, s1[len - 1]))
			len--;
	strtrim = (char *)malloc(sizeof(char) * (len + 1));
	if (strtrim == NULL)
		return (NULL);
	ft_strlcpy(strtrim, s1, len + 1);
	strtrim[len] = '\0';
	return (strtrim);
}
