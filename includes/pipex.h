/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellacroi <ellacroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 09:58:35 by gcollet           #+#    #+#             */
/*   Updated: 2021/11/22 15:04:32 by ellacroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"

char		*get_cmd_path(char *cmd, char **env);
char		**get_paths(char **env);
int			ft_exec(char *cmd, char **env);

void		ft_handle_error(char *str, int error_code);
void		ft_free_split(char **tab);
char		*ft_strjoin_add_slash(char const *s1, char const *s2);

#endif
