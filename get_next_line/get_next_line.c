/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:18:09 by ellucas           #+#    #+#             */
/*   Updated: 2024/12/03 13:14:05 by ellucas          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *remainder)
{
	int		i;
	char	*line;

	i = 0;
	while (remainder[i] != '\n' && remainder[i] != '\0')
		i++;
	if (remainder[i] == '\n')
	{
		line = malloc(i + 2);
		if (!line)
			return (NULL);
		ft_strncpy(line, remainder, i + 1);
		line[i++] = '\0';
	}
	else
	{
		line = malloc(i + 1);
		if (!line)
			return (NULL);
		ft_strncpy(line, remainder, i);
		line[i] = '\0';
	}
	return (line);
}

char	*remainder_update(char *remainder)
{
	int		i;
	char	*new_remainder;

	if (!remainder)
		return (NULL);
	i = 0;
	while (remainder[i] != '\n' && remainder[i] != '\0')
		i++;
	if (remainder[i] == '\0')
	{
		free(remainder);
		return (NULL);
	}
	new_remainder = ft_strdup(remainder + i + 1);
	free(remainder);
	return (new_remainder);
}

static char	*read_and_store(int fd, char *remainder)
{
	char	*buffer;
	ssize_t	bytes_read;
	char *temp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while ((!remainder || !ft_strchr(remainder, '\n')) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		temp = remainder;
		remainder = ft_strjoin(remainder, buffer);
		if (!remainder)
		{
			free(buffer);
			free(temp);
			return (NULL);
		}
		free(temp);
	}
	free(buffer);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = read_and_store(fd, remainder);
	if (!remainder)
		return (NULL);
	line = extract_line(remainder);
	remainder = remainder_update(remainder);
	return (line);
}
