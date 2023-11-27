/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efret <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:18:29 by efret             #+#    #+#             */
/*   Updated: 2023/11/27 19:31:13 by efret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_file	file;
	size_t			i;

	if (fd < 0 || (file.fd && file.fd != fd))
		return (NULL);
	if (!file.fd)
		file.fd = fd;
	if (!read(file.fd, file.buffer, BUFFER_SIZE))
	{
		if (file.line)
			free(file.line);
		return (NULL);
	}
	i = 0;
	while (file.buffer[i] && file.buffer[i] != '\n')
		i++;
	if (file.line)
		free(file.line);
	file.line = malloc(sizeof(char) * (i + 1));
	file.line[i] = 0;
	while (i-- > 0)
		file.line[i] = file.buffer[i];
	
	return (file.line);
}

#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	int	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Could not open file.\n");
		return (0);
	}
	for (int i = 0; i < 10; i++)
		printf("%s", get_next_line(fd));

	char	buf[BUFFER_SIZE];
	for (int i = 0; i < 10; i++)
	{
		read(fd, buf, BUFFER_SIZE);
		printf("%s", buf);
	}
	close(fd);
	return (0);
}
