/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 00:12:59 by wleite            #+#    #+#             */
/*   Updated: 2021/08/11 00:39:02 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

#define BUFFER_SIZE 10

char	*get_next_line(int fd);
size_t	ft_strnlen(const char *s, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
void	*ft_memset(void *dest, int c, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_bzero(void *b, size_t len);
void	*ft_calloc(size_t number, size_t size);
char	*ft_strdup(const char *str);
char	**ft_split(char const *s, char c);
char	*filter_result(char *result, char *buffer, size_t count);
void	*ft_memcpy(void *dst, const void *src, size_t len);
char	*ft_strljoin(char const *s1, char const *s2, size_t	srclen);
void	*ft_memmove(void *dst, const void *src, size_t len);

#endif
