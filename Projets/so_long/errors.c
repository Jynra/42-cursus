/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <ellucas@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:01:54 by ellucas           #+#    #+#             */
/*   Updated: 2025/01/22 14:11:27 by ellucas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	errors(int i)
{
	if (i == 1)
	{
		ft_printf("Error\nCannot read map file\n");
		return (1);
	}
	return (0);
}
