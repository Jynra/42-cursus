/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <ellucas@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:14:09 by ellucas           #+#    #+#             */
/*   Updated: 2025/01/21 16:30:25 by ellucas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_data *data)
{
	int	i;

	i = 0;
	ft_printf("\nAffichage de la map :\n");
	while (i < data->map_height)
	{
		ft_printf("%s", data->map[i]);
		i++;
	}
}