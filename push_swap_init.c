/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selango <selango@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-17 10:41:39 by selango           #+#    #+#             */
/*   Updated: 2024-09-17 10:41:39 by selango          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*set the above_median*/
void	set_current_position(t_stack_node *stack)
{
	int	i;
	int	centerline;

	i = 0;
	if (stack == NULL)
		return ;
	centerline = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= centerline)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

/*set the target_node of b if the value is closer to b 
else if all the values are higher set target_node as (smallest_node) in a*/
static void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if ((current_a->value > b->value)
				&& (current_a->value < best_match_index))
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_match_index)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

/*set_price sets cost according to the target_node set in a*/
void	set_price(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_cost = b->current_position;
		if (!(b->above_median))
			b->push_cost = len_b - (b->current_position);
		if (b->target_node->above_median)
			b->push_cost += b->target_node->current_position;
		else
			b->push_cost += len_a - (b->target_node->current_position);
		b = b->next;
	}
}

/*sets  the push_cost in b cheapest node*/
void	set_cheapest(t_stack_node *b)
{
	long				best_match_value;
	t_stack_node		*best_match_node;

	best_match_value = LONG_MAX;
	if (b == NULL)
		return ;
	while (b)
	{
		if (b->push_cost < best_match_value)
		{
			best_match_value = b->push_cost;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest = true;
}

/*init nodes by currently setting the position*/
void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}
