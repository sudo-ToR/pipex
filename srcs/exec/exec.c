/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 21:39:03 by lnoirot           #+#    #+#             */
/*   Updated: 2022/03/13 13:59:36 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	create_second_child(t_pipex *pipex)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (EXEC_FAIL);
	if (!pid)
	{
		dup2(pipex->fd_pipe[0], 0);
		close(pipex->fd_pipe[1]);
		dup2(pipex->fd_2, 1);
		execve(pipex->cmd_2[0], pipex->cmd_2, pipex->env);
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
		dup2(pipex->fd_pipe[1], 1);
		close(pipex->fd_pipe[0]);
		dup2(pipex->fd_1, 0);
		execve(pipex->cmd_1[0], pipex->cmd_1, pipex->env);
	}
	return (0);
}

int	exec(t_pipex *pipex)
{
	int		stat_loc;

	if (create_first_child(pipex))
		return (EXEC_FAIL);
	if (create_second_child(pipex))
		return (EXEC_FAIL);
	wait(&stat_loc);
	return (0);
}
