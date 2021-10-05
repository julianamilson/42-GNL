/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:55:38 by jmilson-          #+#    #+#             */
/*   Updated: 2021/10/05 15:19:47 by jmilson-         ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;
	size_t	i;

	if (start > ft_strclen(s, '\0'))
		return (ft_strdup(""));
	slen = ft_strclen(&s[start], '\0');
	if (len >= slen)
		len = slen - start;
	sub = malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] != '\0' && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sr;
	size_t	len;
	size_t	i;

	len = ft_strclen(s1, '\0') + ft_strclen(s2, '\0');
	sr = malloc((len + 1));
	if (sr == NULL)
		return (NULL);
	sr[len] = '\0';
	i = 0;
	while (i < len)
	{
		if (*s1)
			sr[i++] = *s1++;
		else
			sr[i++] = *s2++;
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

	len = ft_strclen(str, '\0');
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[len] = '\0';
	i = 0;
	while (str[i] != '\0')
	{
		ptr[i] = str[i];
		i++;
	}
	return (ptr);
}
