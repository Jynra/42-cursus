/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:26:47 by ellucas           #+#    #+#             */
/*   Updated: 2024/10/14 15:41:48 by ellucas          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strstr(char *str, char *to_find, size_t n)
{
	int	len;
	int	i;
	int	j;

	len = 0;
	if (!to_find)
		return (str);
	while (to_find[len])
		len++;
	if (len == 0)
		return (str);
	i = 0;
	j = 0;
	while (i < n)
	{
		while (to_find[j] == str[i + j])
		{
			if (j + 1 == len)
				return (str + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	main(int ac, char *av[])
{
	printf("%s", ft_strstr(av[1], av[2], atoi(av[3])));
	return (0);
}
