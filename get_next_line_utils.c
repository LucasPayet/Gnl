/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:10:37 by lupayet           #+#    #+#             */
/*   Updated: 2025/05/20 14:07:00 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s);
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	dup[len] = 0;
	while (len--)
		dup[len] = s[len];
	return (dup);
}

char	*ft_linejoin(char *s1, char const *s2)
{
	size_t	l_s1;
	size_t	l_s2;
	char	*j;

	l_s1 = ft_strlen(s1);
	l_s2 = ft_strlen(s2);
	j = (char *)malloc(l_s1 + l_s2 + 1);
	if (!j)
		return (free(s1), NULL);
	if (s1)
		ft_strlcpy(j, s1, l_s1 + 1);
	free(s1);
	ft_strlcpy(&j[l_s1], s2, l_s2 + 1);
	return (j);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	c;

	c = 0;
	if (siz == 0)
		return (ft_strlen(src));
	while (c < (siz - 1) && src[c] != '\0')
	{
		dst[c] = src[c];
		c++;
	}
	dst[c] = '\0';
	return (ft_strlen(src));
}
