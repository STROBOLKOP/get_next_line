/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efret <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:19:24 by efret             #+#    #+#             */
/*   Updated: 2024/01/09 16:48:24 by efret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

typedef struct s_file
{
	int		fd;
	size_t	pos;
	char	buffer[BUFFER_SIZE];
	char	*line;
	size_t	len;
}			t_file;

char	*get_next_line(int fd);

#endif
