/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 00:20:13 by lionelulm         #+#    #+#             */
/*   Updated: 2025/02/11 15:06:23 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate_ab_stack(t_stack **stacka, t_stack **stackb, t_stack *index)
{
	while (*stackb != index->objective && *stacka != index)
		rotate_ab(stacka, stackb, false);
	init_i(*stacka);
	init_i(*stackb);
}

static void	rev_rot_ab_stack(t_stack **stacka, t_stack **stackb, t_stack *index)
{
	while (*stackb != index->objective && *stacka != index)
		rev_rotate_ab(stacka, stackb, false);
	init_i(*stacka);
	init_i(*stackb);
}

static void	a_to_b(t_stack **stacka, t_stack **stackb)
{
	t_stack	*index;

	index = get_lowest(*stacka);
	if (index->median && index->objective->median)
		rotate_ab_stack(stacka, stackb, index);
	else if (!(index->median) && index->objective->median)
		rev_rot_ab_stack(stacka, stackb, index);
	ready_to_push(stacka, index, 'a');
	ready_to_push(stackb, index->objective, 'b');
	push_b(stackb, stacka, false);
}

static void	min_to_top(t_stack **stacka)
{
	while ((*stacka)->nb != find_min(*stacka)->nb)
	{
		if (find_min(*stacka)->median)
			rotate_a(stacka, false);
		else
			rev_rotate_a(stacka, false);
	}
}

void	algorithm(t_stack **stacka, t_stack **stackb)
{
	int	stacka_length;

	stacka_length = stack_length(*stacka);
	if (stacka_length-- > 3 && !is_it_sorted(*stacka))
		push_b(stackb, stacka, false);
	while (stacka_length-- > 3 && !is_it_sorted(*stacka))
	{
		initialize_a(*stacka, *stackb);
		a_to_b(stacka, stackb);
	}
	sort_with_three(stacka);
	while (*stackb)
	{
		initialize_b(*stacka, *stackb);
		b_to_a(stacka, stackb);
	}
	init_i(*stacka);
	min_to_top(stacka);
}
