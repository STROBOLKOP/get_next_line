/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efret <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:45:01 by efret             #+#    #+#             */
/*   Updated: 2023/11/22 17:05:58 by efret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_itoa_len(int n)
{
	size_t	len;
	long	num;

	num = (long)n;
	len = 1;
	if (num < 0)
	{
		len++;
		num = -num;
	}
	while (num > 9)
	{
		len++;
		num /= 10;
	}
	return (len);
}

static unsigned int	ft_pow(int base, int pow)
{
	if (!pow)
		return (1);
	if (pow < 0)
		return (0);
	return (base * ft_pow(base, pow - 1));
}

char	*ft_itoa(int n)
{
	size_t	len;
	size_t	i;
	long	num;
	char	*res;

	len = ft_itoa_len(n);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	num = (long)n;
	if (num < 0)
	{
		res[i++] = '-';
		len--;
		num = -num;
	}
	while (len-- > 0)
		res[i++] = "0123456789"[(num / ft_pow(10, len)) % 10];
	res[i] = 0;
	return (res);
}
