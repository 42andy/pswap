/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:11:24 by astoll            #+#    #+#             */
/*   Updated: 2024/07/22 20:40:38 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	create_stacks(int argc, char *argv[], t_stack *stack)
{
	int	i;

	i = 0;
	stack->size_a = 0;
	stack->size_b = 0;
	while (--argc)
	{
		if (ft_count(argv[i + 1], ' '))
			stack->size_a += ft_count(argv[i + 1], ' ');
		else
			stack->size_a++;
		i++;
	}
	stack->a = malloc(stack->size_a * sizeof * stack->a);
	if (stack->a == NULL)
	{
		write(1, "Error\n", 6);
		free_exit(stack);
	}
	stack->b = malloc(stack->size_a * sizeof * stack->b);
	if (stack->b == NULL)
	{
		write(1, "Error\n", 6);
		free_exit(stack);
	}
}

void	chain_args(int argc, char *argv[], t_stack *stack)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 1;
	tmp2 = ft_strdup("");
	while (i < argc && argv[i] != NULL)
	{
		tmp = ft_strjoin(tmp2, argv[i]);
		if (tmp2)
			free(tmp2);
		if (i != argc - 1)
		{
			tmp2 = ft_strjoin(tmp, " ");
			if (tmp)
				free(tmp);
			tmp = tmp2;
		}
		i++;
	}
	stack->chained = ft_strdup(tmp);
	if (stack->chained == NULL)
	{
		write(1, "Error\n", 6);
		free_exit(stack);
	}
	if (tmp)
		free(tmp);
}

void	split_chain(t_stack *stack)
{
	char	**tmp;
	int		i;
	int		j;

	j = 0;
	tmp = ft_split(stack->chained, ' ');
	i = 0;
	while (tmp[i] != NULL && tmp[i][0] != '\0')
	{
		stack->a[j++] = ft_atol(tmp[i++], stack);
		free(tmp[i - 1]);
	}
	free(tmp);
}

void	dup_check(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stack->size_a)
	{
		j = i + 1;
		while (j < stack->size_a)
		{
			if (stack->a[i] == stack->a[j])
			{
				write(1, "Error\n", 6);
				free_exit(stack);
			}
			j++;
		}
		i++;
	}
}

void	init_index(t_stack *stack)
{
	int		i;
	int		j;
	int		k;
	int		*index_a;

	index_a = malloc(stack->size_a * sizeof * index_a);
	if (index_a == NULL)
	{
		write(1, "Error\n", 6);
		free_exit(stack);
	}
	i = -1;
	while (++i < stack->size_a)
	{
		k = 0;
		j = -1;
		while (++j < stack->size_a)
			if (stack->a[i] > stack->a[j])
				k++;
		index_a[i] = k;
	}
	i = stack->size_a;
	while (i--)
		stack->a[i] = index_a[i];
	free(index_a);
}
