/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:24:02 by ellucas           #+#    #+#             */
/*   Updated: 2024/11/21 17:18:55 by ellucas          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexconv(uintptr_t n)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += hexconv(n / 16);
	ft_printchar("0123456789abcdef"[n % 16]);
	i++;
	return (i);
}

int	ft_printptr(uintptr_t ptr)
{
	int	i;

	i = 0;
	if (!ptr || (void *)ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	i += 2 + hexconv(ptr);
	return (i);
}
