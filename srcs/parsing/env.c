/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:03:49 by lnoirot           #+#    #+#             */
/*   Updated: 2022/03/13 12:05:24 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	find_char_index(char *str, char c)
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
