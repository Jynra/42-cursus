/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <ellucas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:00:14 by ellucas           #+#    #+#             */
/*   Updated: 2025/03/25 15:19:31 by ellucas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	swap(t_stack_node **first)
{
	if (!*first || !(*first)->next)
		return ;
	*first = (*first)->next;
	(*first)->prev->prev = *first;
	(*first)->prev->next = (*first)->next;
	if ((*first)->next)
		(*first)->next->prev = (*first)->prev;
	(*first)->next = (*first)->prev;
	(*first)->prev = NULL;
}

void	sa(t_stack_node **a, bool print)
{
	swap(a);
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool print)
{
	swap(b);
	if (!print)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("ss\n");
}