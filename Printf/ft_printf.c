/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:34:56 by ellucas           #+#    #+#             */
/*   Updated: 2024/11/12 14:56:53 by ellucas          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>

int check_type(const char *input, void *args)
{
	int	i;

	i = 0;
	if (*input == 'c')
		i += ft_putchar((char)input);
	elseif (*input == 's')
		i += ft_putstr();
	elseif (*input == 'p')
		i += ft_putvoid();
	elseif (*input == 'd')
		i += ft_putdec();
	elseif (*input == 'i')
		i += ft_putint();
	elseif (*input == 'u')
		i += ft_put_unsigned_dec();
	elseif (*input == 'x')
		i += ft_putnbr_lowercase();
	elseif (*input == 'X')
		i += ft_putnbr_uppercase();
	elseif (*input == '%')
		i += ft_put_percent();
}

int	ft_printf(const char *input, ...)
{
	int	i;

	va_list	args;
	va_start (args, input);

	i = 0;
	while (input[i] != '\0')
	{
		check_type(input, args);
	}
}
