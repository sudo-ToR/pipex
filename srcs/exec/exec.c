/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 21:39:03 by lnoirot           #+#    #+#             */
/*   Updated: 2022/03/12 22:48:43 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	*create_pipe()
{
	int	fd_pipe[2];

	if (pipe(fd_pipe) < 0)
		return (NULL);
	return (fd_pipe);
}

int	exec(t_pipex *pipex)
{
	pid_t	pid;
	int		stat_loc;

	pid = fork();
	if (pid == -1)
		return (EXEC_FAIL);
	if (!pid)
	{
		execve(pipex->cmd_1[0], pipex->cmd_1, pipex->env);
	}
	else
		waitpid(pid, &stat_loc, 0);
	return (0);
}
