/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 21:39:03 by lnoirot           #+#    #+#             */
/*   Updated: 2022/03/13 17:02:08 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	exit_execution(t_pipex *pipex)
{
	free_pipex(pipex);
	exit(1);
}

int	create_second_child(t_pipex *pipex)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (EXEC_FAIL);
	if (!pid)
	{
		if (!is_fd_valid(pipex->fd_2))
		{
			error_msg(OPEN_FAILURE);
			return (0);
		}
		dup2(pipex->fd_pipe[0], 0);
		close(pipex->fd_pipe[1]);
		dup2(pipex->fd_2, 1);
		execve(pipex->cmd_2[0], pipex->cmd_2, pipex->env);
		exit_execution(pipex);
	}
	return (0);
}

int	create_first_child(t_pipex *pipex)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (EXEC_FAIL);
	if (!pid)
	{
		if (!is_fd_valid(pipex->fd_1))
		{
			error_msg(OPEN_FAILURE);
			return (0);
		}
		dup2(pipex->fd_pipe[1], 1);
		close(pipex->fd_pipe[0]);
		dup2(pipex->fd_1, 0);
		execve(pipex->cmd_1[0], pipex->cmd_1, pipex->env);
		exit_execution(pipex);
	}
	return (0);
}

int	is_fd_valid(int fd)
{
	if (fd >= 0)
		return (1);
	return (0);
}

int	exec(t_pipex *pipex)
{
	int		stat_loc;

	if (create_second_child(pipex))
		return (EXEC_FAIL);
	if (create_first_child(pipex))
		return (EXEC_FAIL);
	wait(&stat_loc);
	return (0);
}
