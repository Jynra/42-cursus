/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:34:56 by ellucas           #+#    #+#             */
/*   Updated: 2024/11/07 15:57:58 by ellucas          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int check_type(const char *input, void *arg)
{
	int	i;

	i = 0;
	if (*input == 'c')
		i += putchar();
}

int	ft_printf(const char *input, ...)
{

}
