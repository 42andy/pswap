/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 08:25:26 by astoll            #+#    #+#             */
/*   Updated: 2024/07/22 20:35:10 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int		*a;
	int		size_a;
	int		*b;
	int		size_b;
	char	*chained;
}			t_stack;

void	pusha(t_stack *stack);
void	pushb(t_stack *stack);
void	rotatea(int *tab, int size);
void	rrotatea(int *tab, int size);
void	rotateb(int *tab, int size);
void	swapa(int *tab);
void	swapb(int *tab);
void	radix_sort(t_stack *stack);
void	radix_sort_b(t_stack *stack, int size_b, int bit_size, int j);
int		is_sorted(t_stack *stack);
void	sort(t_stack *stack);
void	sort_3(t_stack *stack);
void	sort_4_5(t_stack *stack);
void	create_stacks(int argc, char *argv[], t_stack *stack);
void	chain_args(int argc, char *argv[], t_stack *stack);
void	split_chain(t_stack *stack);
void	dup_check(t_stack *stack);
void	init_index(t_stack *stack);
void	sort_check(t_stack *stack);
int		ft_atol(const char *str, t_stack *stack);
int		ft_count(char const *stack, char c);
void	free_exit(t_stack *stack);

#endif