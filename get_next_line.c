/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 00:15:03 by wleite            #+#    #+#             */
/*   Updated: 2021/08/11 00:38:53 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	static char		*buffer_backup;
	char			*result;
	static size_t	count;

	buffer_backup = ft_calloc(count + 1, sizeof(char));
	ft_memcpy(buffer_backup, buffer, count);
	result = ft_strdup(buffer_backup);

	// printf("\nCOUNT: %zu", count);
	// printf("BUFFER: %s\n", buffer);
	while(1)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count <= 0)
		{
			result = NULL;
			break ;
		}
		free(buffer_backup);
		buffer_backup = ft_calloc(count + 1, sizeof(char));
		ft_memcpy(buffer_backup, buffer, count);
		result = ft_strljoin(result, buffer_backup, count);
		if (ft_strchr(result, '\n'))
		{
			result = filter_result(result, buffer_backup, count);
			break ;
		}
	}
	free(buffer_backup);
	return (result);
}

// char	*get_next_line(int fd)
// {
// 	static char	buffer[BUFFER_SIZE];
// 	char		*buffer_backup;
// 	char		*result;
// 	size_t		count;

// 	buffer_backup = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
// 	ft_memcpy(buffer_backup, buffer, BUFFER_SIZE);
// 	result = ft_strdup(buffer_backup);

// 	ft_bzero(buffer, BUFFER_SIZE);

// 	// printf("\nRESULT: %s", result);
// 	// printf("BUFFER: %s\n", buffer);
// 	while(1)
// 	{
// 		count = read(fd, buffer, BUFFER_SIZE);
// 		if (count <= 0)
// 		{
// 			result = NULL;
// 			break ;
// 		}
// 		ft_memcpy(buffer_backup, buffer, BUFFER_SIZE);
// 		buffer_backup[BUFFER_SIZE] = '\0';
// 		result = ft_strjoin(result, buffer_backup);
// 		if (ft_strchr(result, '\n'))
// 		{
// 			result = filter_result(result, buffer);
// 			break ;
// 		}
// 	}
// 	free (buffer_backup);
// 	return (result);
// }
