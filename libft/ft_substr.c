/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:28:54 by astoll            #+#    #+#             */
/*   Updated: 2023/11/18 14:17:52 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*str;

	slen = ft_strlen(s);
	if (!s)
	{
		return (0);
	}
	if (slen < start)
	{
		return (ft_strdup(""));
	}
	slen = slen - start;
	if (slen < len)
	{
		len = slen;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
	{
		return (0);
	}
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

//bing version (substr + strlcpy)
/*char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*str;
	size_t	i;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (slen < start)
		return (ft_strdup(""));
	slen = slen - start;
	if (slen < len)
		len = slen;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	i = 0;
	while (s[i + start] && i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}*/