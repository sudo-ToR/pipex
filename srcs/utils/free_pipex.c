/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:29:41 by lnoirot           #+#    #+#             */
/*   Updated: 2022/03/13 17:09:12 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_pipex(t_pipex *to_free)
{
	if (to_free->fd_1 != -1)
		close(to_free->fd_1);
	if (to_free->fd_2 != -1)
		close(to_free->fd_2);
	free_str_table(to_free->cmd_1);
	free_str_table(to_free->cmd_2);
	if (to_free->fd_pipe[0] != -1)
		close(to_free->fd_pipe[0]);
	if (to_free->fd_pipe[1] != -1)
		close(to_free->fd_pipe[1]);
}
