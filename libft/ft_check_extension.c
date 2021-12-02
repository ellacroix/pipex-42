/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellacroi <ellacroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 19:18:38 by ellacroi          #+#    #+#             */
/*   Updated: 2021/02/19 19:22:22 by ellacroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_extension(char *file, char *extension)
{
	char	*p;

	p = file;
	p = ft_strrchr(file, '.');
	if (p == NULL || ft_strncmp(p, extension, ft_strlen(extension) + 1) != 0)
		return (1);
	return (0);
}
