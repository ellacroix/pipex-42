/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellacroi <ellacroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 23:05:55 by ellacroi          #+#    #+#             */
/*   Updated: 2020/11/19 11:59:59 by ellacroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	d_size;

	d_size = 0;
	while (dst[d_size] && d_size < dstsize)
		d_size++;
	i = d_size;
	while (src[d_size - i] && d_size + 1 < dstsize)
	{
		dst[d_size] = src[d_size - i];
		d_size++;
	}
	if (i < dstsize)
		dst[d_size] = '\0';
	return (i + ft_strlen(src));
}
