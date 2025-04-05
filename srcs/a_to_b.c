/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 00:50:36 by lionelulm         #+#    #+#             */
/*   Updated: 2025/02/11 15:06:23 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_i(t_stack *stack)
{
	int	index;
	int	median;

	index = 0;
	if (!stack)
		return ;
	median = stack_length(stack) / 2;
	while (stack)
	{
		stack->index = index;
		if (index <= median)
			stack->median = true;
		else
			stack->median = false;
		stack = stack->next;
		++index;
	}
}

static void	target_a(t_stack *stacka, t_stack *stackb)
{
	t_stack	*buffer;
	t_stack	*target;
	long	index;

	while (stacka)
	{
		index = LONG_MIN;
		buffer = stackb;
		while (buffer)
		{
			if (buffer->nb < stacka->nb && buffer->nb > index)
			{
				index = buffer->nb;
				target = buffer;
			}
			buffer = buffer->next;
		}
		if (index == LONG_MIN)
			stacka->objective = find_max(stackb);
		else
			stacka->objective = target;
		stacka = stacka->next;
	}
}

static void	cost_a(t_stack *stacka, t_stack *stackb)
{
	int	stacka_length;
	int	stackb_length;

	stacka_length = stack_length(stacka);
	stackb_length = stack_length(stackb);
	while (stacka)
	{
		stacka->push = stacka->index;
		if (!(stacka->median))
			stacka->push += stacka_length - (stacka->index);
		if (stacka->objective->median)
			stacka->push += stacka->objective->index;
		else
			stacka->push += stackb_length - (stacka->objective->index);
		stacka = stacka->next;
	}
}

void	init_lowest(t_stack *stack)
{
	t_stack	*low;
	long	index;

	if (!stack)
		return ;
	index = LONG_MAX;
	while (stack)
	{
		if (stack->push < index)
		{
			index = stack->push;
			low = stack;
		}
		stack = stack->next;
	}
	low->lowest = true;
}

void	initialize_a(t_stack *stacka, t_stack *stackb)
{
	init_i(stacka);
	init_i(stackb);
	target_a(stacka, stackb);
	cost_a(stacka, stackb);
	init_lowest(stacka);
}
