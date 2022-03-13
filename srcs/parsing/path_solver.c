/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_solver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:05:59 by lnoirot           #+#    #+#             */
/*   Updated: 2022/03/13 17:33:59 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	try_path(char **to_try, char *name)
{
	char	*tmp;
	int		ret;

	tmp = *to_try;
	*to_try = ft_strjoin(*to_try, "/");
	free(tmp);
	tmp = *to_try;
	*to_try = ft_strjoin(*to_try, name);
	free(tmp);
	if (!*to_try)
		return (1);
	ret = access(*to_try, X_OK);
	return (ret);
}

int	path_solver(char *path_env, char **cmd)
{
	char	**path_lst;
	int		i;
	char	*tmp;

	if (!path_env)
		return (1);
	i = 0;
	path_lst = ft_split(path_env, ":");
	while (path_lst[i])
	{
		if (!try_path(&path_lst[i], cmd[0]))
		{
			tmp = cmd[0];
			cmd[0] = ft_strdup(path_lst[i]);
			free(tmp);
			free_str_table(path_lst);
			return (0);
		}
		i++;
	}
	free_str_table(path_lst);
	return (1);
}
