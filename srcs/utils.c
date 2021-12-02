/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellacroi <ellacroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:16:01 by ellacroi          #+#    #+#             */
/*   Updated: 2021/11/22 15:04:25 by ellacroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_handle_error(char *str, int error_code)
{
	write(2, str, ft_strlen(str));
	exit(error_code);
}

void	ft_free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*ft_strjoin_add_slash(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	strjoin = malloc(sizeof(char) * (len + 2));
	if (strjoin == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		strjoin[i++] = *s1++;
	strjoin[i++] = '/';
	while (*s2)
		strjoin[i++] = *s2++;
	strjoin[i] = '\0';
	return (strjoin);
}
