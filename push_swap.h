/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selango <selango@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-17 11:01:54 by selango           #+#    #+#             */
/*   Updated: 2024-09-17 11:01:54 by selango          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					final_index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

char			**ft_split(char *str, char sep);

// handle error
void			free_matrix(char **argv);
void			free_stack(t_stack_node **stack);
void			error_free(t_stack_node **a, char **argv, bool flag_argc_2);

int				error_syntax(char *str);
int				error_repetition(t_stack_node *a, int nbr);
int				ft_isdigit(int s);

// stack init
void			stack_init(t_stack_node **a, char **argv, bool flag_argv_2);
bool			stack_sorted(t_stack_node *stack);

// node operations
t_stack_node	*find_highest(t_stack_node *stack);
t_stack_node	*find_smallest(t_stack_node *stack);
int				stack_len(t_stack_node *stack);

// stack utils
t_stack_node	*find_last(t_stack_node *head);
void			append_node(t_stack_node **stack, int n);
t_stack_node	*return_cheapest(t_stack_node *stack);

// commands
void			rra(t_stack_node **a, bool checker);
void			rrb(t_stack_node **b, bool checker);
void			rrr(t_stack_node **a, t_stack_node **b, bool checker);

// rotate
void			ra(t_stack_node **a, bool checker);
void			rb(t_stack_node **b, bool checker);
void			rr(t_stack_node **a, t_stack_node **b, bool checker);

// push
void			pa(t_stack_node **a, t_stack_node **b, bool checker);
void			pb(t_stack_node **a, t_stack_node **b, bool checker);

// swap
void			sa(t_stack_node **a, bool checker);
void			sb(t_stack_node **b, bool checker);
void			ss(t_stack_node **a, t_stack_node **b, bool checker);

// algo init
void			set_current_position(t_stack_node *stack);
void			init_nodes(t_stack_node *a, t_stack_node *b);

// algo
void			handle_three(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b);
void			finish_rotation(t_stack_node **stack, t_stack_node *top_node,
					char stack_name);
void			push_swap(t_stack_node **a, t_stack_node **b);

#endif
