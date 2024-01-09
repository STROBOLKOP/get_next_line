/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efret <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:18:29 by efret             #+#    #+#             */
/*   Updated: 2024/01/09 17:30:35 by efret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	for (size_t i = 0; i < file->len + buf_data_len; i++)
		res[i] = '0';
	ft_memcpy(res, file->line, file->len);
	ft_memcpy(&res[file->len], &file->buffer[start], buf_data_len);
	res[file->len + file->pos - start] = 0;
	free(file->line);
	file->len += buf_data_len;
	return (res);
}

char	*get_next_line(int fd)
{
	static t_file	*file;
	size_t			start;

	/*
	 * If pos < buffersize; then continue from buffer.
	 * no buffer left to loop over to check but still no newline,
	 * then read from fd again and
	 * loop over the new buffer data in search for the next newline.
	 * always allocate the full length again and free the prev length.
	 */
	file = malloc(sizeof(t_file));
	if (!file)
		return (NULL);
	if (fd < 0 || (file->fd && file->fd != fd))
		return (NULL);
	file->fd = fd;
	if (file->line)
		free(file->line);
	file->len = 0;
	while (1)
	{
		if (!(file->pos) || file->pos == BUFFER_SIZE)
		{
			file->pos = 0;
			if (read(file->fd, file->buffer, BUFFER_SIZE) <= 0)
				break;
		}
		start = file->pos;
		while (file->buffer[file->pos])
		{
			file->pos++;
			if (file->buffer[file->pos-1] == '\n')
				break;
		}
		file->line = ft_strjoin(file, start);
		if (file->line[file->len - 1] == '\n')
			break;
	}
	return (file->line);
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
	for (int i = 0; i < 5; i++)
		printf("%s", get_next_line(fd));

	close(fd);
	return (0);
}
