/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efret <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:39:04 by efret             #+#    #+#             */
/*   Updated: 2023/11/21 14:56:04 by efret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
