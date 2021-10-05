/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:24:32 by jmilson-          #+#    #+#             */
/*   Updated: 2021/10/05 00:21:06 by jmilson-         ###   ########.fr       */
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
	int	fd_to_read;

	fd_to_read = open("test.txt", O_RDWR);
	printf("%s", get_next_line(fd_to_read));
	printf("-----\n");
	printf("%s", get_next_line(fd_to_read));
	printf("-----\n");
	printf("%s", get_next_line(fd_to_read));
	printf("-----\n");
	printf("%s", get_next_line(fd_to_read));
	printf("-----\n");
	printf("%s", get_next_line(fd_to_read));
	printf("-----\n");
	printf("%s", get_next_line(fd_to_read));
	printf("-----\n");
	printf("%s", get_next_line(fd_to_read));
	printf("-----\n");
	printf("%s", get_next_line(fd_to_read));
	printf("-----\n");
	return (0);
}
