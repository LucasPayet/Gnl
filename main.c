/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:40:52 by lupayet           #+#    #+#             */
/*   Updated: 2025/05/16 11:38:07 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../Libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char *av[])
{
	unsigned int	i;
	int				fd;
	char			*str;

	if (ac != 3)
		return (printf("Wrong input !"), 1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		fd = 0;
	i = ft_atoi(av[2]);
	printf("OK\n");
	str = get_next_line(fd);
	printf("%d: %s", i, str);
	i--;
	while (i-- && str)
	{
		str = get_next_line(fd);
		printf("%d: %s", i + 1, str);
	}
	free(str);
	if (fd < 2)
		close(fd);
	return (0);
}
