/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:55:00 by jmilson-          #+#    #+#             */
/*   Updated: 2021/10/06 20:27:42 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *read_temp(char *temp, int read_chars, char *line)
{
	if (read_chars <= 0)
	{
		if (!*temp)
		{
			free(temp);
			temp = NULL;
			return (NULL);
		}
		line = temp;
		temp = NULL;
		return (line);
	}
	return (temp);
}

static char	*get_content(char **bbackup, char *buffer, char *line, int fd)
{
	char		*temp;
	int			read_chars;
	size_t		bef_n;

	temp = *bbackup;
	while (!ft_strchr(temp, '\n'))
	{
		read_chars = read(fd, buffer, BUFFER_SIZE);
		temp = read_temp(temp, read_chars, line);
		buffer[read_chars] = '\0';
		temp = ft_strjoin(temp, buffer);
	}
	bef_n = ft_strclen(temp, '\n');
	line = ft_substr(temp, 0, bef_n + 1);
	*bbackup = ft_strdup(&temp[bef_n + 1]);
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
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!bbackup)
		bbackup = ft_strdup("");
	line = get_content(&bbackup, buffer, line, fd);
	free(buffer);
	return (line);
}
