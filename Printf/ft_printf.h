/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:55:20 by ellucas           #+#    #+#             */
/*   Updated: 2024/11/21 15:00:24 by ellucas          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdint.h>

int	ft_printf(const char *input, ...);
int	ft_printchar(char c);
int	ft_printstr(char *str);
int	ft_printptr(uintptr_t ptr);
int	ft_printint(int n);
int	ft_uprintnbr(unsigned int nb);
int	ft_printhex_lower(unsigned int nb);
int	ft_printhex_up(unsigned int n);

#endif
