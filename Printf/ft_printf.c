/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:34:56 by ellucas           #+#    #+#             */
/*   Updated: 2024/11/13 17:07:24 by ellucas          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int check_type(const char *input, void *args)
{
	int	i;

	i = 0;
	if (*input == 'c')
		i += ft_putchar((int)args);
		/*
	else if (*input == 's')
		i += ft_putstr((char*)args);
	else if (*input == 'p')
		i += ft_putvoid();
	else if (*input == 'd')
		i += ft_putdec();
	else if (*input == 'i')
		i += ft_putint();
	else if (*input == 'u')
		i += ft_put_unsigned_dec();
	else if (*input == 'x')
		i += ft_putnbr_lowercase();
	else if (*input == 'X')
		i += ft_putnbr_uppercase();
	else if (*input == '%')
		i += ft_put_percent();
	*/
}

int	ft_printf(const char *input, ...)
{
	int	i;

	va_list	args;
	va_start (args, input);

	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '%')
		{
			i++;
			check_type(input, args);
		}
		write(1, input[i], 1);
		i++;
	}
}

int	main(int ac, char *av[])
{
	ft_printf("result is: %c\n", av[1]);
}
