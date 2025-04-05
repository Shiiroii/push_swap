/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 00:40:28 by lionelulm         #+#    #+#             */
/*   Updated: 2025/02/11 15:06:23 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_stack **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	*stack = (*stack)->next;
	(*stack)->previous->previous = *stack;
	(*stack)->previous->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->previous = (*stack)->previous;
	(*stack)->next = (*stack)->previous;
	(*stack)->previous = NULL;
}

void	swap_a(t_stack **stacka, bool test)
{
	swap(stacka);
	if (!test)
		ft_printf("sa\n");
}

void	swap_b(t_stack **stackb, bool test)
{
	swap(stackb);
	if (!test)
		ft_printf("sb\n");
}

void	swap_ab(t_stack **stacka, t_stack **stackb, bool test)
{
	swap(stacka);
	swap(stackb);
	if (!test)
		ft_printf("ss\n");
}
