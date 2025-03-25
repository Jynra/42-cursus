/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <ellucas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:14:16 by ellucas           #+#    #+#             */
/*   Updated: 2025/03/25 16:58:57 by ellucas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_medium;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

/* Init */
void			init_stack_a(t_stack_node **a, char **av);

/* Sort */
void			current_index(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
void			sort_three(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b);

/* Utils */
int				stack_len(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);

/* init_a_to_b */
void	init_node_a(t_stack_node *a, t_stack_node *b);
void	set_cheapest(t_stack_node *stack);

/* push */
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **b, t_stack_node **a, bool print);

/* rotate */
void			rotate(t_stack_node **stack);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **a, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);

/* rev_rotate */
void			rev_rotate(t_stack_node **stack);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);

/* swap */
void			swap(t_stack_node **first);
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);

/* Errors */
int				err_syntaxe(char *str);
int				err_duplicate(t_stack_node *a, int n);
void			free__stack(t_stack_node **stack);
void			free_err(t_stack_node **a);

#endif