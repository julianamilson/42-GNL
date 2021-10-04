/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:55:00 by jmilson-          #+#    #+#             */
/*   Updated: 2021/10/04 18:37:25 by jmilson-         ###   ########.fr       */
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
	char		*temp;
	char		*line;
	size_t		read_chars;
	size_t		pos_n;
	size_t		zero;

		if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	temp = ft_strdup("");
	while (!ft_strchr(temp, '\n'))
	{
		read_chars = read(fd, buffer, BUFFER_SIZE);
		if (read_chars == -1 || read_chars == 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_chars] = 0;
		temp = ft_strjoin(temp, buffer);
	}
	pos_n = ft_strclen(temp, '\n');
	line = ft_substr(temp, 0, pos_n + 1);
	zero = ft_strclen(temp, '\0');
	bbackup = ft_substr(temp, pos_n + 1, zero);
	free(temp);
	printf("backup: |%s|", bbackup);
	return (line);
}
