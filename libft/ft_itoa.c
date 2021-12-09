/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellacroi <ellacroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:44:03 by ellacroi          #+#    #+#             */
/*   Updated: 2021/12/09 16:33:04 by ellacroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*str;
	size_t			neg;
	unsigned int	u_n;
	int				size;

	neg = 0;
	if (n < 0)
		neg = 1;
	u_n = n;
	if (n < 0)
		u_n = -n;
	size = 1;
	while (n)
	{
		n /= 10;
		size++;
	}
	str = (char *)malloc(sizeof(char) * (size + 1 + neg));
	if (str == NULL)
		return (NULL);
	return (ft_itoa2(str, size, u_n, neg));
}
