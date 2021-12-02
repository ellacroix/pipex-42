/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellacroi <ellacroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:15:40 by ellacroi          #+#    #+#             */
/*   Updated: 2021/11/22 15:23:57 by ellacroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/* Child process that create a fork and a pipe, put the output inside a pipe
 and then close with the exec function. The main process will change his stdin
 for the pipe file descriptor. */
void	fork_process(char *argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		ft_handle_error("Error: pipe() failed\n", 1);
	pid = fork();
	if (pid == -1)
		ft_handle_error("Error: fork() failed\n", 1);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		ft_exec(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	fdin;
	int	fdout;

	if (argc >= 5)
	{
		i = 2;
		fdout = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		fdin = open(argv[1], O_RDONLY);
		if (fdout == -1 || fdin == -1)
			ft_handle_error("Can't open file", 1);
		dup2(fdin, STDIN_FILENO);
		while (i < argc - 2)
			fork_process(argv[i++], envp);
		dup2(fdout, STDOUT_FILENO);
		ft_exec(argv[argc - 2], envp);
	}
	ft_handle_error("Error: Too little arguments\n", 1);
}
