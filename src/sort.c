/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:29:07 by astoll            #+#    #+#             */
/*   Updated: 2024/07/22 20:41:47 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_3(t_stack *stack)
{
	if (stack->a[2] != 2)
	{
		if (stack->a[0] == 2)
			rotatea(stack->a, stack->size_a);
		else
			rrotatea(stack->a, stack->size_a);
	}
	if (stack->a[0] > stack->a[1])
		swapa(stack->a);
}

void	sort_4_5(t_stack *stack)
{
	while (stack->size_b <= 1)
	{
		if (stack->a[0] == 0 || stack->a[0] == 1)
			pushb(stack);
		else
			rotatea(stack->a, stack->size_a);
	}
	if (stack->b[0] == 0)
		swapb(stack->b);
	if (stack->a[2] != 4)
	{
		if (stack->a[0] == 4)
			rotatea(stack->a, stack->size_a);
		else
			rrotatea(stack->a, stack->size_a);
	}
	if (stack->a[0] > stack->a[1])
		swapa(stack->a);
	pusha(stack);
	pusha(stack);
}

void	sort(t_stack *stack)
{
	if (stack->size_a == 2 && stack->a[0] > stack->a[1])
		swapa(stack->a);
	else if (stack->size_a == 3)
		sort_3(stack);
	else if (stack->size_a >= 4 && stack->size_a <= 5)
		sort_4_5(stack);
	else
		radix_sort(stack);
}
