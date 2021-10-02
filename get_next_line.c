/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:55:00 by jmilson-          #+#    #+#             */
/*   Updated: 2021/10/01 21:48:08 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>

// static char	*funcao_que_trata(int fd, char *bbackup, char *buffer);

/*Essa função retorna uma linha*/
/*
/param File descriptor to read from
/return Read line: correct behavior
NULL: nothing else to read or an error occurred
*/
char	*get_next_line(int fd)
{
	char static	*bbackup;
	char		*buffer;
	char		*line;
	size_t		read_chars;
	size_t		pos_n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup("");
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (!ft_strchr(line, '\n'))
	{
		read_chars = read(fd, buffer, BUFFER_SIZE);
		buffer[read_chars] = 0;
		line = ft_strjoin(line, buffer);
	}
	pos_n = ft_strclen(line, '\n');
	char *banana = ft_strdup(line + pos_n + 1);

	printf("banana: |%s|", banana);
	return (line);
}
