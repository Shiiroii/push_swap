/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 00:11:06 by lionelulm         #+#    #+#             */
/*   Updated: 2025/02/11 15:06:23 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*end;

	if (!*stack || !(*stack)->next)
		return ;
	end = find_end(*stack);
	end->previous->next = NULL;
	end->next = *stack;
	end->previous = NULL;
	*stack = end;
	end->next->previous = end;
}

void	rev_rotate_a(t_stack **stacka, bool test)
{
	rev_rotate(stacka);
	if (!test)
		ft_printf("rra\n");
}

void	rev_rotate_b(t_stack **stackb, bool test)
{
	rev_rotate(stackb);
	if (!test)
		ft_printf("rrb\n");
}

void	rev_rotate_ab(t_stack **stacka, t_stack **stackb, bool test)
{
	rev_rotate(stacka);
	rev_rotate(stackb);
	if (!test)
		ft_printf("rrr\n");
}
