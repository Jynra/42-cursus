/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jynra <jynra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:20:10 by ellucas           #+#    #+#             */
/*   Updated: 2025/03/27 18:23:14 by jynra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0])) //if (ac <= 2)
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
//		av = split(av[1], ' ');
//	ft_printf("split executer correctement\n"); // DEBUG
	init_stack_a(&a, av + 1);

	if (!stack_sorted(a))
	{
//		ft_printf("stack pas sorted\n"); // DEBUG
		if (stack_len(a) == 2)
		{
//			ft_printf("stack_len = %d\n", stack_len(a)); // DEBUG
			sa(&a, false);
		}
		else if (stack_len(a) == 3)
		{
//			ft_printf("stack_len = %d\n", stack_len(a)); // DEBUG
			sort_three(&a);
		}
		else
		{
//			ft_printf("stack_len = %d\n", stack_len(a)); // DEBUG
			sort_stacks(&a, &b);
		}
	}
//	ft_printf("Sorted finish\n"); // DEBUG
	free_stack(&a);
	return (0);
}
