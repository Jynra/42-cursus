/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <ellucas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:02:50 by ellucas           #+#    #+#             */
/*   Updated: 2025/03/26 13:15:31 by ellucas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_max(*a);
	ft_printf("Error sort_three 1\n"); // DEBUG
	if (biggest_node == *a)
	{
		ft_printf("Error sort_three 2\n"); // DEBUG
		ra(a,false);
		ft_printf("Error sort_three 3\n"); // DEBUG
	}
	else if ((*a)->next == biggest_node)
	{
		ft_printf("Error sort_three 4\n"); // DEBUG
		rra(a, false);
	}
	if ((*a)->next && (*a)->nbr > (*a)->next->nbr)
	{
		ft_printf("Error sort_three 5\n"); // DEBUG
		sa(a, false);
	}
	ft_printf("Error sort_three 6\n"); // DEBUG
}