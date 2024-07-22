/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:04:31 by astoll            #+#    #+#             */
/*   Updated: 2023/11/07 22:11:22 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
			{
				i++;
			}
			if (s[i] == '\0')
			{
				return (count);
			}
		}
		i++;
	}
	return (count);
}

static size_t	ft_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
	}
	return (i);
}

static void	ft_free(size_t i, char **array)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
}

static char	**split(char const *s, char c, char **array, size_t count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < count)
	{
		while (s[j] != '\0' && s[j] == c)
		{
			j++;
		}
		array[i] = ft_substr(s, j, ft_len(&s[j], c));
		if (!(array[i]))
		{
			ft_free(i, array);
			return (NULL);
		}
		while (s[j] != '\0' && s[j] != c)
		{
			j++;
		}
		i++;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
	{
		return (NULL);
	}
	array = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!array)
	{
		return (NULL);
	}
	array = split(s, c, array, ft_count(s, c));
	return (array);
}
