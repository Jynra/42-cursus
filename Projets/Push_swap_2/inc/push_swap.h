/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jynra <jynra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:14:16 by ellucas           #+#    #+#             */
/*   Updated: 2025/03/26 01:14:42 by jynra            ###   ########.fr       */
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
void			prep_for_push(t_stack_node **stack, t_stack_node *top_node, char stack_name);
t_stack_node	*get_cheapest(t_stack_node *stack);

/* Sort */
void			current_index(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
void			sort_three(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b);

/* sort_stack__utils (need check) */
void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node);
void	rev_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node);
void	move_a_to_b(t_stack_node **a, t_stack_node **b);
void	move_b_to_a(t_stack_node **a, t_stack_node **b);
void	min_on_top(t_stack_node **a);


/* Utils */
int				stack_len(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);

/* init_a_to_b */
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *stack);

/* init_b__to_a */
void			init_nodes_b(t_stack_node *a, t_stack_node *b);

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
int				err_syntax(char *str);
int				err_duplicate(t_stack_node *a, int n);
void			free_stack(t_stack_node **stack);
void			free_err(t_stack_node **a);

#endif