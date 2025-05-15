/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:07:46 by lupayet           #+#    #+#             */
/*   Updated: 2025/05/15 23:09:10 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

#include <stdio.h>

static char	*ft_linechr(const char *s)
{
	while (*s)
		if (*s++ == '\n')
			return ((char *)(s--));
	return (NULL);
}

static char	*get_buffer(int fd, char *big_buffer)
{
	char	*buf;
	int		bytes;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes = 1;
	while (!)
	return (big_buffer);
}

static char	*get_line(char *buf)
{
}

char	*get_next_line(int fd)
{
	static char	*big_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	big_buffer = get_buffer(fd, big_buffer);
	if (!big_buffer)
		return (NULL);
	line = get_line(big_buffer);
	return (line);
}
