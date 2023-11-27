/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efret <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:30:54 by efret             #+#    #+#             */
/*   Updated: 2023/11/21 13:59:29 by efret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	data;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	data = (unsigned char)c;
	while (i < n)
		ptr[i++] = data;
	return (s);
}
