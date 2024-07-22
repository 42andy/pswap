/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:10:03 by astoll            #+#    #+#             */
/*   Updated: 2024/07/22 20:42:10 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotatea(int *tab, int size)
{
	int	tmp;

	tmp = tab[0];
	ft_memmove(tab, tab + 1, sizeof(int) * (size - 1));
	tab[size - 1] = tmp;
	write(1, "ra\n", 3);
}

void	rrotatea(int *tab, int size)
{
	int	tmp;

	tmp = tab[size - 1];
	ft_memmove(tab + 1, tab, sizeof(int) * (size - 1));
	tab[0] = tmp;
	write(1, "rra\n", 4);
}

void	rotateb(int *tab, int size)
{
	int	tmp;

	tmp = tab[0];
	ft_memmove(tab, tab + 1, sizeof(int) * (size - 1));
	tab[size - 1] = tmp;
	write(1, "rb\n", 3);
}
