/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:33:02 by lnoirot           #+#    #+#             */
/*   Updated: 2022/03/13 17:02:29 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	error_msg(int error)
{
	if (error == OPEN_FAILURE)
		ft_putstr_fd("Open fail to execute\n", 2);
	if (error == STORE_CMD_FAILURE)
		ft_putstr_fd("Fail to store the cmd\n", 2);
	if (error == CMD_NOT_FOUND)
		ft_putstr_fd("Command not found\n", 2);
	if (error == PIPE_FAILURE)
		ft_putstr_fd("Fail to open pipe\n", 2);
	if (error == EXEC_FAIL)
		ft_putstr_fd("Fail to execute\n", 2);
}

int	main(int ac, char **av, char **env)
{
	t_pipex		pipex;
	int			error;

	if (ac != 5)
	{
		ft_putstr_fd("Wrond number of argument\n", 2);
		return (1);
	}
	ft_memset(&pipex, 0, sizeof(t_pipex));
	error = parsing(&pipex, &av[1], env);
	if (error)
	{
		error_msg(error);
		free_pipex(&pipex);
		return (1);
	}
	error = exec(&pipex);
	if (error)
	{
		error_msg(error);
		free_pipex(&pipex);
		return (1);
	}
	free_pipex(&pipex);
	return (0);
}
