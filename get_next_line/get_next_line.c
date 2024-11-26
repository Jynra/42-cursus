/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:18:09 by ellucas           #+#    #+#             */
/*   Updated: 2024/11/26 16:35:51 by ellucas          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"

#include <fcntl.h>
#include <unistd.h>

char	get_next_line(int fd)
{
	char buffer[1];
	ssize_t byte;

	byte = read(fd, buffer, 1);
	if (byte == 1)
		return (buffer[0]);
	return (-1);
}

int	main()
{
	int		fd;
	char	c;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error", 5);
		return (1);
	}
	while (c != -1)
	{
		write (1, &c, 1);
		c = get_next_line(fd);
	}
	close(fd);
	return (0);
}
