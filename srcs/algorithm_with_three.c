/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_with_three.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 00:38:46 by lionelulm         #+#    #+#             */
/*   Updated: 2025/02/11 15:06:23 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_with_three(t_stack **stacka)
{
	t_stack	*max;

	max = find_max(*stacka);
	if (max == *stacka)
		rotate_a(stacka, false);
	else if ((*stacka)->next == max)
		rev_rotate_a(stacka, false);
	if ((*stacka)->nb > (*stacka)->next->nb)
		swap_a(stacka, false);
}
