/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jynra <jynra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:55:20 by ellucas           #+#    #+#             */
/*   Updated: 2025/03/14 12:06:38 by jynra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stack *stack_b, t_stack *stack_a)
{
	t_node	*first;

	(void)first;
	if (!stack_b)
		return ;
	stack_a->top = stack_b->top;
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	//t_node	*first;

	//(void)first;
	if (!stack_a)
		return ;
	stack_b->top = stack_a->top;
}
