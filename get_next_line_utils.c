/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:55:38 by jmilson-          #+#    #+#             */
/*   Updated: 2021/10/01 21:48:23 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strclen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

void	*ft_calloc(size_t number, size_t size)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	i = number * size;
	ptr = malloc(i);
	if (!ptr || i < 0)
		return (NULL);
	j = 0;
	while (j < i)
	{
		ptr[j] = '\0';
		j++;
	}
	return ((void *)ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sr;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	len1 = ft_strclen(s1, '\0');
	len2 = ft_strclen(s2, '\0');
	sr = (char *)ft_calloc((len1 + len2 + 1), sizeof(char));
	if (sr == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		sr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		sr[i + j] = s2[j];
		j++;
	}
	return (sr);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if ((unsigned char) *str == (unsigned char) c)
			return ((char *) str);
		str++;
	}
	if (c == 0)
		return ((char *) str);
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	len = ft_strclen(str, '\0') + 1;
	ptr = (char *)malloc(len);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
