/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 01:22:28 by lionelulm         #+#    #+#             */
/*   Updated: 2025/02/11 15:06:23 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack	*stackb;

	stacka = NULL;
	stackb = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	initialize_stack_a(&stacka, argv + 1);
	if (!is_it_sorted(stacka))
	{
		if (stack_length(stacka) == 2)
			swap_a(&stacka, false);
		else if (stack_length(stacka) == 3)
			sort_with_three(&stacka);
		else
			algorithm(&stacka, &stackb);
	}
	free_stack(&stacka);
	return (0);
}
