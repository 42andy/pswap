/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 08:31:55 by astoll            #+#    #+#             */
/*   Updated: 2024/07/22 20:41:07 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	check_args(int argc, char *argv[])
{
	int	i;
	int	j;

	if (argc < 2)
		exit(1);
	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == '\0' || argv[i][0] == ' ')
			exit(write(2, "Error\n", 6));
		while (argv[i][j])
		{
			if ((argv[i][j] == '-' || argv[i][j] == '+') &&
				(!ft_isdigit(argv[i][j + 1]) || (j > 0 &&
				ft_isdigit(argv[i][j - 1]))))
				exit(write(2, "Error\n", 6));
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' ' &&
				argv[i][j] != '-' && argv[i][j] != '+')
				exit(write(2, "Error\n", 6));
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*stack;

	check_args(argc, argv);
	stack = malloc(sizeof * stack);
	if (stack == NULL)
		exit(1);
	create_stacks(argc, argv, stack);
	chain_args(argc, argv, stack);
	split_chain(stack);
	dup_check(stack);
	sort_check(stack);
	init_index(stack);
	sort(stack);
	sort_check(stack);
	free_exit(stack);
	return (0);
}
