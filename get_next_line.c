/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efret <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:18:29 by efret             #+#    #+#             */
/*   Updated: 2024/01/10 17:36:17 by efret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> // ----------------------------------------------------------DELETE ME

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dptr;
	unsigned char	*sptr;

	if (!dest && !src && n)
		return (NULL);
	i = 0;
	dptr = (unsigned char *)dest;
	sptr = (unsigned char *)src;
	while (i < n)
	{
		dptr[i] = sptr[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(t_file *file, size_t start)
{
	char			*res;
	size_t			buf_data_len;

	buf_data_len = file->pos - start;
	res = malloc(sizeof(char) * (file->len + buf_data_len + 1));
	if (!res)
		return (NULL);
	ft_memcpy(res, file->line, file->len);
	ft_memcpy(&res[file->len], &file->buffer[start], buf_data_len);
	res[file->len + file->pos - start] = 0;
	file->len += buf_data_len;
	return (res);
}

char	*get_next_line(int fd)
{
	static t_file	*file;
	size_t			start;

	if (!file)
		file = calloc(1, sizeof(t_file)); // ft_calloc here pls
	file->fd = fd;
	file->len = 0;
	while (1)
	{
		if (!(file->pos) || file->pos == BUFFER_SIZE)
		{
			while (file->pos > 0)
				file->buffer[--file->pos] = 0;
			if (read(file->fd, file->buffer, BUFFER_SIZE) <= 0)
				return (NULL);
		}
		start = file->pos;
		while (file->buffer[file->pos])
			if (file->buffer[file->pos++] == '\n')
				return (ft_strjoin(file, start));
		if (start == file->pos)
			return (NULL);
		file->line = ft_strjoin(file, start);
	}
	return (file->line);
}

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
	for (int i = 0; i < 20; i++)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
