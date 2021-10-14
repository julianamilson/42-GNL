/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:24:32 by jmilson-          #+#    #+#             */
/*   Updated: 2021/10/14 00:08:32 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd_to_read;
	char	*str;

	fd_to_read = open("/home/juliana/42/42-GNL/gnlTester/files/empty", O_RDWR);
	str = get_next_line(fd_to_read);
	printf("%s", str);
	free(str);
	str = NULL;
	printf("-----\n");
	str = get_next_line(fd_to_read);
	printf("%s", str);
	free(str);
	str = NULL;
	printf("-----\n");
	str = get_next_line(fd_to_read);
	printf("%s", str);
	free(str);
	str = NULL;
	printf("-----\n");
	str = get_next_line(fd_to_read);
	printf("%s", str);
	free(str);
	str = NULL;
	printf("-----\n");
	str = get_next_line(fd_to_read);
	printf("%s", str);
	free(str);
	str = NULL;
	printf("-----\n");
	return (0);
}
