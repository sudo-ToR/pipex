/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:39:52 by lnoirot           #+#    #+#             */
/*   Updated: 2022/03/12 17:43:36 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
int	open_fd(char *fd_1, char *fd_2, t_pipex *pipex)
{
	pipex->fd_1 = open(fd_1, O_RDONLY);
	if (pipex->fd_1 < 0)
		return (OPEN_FAILURE);
	pipex->fd_2 = open(fd_2, O_CREAT | O_WRONLY | O_TRUNC, UMASK_MODE_OPEN);
	if (pipex->fd_2 < 0)
		return (OPEN_FAILURE);
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
		return (1);
	return (0);
}

char	*translate_var_env(char *to_translate)
{
	char	*value;
	int		i;

	i = 0;
	if (!to_translate)
		return (NULL);
	while (to_translate[i] && to_translate[i] != '=')
		i++;
	
	value = ft_strdup(&to_translate[i + 1]);
	return (value);
}

char	*find_var_value(char **env, char *var_name)
{
	int		i;
	char	*var_value;

	i = 0;
	while (env[i] && ft_strncmp(var_name, env[i], ft_strlen(var_name)))
		i++;
	var_value = translate_var_env(env[i]);
	return(var_value);
}

int	find_path(t_pipex *pipex)
{
	char *path_lst;
	
	path_lst = find_var_value(pipex->env, "PATH");
	free(path_lst);
	return (0);
}

int	parsing(t_pipex *pipex, char **cmd, char **env)
{
	if (open_fd(cmd[0], cmd[3], pipex))
		return (OPEN_FAILURE);
	if (store_cmd(cmd[1], cmd[2], pipex))
		return (1);
	pipex->env = env;
	if (find_path(pipex))
		return (1);
	return (0);
}
