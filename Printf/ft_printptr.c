/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:24:02 by ellucas           #+#    #+#             */
/*   Updated: 2024/11/21 15:05:46 by ellucas          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int hexconv(uintptr_t n)
{
    char c;
    int count = 0;

    if (n >= 16) // Appel récursif pour les chiffres supérieurs
        count += hexconv(n / 16);

    c = "0123456789abcdef"[n % 16]; // Récupérer le caractère hexadécimal
    write(1, &c, 1); // Afficher le caractère
    count++;
    return count;
}

int	ft_printptr(uintptr_t ptr)
{
	int	i;

	i = 0;
	if ((void *)ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	i += 2 + hexconv(ptr);
	return (i);
}
