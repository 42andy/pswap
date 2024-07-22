/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:41:53 by astoll            #+#    #+#             */
/*   Updated: 2024/07/22 15:11:59 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_exit(t_stack *stack)
{
	if (stack != NULL)
	{
		if (stack->a != NULL)
			free(stack->a);
		if (stack->b != NULL)
			free(stack->b);
		if (stack->chained != NULL)
			free(stack->chained);
		if (stack != NULL)
			free(stack);
	}
	exit(1);
}


int	ft_count(char const *stack, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (stack[i] != '\0')
	{
		if (stack[i] != c)
		{
			count++;
			while (stack[i] != '\0' && stack[i] != c)
				i++;
			if (stack[i] == '\0')
				return (count);
		}
		i++;
	}
	return (count);
}

int	ft_atol(const char *str, t_stack *stack)
{
	int			i;
	long		sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if ((str[i] == 43 || str[i] == 45))
	{
		if (str[i] == 45)
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (result > 2147483647 || (result * sign) < -2147483648 || ft_strlen(str) > 11)
		{
			write(1, "Error\n", 6);
			free_exit(stack);
		}
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			write(1, "Error\n", 6);
			free_exit(stack);
		}
		result = result * 10;
		result += str[i] - 48;
		i++;
	}
	return ((int)(result * sign));
}

void	sort_check(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_a - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
			return ;
		i++;
	}
	free_exit(stack);
}