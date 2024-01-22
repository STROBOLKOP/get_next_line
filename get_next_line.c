/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efret <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:18:29 by efret             #+#    #+#             */
/*   Updated: 2024/01/22 14:24:18 by efret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE] = "";
	char		*line;
	int			read_return;

	line = NULL;
	if (buf[0])
		if (ft_append_line(&line, buf))
			return (line);
	while (1)
	{
		read_return = read(fd, buf, BUFFER_SIZE);
		if (read_return < 0)
		{
			if (line)
				free(line);
			ft_bzero(buf, BUFFER_SIZE);
			return (NULL);
		}
		if (read_return == 0)
			return (line);
		if (ft_append_line(&line, buf))
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
for (int i = 0; i < 3; i++)
{
line = get_next_line(fd);
printf("%s", line);
if (line)
free(line);
}
close(fd);
return (0);
}
*/
