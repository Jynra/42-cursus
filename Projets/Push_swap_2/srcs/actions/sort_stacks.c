/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <ellucas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:21:17 by ellucas           #+#    #+#             */
/*   Updated: 2025/03/26 12:41:54 by ellucas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
//		ft_printf("Erreur 1\n"); // DEBUG
		init_nodes_a(*a, *b);
//		ft_printf("Erreur 2\n"); // DEBUG
		move_a_to_b(a, b);
	}
	ft_printf("Erreur 5\n"); // DEBUG
	sort_three(a);
	ft_printf("Error 8\n"); // DEBUG
	while (*b)
	{
		ft_printf("Error 7\n"); // DEBUG
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	ft_printf("Error 6\n"); // DEBUG
	current_index(*a);
	min_on_top(a);
}