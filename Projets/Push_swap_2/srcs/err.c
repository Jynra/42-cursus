/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jynra <jynra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:21:40 by jynra             #+#    #+#             */
/*   Updated: 2025/03/14 16:05:21 by jynra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int err_syntaxe(char *str)
{
    if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
        return (1);
    if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
        return (1);
    while (*++str)
    {
        if (!(*str >= '0' && *str <= '9'))
            return (1);
    }
    return (0);
}

int err_duplicate(t_stack_node *a, int n)
{
    if (!a)
        return (0);
    while (a)
    {
        if (a->nbr == n)
            return (1);
        a = a->next;
    }
    return (0);
}

void    free__stack(t_stack_node **stack)
{
    t_stack_node    *tmp;
    t_stack_node    *current;

    if (!stack)
        return ;
    current = *stack;
    while (current)
    {
        tmp = current->next;
        current->nbr = 0;
        free(current);
        current = tmp;
    }
    *stack = NULL;
}

void    free_err(t_stack_node **a)
{
    free_stack(a);
    ft_printf("Error\n"); // A personnaliser en fonction des erreurs
    exit(1);
}