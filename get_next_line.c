/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:07:46 by lupayet           #+#    #+#             */
/*   Updated: 2025/05/12 16:57:24 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static char	*end_line(int fd, char *buffer, char *line, char *join)
{
	read(fd, buffer, BUFFER_SIZE);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static char	*left_buffer;
	char		*line;
	char		*temp;
	int			i;

	i = 0;
	free(line)
	if (left_buffer)
	{
		while (left_buffer[i] && left_buffer[i] != '\n')
			i++;
		line = strndup(left_buffer, i);
		if (left_buffer[i] = '\n')
		{
			temp = strndup(left_buffer[i + 2]);
			free(left_buffer);
			left_buffer = temp;
			return (line);
		}
	}
	else
	{
		read(fd, &buffer, BUFFER_SIZE);
	}
	if (line)
	{
		leff_buffer = end_line(fd, &buffer, line, NULL);
	}
}
