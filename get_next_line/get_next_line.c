/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:18:09 by ellucas           #+#    #+#             */
/*   Updated: 2024/12/03 15:34:44 by ellucas          ###   LAUSANNE.ch       */
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

	// Trouver la fin de la ligne
	i = 0;
	while (remainder[i] != '\n' && remainder[i] != '\0')
		i++;

	// Pas de reste à mettre à jour
	if (remainder[i] == '\0')
	{
		return (NULL);
	}

	// Créer un nouveau reste
	new_remainder = ft_strdup(remainder + i + 1);

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
	buffer[0] = '\0';
	bytes_read = 1;
	while ((!remainder || !ft_strchr(remainder, '\n')) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		if (bytes_read == 0)
			break;
		buffer[bytes_read] = '\0';
		temp = remainder;
		remainder = ft_strjoin(remainder, buffer);
		if (!remainder)
		{
			free(buffer);
			free(temp);
			return (NULL);
		}
	}
	free(buffer);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder = NULL;
	char		*line;

	// Cas spécial pour libérer `remainder` à la fin
	if (fd == -1)
	{
		if (remainder)
		{
			remainder = NULL;
		}
		return (NULL);
	}

	// Vérifications initiales
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	// Lecture et stockage
	remainder = read_and_store(fd, remainder);
	if (!remainder || *remainder == '\0')
	{
		remainder = NULL;
		return (NULL);
	}

	// Extraction de la ligne et mise à jour du remainder
	line = extract_line(remainder);
	remainder = remainder_update(remainder);

	return (line);
}
