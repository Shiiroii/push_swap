/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 00:04:30 by lionelulm         #+#    #+#             */
/*   Updated: 2025/02/11 15:06:23 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push(t_stack **dest, t_stack **source)
{
	t_stack	*push_i;

	if (!*source)
		return ;
	push_i = *source;
	*source = (*source)->next;
	if (*source)
		(*source)->previous = NULL;
	push_i->previous = NULL;
	if (!*dest)
	{
		*dest = push_i;
		push_i->next = NULL;
	}
	else
	{
		push_i->next = *dest;
		push_i->next->previous = push_i;
		*dest = push_i;
	}
}

void	push_a(t_stack **a, t_stack **b, bool test)
{
	push(a, b);
	if (!test)
		ft_printf("pa\n");
}

void	push_b(t_stack **b, t_stack **a, bool test)
{
	push(b, a);
	if (!test)
		ft_printf("pb\n");
}
