/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 21:39:03 by lnoirot           #+#    #+#             */
/*   Updated: 2022/03/13 13:09:09 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	exec(t_pipex *pipex)
{
	pid_t	pid;
	int		stat_loc;

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
	pid = fork();
	if (!pid)
	{
		dup2(pipex->fd_pipe[0], 0);
		close(pipex->fd_pipe[1]);
		dup2(pipex->fd_2, 1);
		execve(pipex->cmd_2[0], pipex->cmd_2, pipex->env);
	}
	else
		wait(&stat_loc);
	return (0);
}
