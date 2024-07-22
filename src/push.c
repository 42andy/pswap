/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:26:17 by astoll            #+#    #+#             */
/*   Updated: 2024/07/22 14:30:32 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	pusha(t_stack *stack)
{
	int	tmp;
	
	tmp = stack->b[0];
	ft_memmove(stack->a + 1, stack->a, sizeof(int) * stack->size_a);
	stack->a[0] = tmp;
	stack->size_b--;
	ft_memmove(stack->b, stack->b + 1, sizeof(int) * stack->size_b);
	stack->size_a++;
	write(1, "pa\n", 3);
}

void	pushb(t_stack *stack)
{
	int	tmp;
	
	tmp = stack->a[0];
	ft_memmove(stack->b + 1, stack->b, sizeof(int) * stack->size_b);
	stack->b[0] = tmp;
	stack->size_a--;
	ft_memmove(stack->a, stack->a + 1, sizeof(int) * stack->size_a);
	stack->size_b++;
	write(1, "pb\n", 3);
}