/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <ellucas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:50:46 by ellucas           #+#    #+#             */
/*   Updated: 2025/02/19 16:52:00 by ellucas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	swap_a(int *a)
{
	int	temp;

	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
}

void	swap_b(int *b)
{
	int	temp;

	temp = b[0];
	b[0] = b[1];
	b[1] = temp;
}

void	swap_a_b(int *a, int *b)
{
	swap_a(a);
	swap_b(b);
}

int	*stack_a(char **av, int size)
{
	int	*stack_a;

	stack_a = (int *)malloc(sizeof(int) * (size));
	while (size > 0)
	{
		stack_a[size - 1] = atoi(av[size]);
		size--;
	}
	return (stack_a);
}

int	main(int ac, char **av)
{
	if (ac < 3)
		return(0);
	int	size = ac - 1;
	int	*tab = stack_a(av, size);
	printf("stack_a : ");
	while (size < ac - 1)
	{
		printf("%d ", tab[size + 1]);
		size++;
	}
}