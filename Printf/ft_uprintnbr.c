/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uprintnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:04:18 by ellucas           #+#    #+#             */
/*   Updated: 2024/11/15 19:08:40 by ellucas          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar( char c)
{
	write(1, &c, 1);
}

int	ft_uprinttnbr(unsigned int nb)
{
	char	c;
	int		len;

	len = 1;
	if (nb >= 10)
	{
		ft_uprinttnbr(nb / 10);
		len++;
	}
	c = (nb % 10) + '0';
	ft_putchar(c);
	return (len);
}
