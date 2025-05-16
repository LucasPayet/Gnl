/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:07:46 by lupayet           #+#    #+#             */
/*   Updated: 2025/05/16 15:41:13 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
static char	*ft_strchr(const char *s, int c)
{
	printf("1\n");
	while (*s)
	{
		printf("2\n");
		if (*s++ == (char)c)
		{
			printf("3\n");
			return ((char *)s);
		}
	}
	printf("4\n");
	return (NULL);
}

static char	*get_buffer(int fd, char *stash)
{
	char	*buf;
	int		bytes;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			break ;
		buf[bytes] = 0;
		stash = ft_strjoin(stash, buf);
	}
	free(buf);
	return (stash);
}

static char	*get_line(char *stash)
{
	size_t	i;
	char	*line;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(i + 2);
	ft_strlcpy(line, stash, i + 1);
	return (line);
}

static char	*clean_stash(char *stash)
{
	size_t	i;
	char	*new_stash;
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	new_stash = ft_strdup(&stash[i]);
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = get_buffer(fd, stash);
	if (!stash)
		return (NULL);
	line = get_line(stash);
	printf("%s", line);
	stash = clean_stash(stash);
	return (line);
}
