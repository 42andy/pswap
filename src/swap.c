/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:44:27 by astoll            #+#    #+#             */
/*   Updated: 2024/07/22 14:34:13 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swapa(int *tab)
{
	int	tmp;
	
	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
	write(1, "sa\n", 3);
}

void	swapb(int *tab)
{
	int	tmp;
	
	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
	write(1, "sb\n", 3);
}