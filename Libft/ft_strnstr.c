/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:28:35 by ellucas           #+#    #+#             */
/*   Updated: 2024/10/14 17:08:01 by ellucas          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		n;
	size_t	i;
	int		j;

	n = 0;
	i = 0;
	j = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (needle[n])
		n++;
	while (i < len)
	{
		while (needle[j] == haystack[i + j] && (i + j) < len)
		{
			if (j + 1 == n)
				return ((char *)haystack + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
