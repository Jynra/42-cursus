/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex_lower.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:50:21 by ellucas           #+#    #+#             */
/*   Updated: 2024/11/21 15:03:39 by ellucas          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
void	ft_printchar1(char c)
{
	write(1, &c, 1);
}
*/
void	ft_putnbrhex_lower(unsigned int nb, int *i)
{
	if (nb >= 16)
	{
		ft_putnbrhex_lower(nb / 16, i);
	}
	ft_printchar("0123456789abcdef"[nb % 16]);
	*i += 1;
}

int ft_printhex_lower(unsigned int nb)
{
	int	i;

	i = 0;
	ft_putnbrhex_lower(nb, &i);
	return (i);
}
