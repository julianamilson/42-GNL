/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:55:00 by jmilson-          #+#    #+#             */
/*   Updated: 2021/10/12 18:18:27 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*verify(char **bbackup, ssize_t bef_n)
{
	char	*line;
	char	*temp;

	if (bef_n == 0)
	{
		if (!**bbackup)
		{
			free(*bbackup);
			*bbackup = NULL;
			return (NULL);
		}
		line = *bbackup;
		*bbackup = NULL;
		return (line);
	}
	temp = *bbackup;
	line = ft_substr(temp, 0, bef_n + 1);
	*bbackup = ft_strdup(temp + bef_n + 1);
	free(temp);
	return (line);
}

static char	*get_content(char **bbackup, char *buffer, int fd)
{
	char	*temp;
	int		read_chars;

	while (!ft_strchr(*bbackup, '\n'))
	{
		read_chars = read(fd, buffer, BUFFER_SIZE);
		if (read_chars <= 0)
			return (verify(bbackup, 0));
		buffer[read_chars] = '\0';
		temp = *bbackup;
		*bbackup = ft_strjoin(temp, buffer);
		free(temp);
	}
	return (verify(bbackup, ft_strclen(*bbackup, '\n')));
}

char	*get_next_line(int fd)
{
	static char	*bbackup;
	char		*buffer;
	char		*line;

	if (fd < 0 ||BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!bbackup)
		bbackup = ft_strdup("");
	line = get_content(&bbackup, buffer, fd);
	free(buffer);
	return (line);
}
