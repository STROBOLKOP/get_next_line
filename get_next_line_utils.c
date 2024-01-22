/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efret <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:19:02 by efret             #+#    #+#             */
/*   Updated: 2024/01/22 14:19:49 by efret            ###   ########.fr       */
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

size_t	ft_strlen_newline(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		if (s[len++] == '\n')
			break ;
	return (len);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
		ptr[i++] = 0;
}

int	ft_append_line(char **line, char *buf)
{
	char	*tmp_line_cpy;
	size_t	buf_cpy_len;
	size_t	line_len;

	line_len = 0;
	tmp_line_cpy = *line;
	if (tmp_line_cpy)
		line_len = ft_strlen(tmp_line_cpy);
	buf_cpy_len = ft_strlen_newline(buf);
	*line = malloc(sizeof(char) * (line_len + buf_cpy_len + 1));
	if (!*line)
		return (-1);
	ft_memcpy(*line, tmp_line_cpy, line_len);
	ft_memcpy(&((*line)[line_len]), buf, buf_cpy_len);
	(*line)[line_len + buf_cpy_len] = 0;
	ft_memcpy(buf, &buf[buf_cpy_len], BUFFER_SIZE - buf_cpy_len);
	ft_bzero(&buf[BUFFER_SIZE - buf_cpy_len], buf_cpy_len);
	if (tmp_line_cpy)
		free(tmp_line_cpy);
	if ((*line)[line_len + buf_cpy_len - 1] != '\n')
		return (0);
	return (1);
}
