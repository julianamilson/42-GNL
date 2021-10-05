/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:55:30 by jmilson-          #+#    #+#             */
/*   Updated: 2021/10/05 16:52:32 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 15

/**
 * @brief Write a function which returns a line read from a file descriptor
 * @param FD File descriptor to read from
 * @return Read line, or null if nothing else to read or an error occurred
 */
char	*get_next_line(int fd);

/**
 * @brief looks for the first occurrence of C in the string pointed to by STR.
 * @param STR points to the string to be scanned
 * @param C character to be searched
 */
char	*ft_strchr(const char *str, int c);

/**
 * @brief takes a string as an argument and returns its length.
 * @param S source string
 * @param C character to be searched
 */
size_t	ft_strclen(const char *s, char c);

/**
 * @brief duplicates a string, it copies the STR to a new pointer.
 * @param STR the string to be copied.
 * @return a new address with the same string of str.
 */
char	*ft_strdup(const char *str);

/**
 * @brief Allocates and returns a new string, result of s1s2's concatenation.
 * @param S1 prefix string
 * @param S2 suffix string
 * @return The new string. NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Allocates and returns a substring from the string ’s’.
 * @param S string from which to create the substring.
 * @param START start index of the substring in the string ’s’.
 * @param LEN The maximum length of the substring.
 * @return The substring. NULL if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
