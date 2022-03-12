/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:33:30 by lnoirot           #+#    #+#             */
/*   Updated: 2022/03/12 17:26:08 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include "parsing.h"
# include "utils.h"

#include <stdlib.h>
#include <unistd.h>

# define OPEN_FAILURE 1

typedef struct s_pipex
{
    char    **env;
    int     fd_1;
    int     fd_2;
    char    **cmd_1;
    char    **cmd_2;
}              t_pipex;

int	parsing(t_pipex *pipe, char **cmd, char **env);

#endif