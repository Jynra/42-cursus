/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jynra <jynra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:50:46 by ellucas           #+#    #+#             */
/*   Updated: 2025/03/14 12:06:41 by jynra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack	*stack_a)
{
	int	temp;
	t_node	*first;
	t_node	*second;

	if (stack_a->size < 2)
		return ;
	first = stack_a->top;
	second = first->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
}

void	sb(t_stack	*stack_b)
{
	int	temp;
	t_node	*first;
	t_node	*second;

	if (stack_b->size < 2)
		return ;
	first = stack_b->top;
	second = first->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
}

void	ss(t_stack	*stack_a, t_stack	*stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
