/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:57:42 by mberne            #+#    #+#             */
/*   Updated: 2020/12/16 14:53:29 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*ns;
	size_t	lens1;
	size_t	lens2;

	i = -1;
	j = -1;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!s1 && !s2)
		return (0);
	if (!(ns = malloc(sizeof(char) * ((lens1 + lens2 + 1)))))
		return (0);
	while (++i < lens1)
		ns[i] = s1[i];
	while (++j < lens2)
		ns[i + j] = s2[j];
	ns[i + j] = '\0';
	free((char *)s1);
	return (ns);
}

int		ft_strchr(const char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ns;
	char	*str;
	size_t	len_str;

	i = 0;
	str = (char *)s;
	if (!s)
		return (0);
	len_str = ft_strlen(str);
	if (len_str < len)
		len = len_str;
	if (!(ns = malloc(sizeof(char) * len + 1)))
		return (0);
	if (start >= len_str)
	{
		ns[i] = 0;
		return (ns);
	}
	while (str[start] && i < len)
		ns[i++] = str[start++];
	ns[i] = '\0';
	return (ns);
}
