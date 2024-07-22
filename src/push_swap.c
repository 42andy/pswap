/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 08:31:55 by astoll            #+#    #+#             */
/*   Updated: 2024/07/22 15:13:23 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"


static void	check_args(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	if (argc < 2)
		exit(1);
	while (i < argc)
	{
		j = 0;
		if (!argv[i][0] || (argv[i][0] && argv[i][0] == ' '))
		{
			write(1, "Error\n", 6);
			exit (1);
		}
		while (argv[i][j] != '\0')
		{
			if ((!(ft_isdigit(argv[i][j])) && (argv[i][j] != ' ')))
			{
				write(1, "Error\n", 6);
				exit (1);
			}
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