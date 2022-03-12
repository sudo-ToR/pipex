/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:33:02 by lnoirot           #+#    #+#             */
/*   Updated: 2022/03/12 22:32:53 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	main(int ac, char **av,char **env)
{
	t_pipex		pipex;
	
	if (ac != 5)
	{
		ft_putstr_fd("Wrond number of argument\n", 2);
		return (1);
	}
	ft_memset(&pipex, 0, sizeof(t_pipex));
	if (parsing(&pipex, &av[1], env))
		return (1);
	exec(&pipex);
	return (0);
}