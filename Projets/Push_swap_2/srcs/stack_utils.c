/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <ellucas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:55:22 by ellucas           #+#    #+#             */
/*   Updated: 2025/03/13 15:47:39 by ellucas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	stack_len(t_stack_node *stack)
{
	int	count;

	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_stack_node	*find_min(t_stack_node *stack)
{
	long	min;
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MIN;
	while (stack->next)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}
bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}
/*
t_stack_node	*find_min(t_stack_node *stack)
{
	long	min;
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
		min = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = 
		}
	}
}
*/
