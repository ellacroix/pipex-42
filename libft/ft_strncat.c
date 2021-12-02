/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellacroi <ellacroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 21:24:27 by ellacroi          #+#    #+#             */
/*   Updated: 2021/06/21 22:27:06 by ellacroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, char *src, size_t nb)
{
	char	*d;

	d = dest;
	while (*d)
		d++;
	while (*src && nb)
	{
		*d = *src;
		src++;
		d++;
		nb--;
	}
	*d = 0;
	return (dest);
}
