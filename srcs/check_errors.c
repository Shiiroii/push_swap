/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 00:42:46 by lionelulm         #+#    #+#             */
/*   Updated: 2025/02/11 15:06:23 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	syntax(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

int	doubles(t_stack *stacka, int n)
{
	if (!stacka)
		return (0);
	while (stacka)
	{
		if (stacka->nb == n)
			return (1);
		stacka = stacka->next;
	}
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*index;

	if (!stack)
		return ;
	index = *stack;
	while (index)
	{
		tmp = index->next;
		index->nb = 0;
		free(index);
		index = tmp;
	}
	*stack = NULL;
}

void	free_error(t_stack **stacka)
{
	free_stack(stacka);
	ft_printf("Error\n");
	exit(1);
}
