/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 00:15:03 by wleite            #+#    #+#             */
/*   Updated: 2021/08/14 00:06:20 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char **buffer_backup)
{
	int		i;
	char	*result;
	char	*temp_free;

	i = 0;
	while ((*buffer_backup)[i] != '\0')
	{
		if ((*buffer_backup)[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	temp_free = *buffer_backup;
	result = ft_substr(temp_free, 0, i);
	*buffer_backup = ft_substr(*buffer_backup, i,
			ft_strlen(result) - ft_strlen(*buffer_backup));
	free(temp_free);
	return (result);
}

// char	*get_line(int fd, char **buffer, char **buffer_backup)
// {
// 	int		count;
// 	char	*temp_free;

// 	if (ft_strchr(*buffer_backup, '\n'))
// 		return (extract_line(buffer_backup));

// 	count = BUFFER_SIZE;
// 	while (!ft_strchr(*buffer, '\n') && count == BUFFER_SIZE)
// 	{
// 		count = read(fd, *buffer, BUFFER_SIZE);
// 		(*buffer)[count] = '\0';
// 		temp_free = *buffer_backup;
// 		*buffer_backup = ft_strjoin(temp_free, *buffer);
// 		free(temp_free);
// 	}

// 	if (ft_strchr(*buffer_backup, '\n'))
// 		return (extract_line(buffer_backup));

// 	if (!ft_strchr(*buffer_backup, '\n') && (*buffer_backup)[0])
// 		return (ft_strdup(*buffer_backup));

// 	return (NULL);
// }

char	*get_line(int fd, char **buffer, char **buffer_backup)
{
	int		count;
	char	*temp_free;
	char	*temp_free2;

	if (ft_strchr(*buffer_backup, '\n'))
		return (extract_line(buffer_backup));

	count = 1;
	while (!ft_strchr(*buffer_backup, '\n') && count > 0)
	{
		count = read(fd, *buffer, BUFFER_SIZE);
		if (count < 0)
		{
			free(*buffer_backup);
			*buffer_backup = NULL;
			return (NULL);
		}
		(*buffer)[count] = '\0';
		temp_free = *buffer_backup;
		*buffer_backup = ft_strjoin(temp_free, *buffer);
		free(temp_free);
	}

	if (ft_strchr(*buffer_backup, '\n'))
		return (extract_line(buffer_backup));

	if (!ft_strchr(*buffer_backup, '\n') && (*buffer_backup)[0])
	{
		temp_free2 = ft_strdup(*buffer_backup);
		free(*buffer_backup);
		*buffer_backup = NULL;
		return (temp_free2);
	}

	return (NULL);
}

char	*get_next_line(int fd)
{
	static char		*buffer_backup;
	char			*buffer;
	char			*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!buffer_backup)
		buffer_backup = ft_strdup("");
	result = get_line(fd, &buffer, &buffer_backup);
	free(buffer);
	buffer = NULL;
	return (result);
}
