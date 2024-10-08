/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:43:12 by ellucas           #+#    #+#             */
/*   Updated: 2024/10/08 16:09:20 by ellucas          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	srclen;
	size_t	dstlen;

	i = 0;
	srclen = 0;
	dstlen = 0;
	while (src)
	{
		srclen++;
	}
	while (dst)
	{
		dstlen++;
	}
	j = dstlen;
	while (i < dstsize - dstlen - 1 && src)
	{
		dst[j + 1] = src[i];
		i++;
	}
	return (dstlen + srclen);
}
