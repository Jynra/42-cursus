/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:38:58 by ellucas           #+#    #+#             */
/*   Updated: 2024/10/18 13:21:24 by ellucas          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	lens1;
	size_t	lens2;
	size_t	i;
	size_t	j;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!s1 || !s2)
		return (0);
	str = malloc(lens1 + lens2);
	i = 0;
	j = 0;
	while (i < (lens1 + lens2))
	{
		if (s1[i] != '\0')
		{
			str[i] = s1[i];
			i++;
		}
		else if (s2[j] != '\0')
			str[i++] = s2[j++];
	}
	str[i] = '\0';
	return (str);
}
