/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:37:46 by astoll            #+#    #+#             */
/*   Updated: 2024/07/22 14:04:03 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_a - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	radix_sort_b(t_stack *stack, int size_b, int bit_size, int j)
{
	while (size_b-- && j <= bit_size && !is_sorted(stack))
	{
		if (((stack->b[0] >> j) & 1) == 0)
			rotateb(stack->b, stack->size_b);
		else
			pusha(stack);
	}
	if (is_sorted(stack))
		while (stack->size_b != 0)
			pusha(stack);
}


void	radix_sort(t_stack *stack)
{
	int	j;
	int	bit_size;
	int	size;

	bit_size = 0;
	size = stack->size_a;
	while (size > 1 && ++bit_size)
		size /= 2;
	j = -1;
	while (++j <= bit_size)
	{
		size = stack->size_a;
		while (size-- && !is_sorted(stack))
		{
			if (((stack->a[0] >> j) & 1) == 0)
				pushb(stack);
			else
				rotatea(stack->a, stack->size_a);
		}
		radix_sort_b(stack, stack->size_b, bit_size, j + 1);
	}
	while (stack->size_b != 0)
		pusha(stack);
}