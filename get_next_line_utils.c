/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 00:15:00 by wleite            #+#    #+#             */
/*   Updated: 2021/08/11 00:38:54 by wleite           ###   ########.fr       */
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

size_t	ft_strnlen(const char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (s[i] && i < n)
		i++;
	return (i);
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
		len = ft_strnlen(src, dstsize - 1);
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
	dstlen = ft_strnlen(dst, dstsize);
	if (dstlen == dstsize)
		return (dstlen + srclen);
	ft_strlcpy(&dst[dstlen], src, dstsize - dstlen);
	return (dstlen + srclen);
}

void	*ft_memset(void *dest, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	ch;

	ptr = (unsigned char *)dest;
	ch = (unsigned char)c;
	while (len--)
		*ptr++ = ch;
	return (dest);
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
	//unalloc s1
	free((void *)s1);
	return (str);
}

char	*ft_strljoin(char const *s1, char const *s2, size_t	srclen)
{
	char	*str;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + srclen + 1;
	str = (char *)malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, size);
	//unalloc s1
	free((void *)s1);
	return (str);
}

void	ft_bzero(void *b, size_t len)
{
	ft_memset(b, 0, len);
}

void	*ft_calloc(size_t number, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(number * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, number * size);
	return (ptr);
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

char	*filter_result(char *result, char *buffer, size_t count)
{
	char	*str;
	size_t	result_len;
	size_t	len;
	size_t	i;

	len = 0;
	result_len = ft_strlen(result);
	while(result[len] != '\0' && result[len] != '\n' && len < result_len)
		len++;
	str = (char *)malloc(sizeof(char) * len + 2);
	if (!str)
		return (NULL);
	len = 0;
	while(result[len] != '\0' && result[len] != '\n' && len < result_len)
	{
		str[len] = result[len];
		len++;
	}
	str[len] = '\n';
	len++;
	str[len] = '\0';
	len++;
	i = 0;
	while (str[len] && i < count)
	{
		buffer[i] = str[len];
		i++;
		len++;
	}
	free(result);
	return (str);
}
