/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:55:30 by jmilson-          #+#    #+#             */
/*   Updated: 2021/10/04 20:56:12 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

/**
 * @brief Write a function which returns a line read from a file descriptor
 * @param FD File descriptor to read from
 * @return Read line, or null if nothing else to read or an error occurred
 */
char	*get_next_line(int fd);

/**
 * @brief Allocates and returns a new string, result of s1s2's concatenation.
 * @param S1 prefix string
 * @param S2 suffix string
 * @return The new string. NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strchr(const char *str, int c);

char	*ft_strdup(const char *str);

size_t	ft_strclen(const char *s, char c);

char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
