/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:39:52 by lnoirot           #+#    #+#             */
/*   Updated: 2022/03/12 22:34:48 by lnoirot          ###   ########.fr       */
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

int		find_char_index(char *str, char c)
{
	int	ret;

	ret = 0;
	if (!str)
		return (0);
	while (str[ret] && str[ret] != c)
		ret++;
	return (ret);
}

char	*find_var_value(char *key, char **env)
{
	char	*value;
	int		i;

	i = 0;
	if (!env)
		return (NULL);
	while (ft_strncmp(key, env[i], ft_strlen(key)))
		i++;
	if (!env[i])
		return (NULL);
	value = ft_strdup(&env[i][find_char_index(env[i], '=')]);
	return (value);
}

int	try_path(char *to_try, char *name)
{
	char	*path;
	char	*tmp;
	int		ret;

	
	tmp = to_try;
	to_try = ft_strjoin(to_try, "/");
	free(tmp);
	path = ft_strjoin(to_try, name);
	ret = access(path, X_OK);
	// free (path);
	return (ret);
}

int	path_solver(char *path_env, char **cmd)
{
	char	**path_lst;
	char	*tmp;
	int		i;

	if (!path_env)
		return (1);
	i = 0;
	path_lst = ft_split(path_env, ":");
	while (path_lst[i])
	{
		if (!try_path(path_lst[i], cmd[0]))
		{
			tmp = cmd[0];
			cmd[0] = ft_strdup(path_lst[i]);
			// free_str_table(path_lst);
			return (0);
		}
		i++;
	}
	// free_str_table(path_lst);
	// free(path_env);
	return (1);
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
		return (1);
	// free(path_env);
	return (0);
}

int	parsing(t_pipex *pipex, char **cmd, char **env)
{
	if (open_fd(cmd[0], cmd[3], pipex))
		return (OPEN_FAILURE);
	if (store_cmd(cmd[1], cmd[2], pipex))
		return (1);
	pipex->env = env;
	if (find_cmd_path(pipex, pipex->cmd_1) || find_cmd_path(pipex, pipex->cmd_2))
		return (1);
	return (0);
}
