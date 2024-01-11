/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efret <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:18:29 by efret             #+#    #+#             */
/*   Updated: 2024/01/11 17:40:02 by efret            ###   ########.fr       */
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

size_t	ft_strlen_newline(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		if (s[len++] == '\n')
			break;
	return (len);
}

/*
char	*ft_strjoin(t_file *file, size_t start)
{
	char			*res;
	size_t			buf_data_len;

	buf_data_len = file->pos - start;
	res = malloc(sizeof(char) * (file->len + buf_data_len + 1));
	if (!res)
		return (NULL);
	ft_memcpy(res, file->line, file->len);
	ft_memcpy(&res[file->len], &file->buf[start], buf_data_len);
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
				file->buf[--file->pos] = 0;
			if (read(file->fd, file->buf, BUFFER_SIZE) <= 0)
				return (NULL);
		}
		start = file->pos;
		while (file->buf[file->pos])
			if (file->buf[file->pos++] == '\n')
				return (ft_strjoin(file, start));
		if (start == file->pos)
			return (NULL);
		file->line = ft_strjoin(file, start);
	}
	return (file->line);
}
*/

char	*ft_strjoin(char *line, char *buf, size_t len)
{
	char	*res;
	size_t	line_len;

	line_len = 0;
	if (line)
		line_len = ft_strlen(line);
	res = malloc(sizeof(char) * (line_len + len + 1));
	if (!res)
		return (NULL);
	ft_memcpy(res, line, line_len);
	ft_memcpy(&res[line_len], buf, len);
	res[line_len + len] = 0;
	if (line)
		free(line);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buf = "";
	char		*line;
	size_t		buf_cpy_len;
	size_t		line_len;
	char		*tmp;

	line_len = 0;
	buf_cpy_len = 0;
	line = NULL;
	while (1)
	{
		if (buf)
			buf_cpy_len = ft_strlen_newline(buf); // Look for a different logic, right now I try to get the length of a freed object when the file is done.
		if (!buf_cpy_len)
		{
			buf = calloc(BUFFER_SIZE + 1, sizeof(char)); // ft_calloc
			if (read(fd, buf, BUFFER_SIZE) <= 0)
				return (free(buf), NULL);
			buf_cpy_len = ft_strlen_newline(buf);
		}
		line = ft_strjoin(line, buf, buf_cpy_len);
		tmp = buf;
		buf = ft_strjoin(NULL, &buf[buf_cpy_len], ft_strlen(buf) - buf_cpy_len); // Something here still leaks, the res malloc'd in strjoin. Maybe just another function, ye?
		free(tmp);
		line_len += buf_cpy_len;
		buf_cpy_len = 0;
		if (line[line_len - 1] == '\n')
			break;
	}
	return (line);
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
	for (int i = 0; i < 10; i++)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line)
			free(line);
	}
	close(fd);
	return (0);
}
