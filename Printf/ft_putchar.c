/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:56:37 by ellucas           #+#    #+#             */
/*   Updated: 2024/11/13 17:02:09 by ellucas          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
/*
int	main(void)
{
	ft_putchar('a');
}
*/
