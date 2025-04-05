/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 01:16:35 by lionelulm         #+#    #+#             */
/*   Updated: 2025/02/11 15:06:23 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	target_b(t_stack *stacka, t_stack *stackb)
{
	t_stack	*buffer;
	t_stack	*target;
	long	index;

	while (stackb)
	{
		index = LONG_MAX;
		buffer = stacka;
		while (buffer)
		{
			if (buffer->nb > stackb->nb && buffer->nb < index)
			{
				index = buffer->nb;
				target = buffer;
			}
			buffer = buffer->next;
		}
		if (index == LONG_MAX)
			stackb->objective = find_min(stacka);
		else
			stackb->objective = target;
		stackb = stackb->next;
	}
}

void	initialize_b(t_stack *stacka, t_stack *stackb)
{
	init_i(stacka);
	init_i(stackb);
	target_b(stacka, stackb);
}

void	b_to_a(t_stack **stacka, t_stack **stackb)
{
	ready_to_push(stacka, (*stackb)->objective, 'a');
	push_a(stacka, stackb, false);
}
