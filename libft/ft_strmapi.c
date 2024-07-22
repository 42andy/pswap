/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:32:03 by astoll            #+#    #+#             */
/*   Updated: 2023/11/01 12:09:10 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	size;
	unsigned int	i;
	char			*str;

	size = ft_strlen(s);
	i = 0;
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
	{
		return (0);
	}
	while (i < size)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[size] = '\0';
	return (str);
}
