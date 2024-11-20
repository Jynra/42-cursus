/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:20:39 by ellucas           #+#    #+#             */
/*   Updated: 2024/11/20 17:27:27 by ellucas          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned int n)
{
	char	buffer[9];
	int i;
	int count;

	i = 0;
	count = 0;

	if (n == 0)
	{
		write(1, "0", 1);
		return 1;
	}
	while (n > 0)
	{
		int digit = n % 16;
		char c;
		if (digit < 10)
			c = '0' + digit;
		else
			c = 'a' + (digit - 10);
		buffer[i++] = c;
		n /= 16;
	}
	while (--i >= 0)
	{
		write(1, &buffer[i], 1);
		count++;
	}
	return count;
}
