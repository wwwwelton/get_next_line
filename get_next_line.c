/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 00:15:03 by wleite            #+#    #+#             */
/*   Updated: 2021/08/12 23:52:21 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char **buffer_backup)
{
	int		i;
	char	*result;

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
	result = ft_substr(*buffer_backup, 0, i);
	*buffer_backup = ft_substr(*buffer_backup, i,
			ft_strlen(result) - ft_strlen(*buffer_backup));
	return (result);
}

char	*get_line(int fd, char **buffer, char **buffer_backup)
{
	int	count;

	if (ft_strchr(*buffer_backup, '\n'))
		return (extract_line(buffer_backup));
	count = 1;
	while (!ft_strchr(*buffer_backup, '\n') && count > 0)
	{
		count = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[BUFFER_SIZE] = '\0';
		if (count <= 0)
			return (NULL);
		*buffer_backup = ft_strjoin(*buffer_backup, *buffer);
	}
	if (ft_strchr(*buffer_backup, '\n'))
		return (extract_line(buffer_backup));
	return (ft_strdup(""));
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
