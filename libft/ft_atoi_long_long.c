/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long_long.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellacroi <ellacroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:09:19 by ellacroi          #+#    #+#             */
/*   Updated: 2021/06/25 18:10:58 by ellacroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi_long_long(const char *str)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	while (*str == '\f' || *str == '\n' || *str == '\r' \
	|| *str == '\t' || *str == '\v' || *str == ' ')
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
		num = num * 10 + *str++ - '0';
	return (num * sign);
}
