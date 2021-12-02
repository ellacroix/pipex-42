/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellacroi <ellacroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:56:30 by ellacroi          #+#    #+#             */
/*   Updated: 2021/06/09 11:25:49 by ellacroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	u_n;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		u_n = (unsigned int) -n;
	}
	else
		u_n = (unsigned int)n;
	if (u_n >= 10)
		ft_putnbr_fd(u_n / 10, fd);
	ft_putchar_fd(u_n % 10 + '0', fd);
}
