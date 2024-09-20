/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selango <selango@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-17 11:16:07 by selango           #+#    #+#             */
/*   Updated: 2024-09-17 11:16:07 by selango          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int s)
{
	return (s >= '0' && s <= '9');
}

static long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*s == 32) || (*s >= 9 && *s <= 13))
	{
		s++;
	}
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

/*initialzing stack a 
 checks for correct input, repetition of numbers 
 and free the memory(using error_free)
 append_node in stack a
 */
void	stack_init(t_stack_node **a, char **argv, bool flag_argv_2)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a, argv, flag_argv_2);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			error_free(a, argv, flag_argv_2);
		if (error_repetition(*a, (int)n))
			error_free(a, argv, flag_argv_2);
		append_node(a, (int)n);
		i++;
	}
	if (flag_argv_2)
		free_matrix(argv);
}
