/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:10:37 by lupayet           #+#    #+#             */
/*   Updated: 2025/05/15 15:27:34 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_lst_line	*ft_lst_line(void *content)
{
	t_lst_line	*lst;

	lst = (t_lst_line *)malloc(sizeof(t_lst_line));
	if (!lst)
		return (NULL);
	lst -> content = content;
	lst -> next = NULL;
	return (lst);
}

t_lst_line	*ft_lstlast_line(t_lst_line *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

void	ft_lstadd_line(t_lst_line **lst, t_lst_line *new)
{
	t_lst_line	*last;

	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast_line(*lst);
		last-> next = new;
	}
}

t_lst_line	*ft_lst_rm_item(t_lst_line *lst)
{
	t_lst_line	*next;
	free(lst-> content);
	next = lst-> next;
	free(lst);
	return (next);
}

#include <stdio.h>
void	ft_rmlist(t_lst_line *lst)
{
	t_lst_line	*temp;

	while (lst)
	{
		//printf("%s\n", lst-> content);
		temp = lst-> next;
		ft_bzero(lst-> content, ft_strlen(lst->content));
		free(lst-> content);
		free(lst);
		lst = temp;
	}
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*b;

	b = (unsigned char *)s;
	while (n--)
	{
		*b++ = 0;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strldup(const char *s, size_t len)
{
	char	*dup;

	if (!len)
		len = ft_strlen(s);
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	dup[len] = 0;
	while (len--)
		dup[len] = s[len];
	return (dup);
}

#include <stdio.h>
char	*ft_strlinejoin(char const *s1, char const *s2, size_t len)
{
	size_t	l_s1;
	char	*j;

	if (!s1)
		s1 = ft_strldup("", 0);
	l_s1 = ft_strlen(s1);
	j = (char *)malloc(l_s1 + len + 1);
	if (!j)
		return (NULL);
	ft_strlcpy(j, s1, l_s1 + 1);
//	printf("Join => %s\n", j);
	free((char *)s1);
	ft_strlcpy(&j[l_s1], s2, len + 1);
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

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!src && !dest)
		return (dest);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d < s)
		while (n--)
			*d++ = *s++;
	else
		while (n--)
			*(d + n) = *(s + n);
	return (dest);
}
