/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efret <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:33:33 by efret             #+#    #+#             */
/*   Updated: 2023/11/21 15:41:23 by efret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*sptr;

	i = 0;
	sptr = (unsigned char *)s;
	while (i < n)
	{
		if (sptr[i] == (unsigned char)c)
			return ((void *)&sptr[i]);
		i++;
	}
	return (NULL);
}
