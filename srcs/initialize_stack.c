/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 01:39:43 by lionelulm         #+#    #+#             */
/*   Updated: 2025/02/11 15:06:23 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static long	ft_atol(const char *str)
{
	int		i;
	long	res;

	i = 1;
	res = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			i = -1;
		str++;
	}
	while (ft_isdigit(*str))
		res = res * 10 + (*str++ - '0');
	return (res * i);
}

static void	use_last(t_stack **stack, int i)
{
	t_stack	*buffer;
	t_stack	*last;

	if (!stack)
		return ;
	buffer = malloc(sizeof(t_stack));
	if (!buffer)
		return ;
	buffer->next = NULL;
	buffer->nb = i;
	if (!(*stack))
	{
		*stack = buffer;
		buffer->previous = NULL;
	}
	else
	{
		last = find_end(*stack);
		last->next = buffer;
		buffer->previous = last;
	}
}

void	initialize_stack_a(t_stack **stacka, char **argv)
{
	int		i;
	long	n;

	i = 0;
	while (argv[i])
	{
		if (syntax(argv[i]))
			free_error(stacka);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_error(stacka);
		if (doubles(*stacka, n))
			free_error(stacka);
		use_last(stacka, n);
		i++;
	}
}

t_stack	*get_lowest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->lowest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	ready_to_push(t_stack **stack, t_stack *buffer, char c)
{
	while (*stack != buffer)
	{
		if (c == 'a')
		{
			if (buffer->median)
				rotate_a(stack, false);
			else
				rev_rotate_a(stack, false);
		}
		else if (c == 'b')
		{
			if (buffer->median)
				rotate_b(stack, false);
			else
				rev_rotate_b(stack, false);
		}
	}
}
