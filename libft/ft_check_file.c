/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellacroi <ellacroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 18:00:33 by ellacroi          #+#    #+#             */
/*   Updated: 2021/02/21 19:54:57 by ellacroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	ft_check_file(char *str)
{
	int	fd;

	fd = open(str, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		return (0);
	}
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	fd = open(str, O_WRONLY);
	if (fd == -1)
		return (2);
	close(fd);
	return (3);
}

/*
**int main(int argc, char **argv)
**{
**	printf("Return value is %i\n", ft_check_file(argv[1]));
**}
*/
/*
**0 is a directory
**1 is unreadable
**2 is unwrittable
**3 is readable and writtable
*/
