/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:38:00 by lnoirot           #+#    #+#             */
/*   Updated: 2022/03/13 15:09:39 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H

# define PARSING_H

# include <fcntl.h>

# define UMASK_MODE_OPEN 436

int		find_char_index(char *str, char c);
char	*find_var_value(char *key, char **env);
int		try_path(char **to_try, char *name);
int		path_solver(char *path_env, char **cmd);

#endif