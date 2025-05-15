/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:05:55 by lupayet           #+#    #+#             */
/*   Updated: 2025/05/15 22:34:58 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>
# include <stdlib.h>

void    ft_bzero(void *s, size_t n);
char		*get_next_line(int fd);
size_t  	ft_strlen(const char *s);
char    	*ft_strldup(const char *s, size_t len);
char    	*ft_strlinejoin(char const *s1, char const *s2, size_t len);
size_t  	ft_strlcpy(char *dst, const char *src, size_t siz);
void    	*ft_memmove(void *dest, const void *src, size_t n);

# endif
