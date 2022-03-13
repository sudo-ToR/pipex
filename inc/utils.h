/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:46:27 by lnoirot           #+#    #+#             */
/*   Updated: 2022/03/13 12:01:09 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H

# define UTILS_H

# include <unistd.h>

size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
void	*ft_memset(void *s, int c, size_t n);
char	**ft_split(char *str, char *charset);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
void	free_str_table(char **to_free);
char	*ft_strrchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif