/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:55:20 by ellucas           #+#    #+#             */
/*   Updated: 2024/11/13 16:59:12 by ellucas          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINT_H

#include <stdarg.h>
#include "./libft/libft.h"

int	ft_printf(const char *input, ...);
int	ft_putchar(char c);

#endif
