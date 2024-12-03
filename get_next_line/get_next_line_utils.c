/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:15:37 by ellucas           #+#    #+#             */
/*   Updated: 2024/12/03 14:35:10 by ellucas          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	size;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	if (s1 && s2)
	{
		size = ft_strlen(s1) + ft_strlen(s2);
		str = malloc(size + 1);
		if (str == NULL)
			return (0);
		i = 0;
		while (i < size)
		{
			j = 0;
			while (s1[j] != '\0')
				str[i++] = s1[j++];
			j = 0;
			while (s2[j] != '\0')
				str[i++] = s2[j++];
		}
		str[i] = '\0';
		return (str);
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		l;
	int		i;

	if (!s1)
		return (NULL);
	l = ft_strlen(s1) + 1;
	copy = malloc(l * sizeof(char));
	if (!copy)
		return (0);
	i = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if ((unsigned char)c == '\0')
	{
		return ((char *)s + i);
	}
	return (NULL);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
