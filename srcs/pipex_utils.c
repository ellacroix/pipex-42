/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellacroi <ellacroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:16:06 by ellacroi          #+#    #+#             */
/*   Updated: 2021/11/22 14:24:22 by ellacroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**get_paths(char **env)
{
	int		i;
	char	**paths;

	i = 0;
	while (env[i++])
		if (ft_strncmp("PATH=", env[i - 1], 5) == 0)
			paths = ft_split(env[i - 1] + 5, ':');
	return (paths);
}

char	*get_cmd_path(char *cmd, char **env)
{
	int		i;
	int		fd;
	char	**paths;
	char	**cmds;
	char	*path_cmd;

	paths = get_paths(env);
	cmds = ft_split(cmd, ' ');
	if (paths == NULL || cmds == NULL)
		ft_handle_error("Error in get_cmd_path", 1);
	i = 0;
	while (paths[i++])
	{
		path_cmd = ft_strjoin_add_slash(paths[i - 1], cmds[0]);
		fd = open(path_cmd, O_RDONLY);
		if (fd >= 0)
			break ;
		free(path_cmd);
	}
	ft_free_split(paths);
	ft_free_split(cmds);
	if (fd < 0)
		ft_handle_error("Command not found\n", 127);
	return (path_cmd);
}

int	ft_exec(char *cmd, char **env)
{
	char	*path;
	char	**cmds;

	path = get_cmd_path(cmd, env);
	cmds = ft_split(cmd, ' ');
	execve(path, cmds, env);
	return (0);
}
