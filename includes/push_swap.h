/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 23:58:28 by lionelulm         #+#    #+#             */
/*   Updated: 2025/02/11 15:07:45 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdbool.h>
# include "../utils/libft/libft.h"
# include "../utils/ft_printf/ft_printf.h"
# include <limits.h>

typedef struct s_stack
{
	int				nb;
	int				index;
	int				push;
	bool			median;
	bool			lowest;
	struct s_stack	*next;
	struct s_stack	*previous;
	struct s_stack	*objective;
}	t_stack;

// ============================ MOVES ==================================

void	push_a(t_stack **a, t_stack **b, bool test);
void	push_b(t_stack **b, t_stack **a, bool test);
void	rotate_a(t_stack **stacka, bool test);
void	rotate_b(t_stack **stackb, bool test);
void	rotate_ab(t_stack **stacka, t_stack **stackb, bool test);
void	rev_rotate_a(t_stack **stacka, bool test);
void	rev_rotate_b(t_stack **stackb, bool test);
void	rev_rotate_ab(t_stack **stacka, t_stack **stackb, bool test);
void	swap_a(t_stack **stacka, bool test);
void	swap_b(t_stack **stackb, bool test);
void	swap_ab(t_stack **stacka, t_stack **stackb, bool test);

// ========================== SORTING ==================================

void	algorithm(t_stack **stacka, t_stack **stackb);
void	sort_with_three(t_stack **stacka);
void	b_to_a(t_stack **stacka, t_stack **stackb);

// =========================== INIT ====================================

void	initialize_a(t_stack *stacka, t_stack *stackb);
void	initialize_b(t_stack *stacka, t_stack *stackb);
void	initialize_stack_a(t_stack **stacka, char **argv);
t_stack	*get_lowest(t_stack *stack);
void	ready_to_push(t_stack **stack, t_stack *buffer, char c);
void	init_lowest(t_stack *stack);

// ========================== ERRORS ===================================

void	free_error(t_stack **stacka);
void	free_stack(t_stack **stack);
int		doubles(t_stack *stacka, int n);
int		syntax(char *str);

// =========================== UTILS ===================================

bool	is_it_sorted(t_stack *stack);
void	init_i(t_stack *stack);
int		stack_length(t_stack *stack);
t_stack	*find_end(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);

//======================================================================

#endif
