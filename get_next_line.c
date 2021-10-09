/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:55:00 by jmilson-          #+#    #+#             */
/*   Updated: 2021/10/08 21:58:29 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *verify(char **temp, char **line)
{
	if (!**temp)
	{
		free(*temp);
		temp = NULL;
		return (NULL);
	}
	line = temp;
	temp = NULL;
	return (line);
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
		if (read_chars <= 0)
			return (verify(&temp, line));
		buffer[read_chars] = '\0';
		temp = ft_strjoin(temp, buffer);
	}
	bef_n = ft_strclen(temp, '\n');
	line = ft_substr(temp, 0, bef_n + 1);
	*bbackup = ft_strdup(&temp[bef_n + 1]);
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
