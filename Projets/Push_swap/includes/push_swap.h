/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <ellucas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:34:21 by ellucas           #+#    #+#             */
/*   Updated: 2025/03/03 16:00:51 by ellucas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

/* struct element e la pile */
typedef struct s_node
{
	int				value;	/* Valeur de l'element */
	struct s_node	*next;	/* Pointeur vers element suivant */
	struct s_node	*prev;	/* Pointeur vers element precedent */
}	t_node;

/* Struct gestion de la pile */
typedef struct s_stack
{
	t_node	*top;	/* Pointeur vers sommet de la pile */
	t_node	*bottom;	/* Pointeur vers bas de la pile */
	int		size;	/* Taille de la pile */
}	t_stack;

/* Struct principal gest des deux piles */
typedef struct s_program
{
	t_stack	*stack_a;	/* pile A */
	t_stack	*stack_b;	/* Pile B */
}	t_program;

t_stack *init_stack(void);
int push_to_stack(t_stack *stack, int value);
void print_stack(t_stack *stack);
void free_stack(t_stack *stack);
void	sa(t_stack *stack_a);
void	sb(t_stack	*stack_b);
void	ss(t_stack	*stack_a, t_stack	*stack_b);
void	pa(t_stack *stack_b, t_stack *stack_a);
void	pb(t_stack *stack_a, t_stack *stack_b);

#endif
