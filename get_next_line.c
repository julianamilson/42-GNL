/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:55:00 by jmilson-          #+#    #+#             */
/*   Updated: 2021/10/04 20:53:23 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_content(char *bbackup, char *buffer, char *line, int fd)
{
	char		*temp;
	int			read_chars;
	size_t		pos_n;
	size_t		zero;

	temp = ft_strdup("");
	if (bbackup)
		temp = ft_strdup(bbackup);
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
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*bbackup;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	buffer[BUFFER_SIZE + 1] = '\0';
	if (!buffer)
		return (NULL);
	line = ft_strdup("");
	line = get_content(bbackup, buffer, line, fd);
	return (line);
}
