/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:07:46 by lupayet           #+#    #+#             */
/*   Updated: 2025/05/14 13:10:27 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static int	load_more(int fd, t_lst_line *list)
{
	char	buffer[BUFFER_SIZE];
	size_t	len;

	len = read(fd, &buffer, BUFFER_SIZE);
	ft_lstadd_back(&list, ft_lstnew(ft_strldup(buffer, len)));
	return (len);
}

static char	*get_line(int fd, t_lst_line *list_line)
{
	char	*line;
	size_t	i;
	int		end;

	line = NULL;
	i = 0;
	while (list_line-> content[i] != '\n')
	{
		if (list_line-> content[i] == '\0')
		{
			line = ft_strlinejoin(line, list_line->content, i);
			end = load_more(fd, list_line);
			list_line = ft_lst_rm_item(*list_line);
			if (end == 0)
				break;
			i = 0;
		}
		else
			i++;
	}
	line = ft_strlinejoin(line, list_line->content, i);
	ft_memmove(list_line-> content, &list_line-> content[i], 
			ft_strlen(&list_line-> content[i]));
	return (line);
}

char	*get_next_line(int fd)
{
	static t_lst_line	*list_line;

	load_more(fd, list_line);
	return (get_line);
}
