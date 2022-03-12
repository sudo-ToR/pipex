/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:22:19 by lnoirot           #+#    #+#             */
/*   Updated: 2022/03/12 20:22:47 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	int		j;

	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	r = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!r)
		return (NULL);
	while (*s1)
	{
		r[j++] = *s1;
		s1++;
	}
	while (*s2)
	{
		r[j++] = *s2;
		s2++;
	}
	r[j] = '\0';
	return (r);
}
