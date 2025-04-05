/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 00:18:19 by lionelulm         #+#    #+#             */
/*   Updated: 2025/02/11 15:06:23 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*end;

	if (!*stack || !(*stack)->next)
		return ;
	end = find_end(*stack);
	end->next = *stack;
	*stack = (*stack)->next;
	(*stack)->previous = NULL;
	end->next->previous = end;
	end->next->next = NULL;
}

void	rotate_a(t_stack **stacka, bool test)
{
	rotate(stacka);
	if (!test)
		ft_printf("ra\n");
}

void	rotate_b(t_stack **stackb, bool test)
{
	rotate(stackb);
	if (!test)
		ft_printf("rb\n");
}

void	rotate_ab(t_stack **stacka, t_stack **stackb, bool test)
{
	rotate(stacka);
	rotate(stackb);
	if (!test)
		ft_printf("rr\n");
}
