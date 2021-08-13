/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 00:15:00 by wleite            #+#    #+#             */
/*   Updated: 2021/08/12 22:38:53 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static size_t	strnlen(const char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (s[i] && i < n)
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	srclen;

	if (!s)
		return (NULL);
	srclen = ft_strlen(s);
	if (srclen > start)
		len = strnlen(&s[start], len);
	else
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s[start], len + 1);
	return (str);
}

char	*ft_strdup(const char *str)
{
	char	*s;
	size_t	len;

	len = ft_strlen(str) + 1;
	s = (char *)malloc(sizeof(char) * len);
	if (s == NULL)
		return (NULL);
	ft_strlcpy(s, str, len);
	return (s);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	ch;

	str = (char *)s;
	ch = (char)c;
	while (*str)
	{
		if (*str == ch)
			return (str);
		str++;
	}
	if (*str == ch)
		return (str);
	return (NULL);
}

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	if ((!dst && !src) || !len)
		return (dst);
	ptr_dest = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	while (len--)
		*ptr_dest++ = *ptr_src++;
	return (dst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	len;

	if (!dst || !src)
		return (0);
	srclen = ft_strlen(src);
	if (dstsize)
	{
		len = strnlen(src, dstsize - 1);
		ft_memcpy(dst, src, len);
		dst[len] = '\0';
	}
	return (srclen);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;

	srclen = ft_strlen(src);
	dstlen = strnlen(dst, dstsize);
	if (dstlen == dstsize)
		return (dstlen + srclen);
	ft_strlcpy(&dst[dstlen], src, dstsize - dstlen);
	return (dstlen + srclen);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, size);
	return (str);
}

static void	*memrcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	if ((!dst && !src) || !len)
		return (dst);
	ptr_dest = (unsigned char *)dst + len - 1;
	ptr_src = (unsigned char *)src + len - 1;
	while (len--)
		*ptr_dest-- = *ptr_src--;
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if ((!dst && !src) || !len)
		return (dst);
	if (dst <= src)
		return (ft_memcpy(dst, src, len));
	else
		return (memrcpy(dst, src, len));
}
