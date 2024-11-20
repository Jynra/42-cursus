/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uprintnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:04:18 by ellucas           #+#    #+#             */
/*   Updated: 2024/11/20 18:54:46 by ellucas          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_uputnbr(unsigned int	nb, int	*i)
{
	if (nb >= 10)
		ft_uputnbr(nb / 10, i);
	ft_printchar("0123456789"[nb % 10]);
	*i += 1;
}

int	ft_uprintnbr(unsigned int nb)
{
	int	i;

	i = 0;
	ft_uputnbr(nb, &i);
	return (i);
}
/*
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
	ft_printchar(c);
	return (len);
}
*/
