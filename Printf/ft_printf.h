/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:55:20 by ellucas           #+#    #+#             */
/*   Updated: 2024/11/14 17:59:47 by ellucas          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include "./libft/libft.h"

int	ft_printf(const char *input, ...);
int	ft_printchar(char c);
int	ft_printstr(char *str);
int	ft_printint(int n);

#endif
