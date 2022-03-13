/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:39:52 by lnoirot           #+#    #+#             */
/*   Updated: 2022/03/13 15:14:32 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	create_pipe(int fd_pipe[2])
{
	if (pipe(fd_pipe) < 0)
		return (1);
	return (0);
}

int	open_fd(char *fd_1, char *fd_2, t_pipex *pipex)
{
	pipex->fd_1 = open(fd_1, O_RDONLY);
	if (pipex->fd_1 < 0)
		return (OPEN_FAILURE);
	pipex->fd_2 = open(fd_2, O_CREAT | O_WRONLY | O_TRUNC, UMASK_MODE_OPEN);
	if (pipex->fd_2 < 0)
	{
		close(pipex->fd_1);
		return (OPEN_FAILURE);
	}
	return (0);
}

int	store_cmd(char *cmd_1, char *cmd_2, t_pipex *pipex)
{
	if (!cmd_1 || !cmd_2)
		return (1);
	pipex->cmd_1 = ft_split(cmd_1, " \f\t\n\r\v");
	if (!pipex->cmd_1)
		return (1);
	pipex->cmd_2 = ft_split(cmd_2, " \f\t\n\r\v");
	if (!pipex->cmd_2)
	{
		free_str_table(pipex->cmd_1);
		return (1);
	}
	return (0);
}

int	find_cmd_path(t_pipex *pipex, char **cmd)
{
	char	*path_env;

	if (!cmd)
		return (1);
	if (!access(cmd[0], X_OK))
		return (0);
	path_env = find_var_value("PATH", pipex->env);
	if (path_solver(path_env, cmd))
	{
		free(path_env);
		return (1);
	}
	free(path_env);
	return (0);
}

int	parsing(t_pipex *pipex, char **cmd, char **env)
{
	if (open_fd(cmd[0], cmd[3], pipex))
		return (OPEN_FAILURE);
	if (store_cmd(cmd[1], cmd[2], pipex))
		return (STORE_CMD_FAILURE);
	pipex->env = env;
	if (find_cmd_path(pipex, pipex->cmd_1)
		|| find_cmd_path(pipex, pipex->cmd_2))
		return (CMD_NOT_FOUND);
	if (create_pipe(pipex->fd_pipe))
		return (PIPE_FAILURE);
	return (0);
}
