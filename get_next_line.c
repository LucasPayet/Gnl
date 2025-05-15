/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:07:46 by lupayet           #+#    #+#             */
/*   Updated: 2025/05/15 15:36:22 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

#include <stdio.h>
static int	load_more(int fd, t_lst_line **list)
{
	char	buffer[BUFFER_SIZE];
	size_t	len;

	len = read(fd, &buffer, BUFFER_SIZE);
	ft_lstadd_line(list, ft_lst_line(ft_strldup(buffer, len)));
	return (len);
}

static char	*get_line(int fd, t_lst_line *list_line, char *buffer)
{
	char	*line;
	t_lst_line	*lst;
	size_t	i;
	int		end;

	lst = list_line;
	if (!lst)
	{
		end = load_more(fd, &lst);
		if (end == 0)
			return (ft_strldup("", 0));
	}

	line = NULL;
	i = 0;
	while (lst-> content[i] != '\n')
	{
		if (lst-> content[i] == '\0')
		{
			line = ft_strlinejoin(line, lst->content, i);
			end = load_more(fd, &lst);
			lst = lst-> next;
			if (end == 0)
				break;
			i = 0;
		}
		else
			i++;
	}
	line = ft_strlinejoin(line, lst->content, i + 1);
	ft_strlcpy(buffer, &lst-> content[i] + 1, 
			ft_strlen(&lst-> content[i]));
	ft_rmlist(list_line);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	left_buff[BUFFER_SIZE];
	char		*line;
	t_lst_line	*list_line;

	if (left_buff[0])
		list_line = ft_lst_line(ft_strldup(left_buff, ft_strlen(left_buff)));
	else
		list_line = NULL;
	line = get_line(fd, list_line, left_buff);
	return (line);
}
