/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efret <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:18:29 by efret             #+#    #+#             */
/*   Updated: 2024/01/22 16:51:35 by efret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffers[1024][BUFFER_SIZE + 1];
	char		*line;
	int			read_return;

	line = NULL;
	if (buffers[fd][0])
		if (ft_append_line(&line, buffers[fd]))
			return (line);
	while (1)
	{
		read_return = read(fd, buffers[fd], BUFFER_SIZE);
		if (read_return < 0)
		{
			if (line)
				free(line);
			ft_bzero(buffers[fd], BUFFER_SIZE);
			return (NULL);
		}
		if (read_return == 0)
			return (line);
		if (ft_append_line(&line, buffers[fd]))
			return (line);
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	char	*line;
	int	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Could not open file.\n");
		return (0);
	}
	int	fd2 = open("test2.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Could not open file.\n");
		return (0);
	}
	int	fd3 = open("test3.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Could not open file.\n");
		return (0);
	}
	int	files[3] = {fd, fd2, fd3};
	for (int i = 0; i < 6; i++)
	{
		line = get_next_line(files[i % 3]);
		printf("%s", line);
		if (line)
			free(line);
	}
	close(fd);
	close(fd2);
	close(fd3);
	return (0);
}
*/
