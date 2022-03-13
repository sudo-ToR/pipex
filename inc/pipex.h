/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:33:30 by lnoirot           #+#    #+#             */
/*   Updated: 2022/03/13 16:34:51 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include "parsing.h"
# include "utils.h"
# include "exec.h"

# include <stdlib.h>
# include <unistd.h>

# define OPEN_FAILURE 1
# define STORE_CMD_FAILURE 2
# define CMD_NOT_FOUND 3
# define PIPE_FAILURE 4

typedef struct s_pipex
{
	char	**env;
	int		fd_1;
	int		fd_2;
	char	**cmd_1;
	char	**cmd_2;
	int		fd_pipe[2];
}	t_pipex;

int		parsing(t_pipex *pipe, char **cmd, char **env);
int		exec(t_pipex *pipex);
void	free_pipex(t_pipex *to_free);
void	error_msg(int error);

#endif