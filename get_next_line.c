/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:55:00 by jmilson-          #+#    #+#             */
/*   Updated: 2021/10/05 18:50:02 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_content(char *bbackup, char *buffer, char *line, int fd)
{
	char		*temp;
	int			read_chars;
	size_t		bef_n;
	size_t		aft_n;

	temp = ft_strdup(bbackup);
	while (!ft_strchr(temp, '\n'))
	{
		read_chars = read(fd, buffer, BUFFER_SIZE);
		if (read_chars == -1 || read_chars == 0)
		{
			free(buffer);
			return (NULL);
		}
		else
			buffer[read_chars] = '\0';
		temp = ft_strjoin(temp, buffer);
	}
	bef_n = ft_strclen(temp, '\n');
	line = ft_substr(temp, 0, bef_n + 1);
	aft_n = ft_strclen(&temp[bef_n], '\0');
	bbackup = ft_substr(temp, bef_n, aft_n + 1);
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
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	if (!bbackup)
		bbackup = ft_strdup("");
	line = get_content(bbackup, buffer, line, fd);
	return (line);
}
