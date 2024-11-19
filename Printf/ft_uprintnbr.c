/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uprintnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:04:18 by ellucas           #+#    #+#             */
/*   Updated: 2024/11/19 11:59:48 by ellucas          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar( char c)
{
	write(1, &c, 1);
}

int	ft_uprintnbr(unsigned int nb)
{
	char	c;
	int		len;

	len = 1;
	if (nb > 9)
	{
		ft_uprintnbr(nb / 10);
		len++;
	}
	c = (nb % 10) + '0';
	ft_putchar(c);
	return (len);
}
