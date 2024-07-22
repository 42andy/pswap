/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:43:35 by astoll            #+#    #+#             */
/*   Updated: 2023/11/18 11:17:24 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*dst;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	dst = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!dst)
	{
		return (0);
	}
	ft_strlcpy(dst, s1, (s1len + 1));
	ft_strlcat(dst, s2, (s1len + s2len + 1));
	return (dst);
}

//better strjoin (pasquale)
/*char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	j = 0;
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)
	{
		return (0);
	}
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		dst[i + j] = s2[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}*/