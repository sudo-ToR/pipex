/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:32:45 by lnoirot           #+#    #+#             */
/*   Updated: 2022/03/12 17:32:53 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	size;
	char	*tmp;

	tmp = (char *)s;
	size = ft_strlen(tmp);
	while (size != 0 && tmp[size] != c)
		size--;
	if (tmp[size] != c)
		return (NULL);
	return (&tmp[size]);
}
