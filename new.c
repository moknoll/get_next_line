/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:06:34 by moritzknoll       #+#    #+#             */
/*   Updated: 2024/11/08 14:10:06 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char *remainder = NULL;
	char *line = NULL;
	char *buffer;
	ssize_t bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = init_buffer();
	if (!buffer)
		return (NULL);
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		line = join_buffers(line, buffer);
		if (has_newline(buffer))
			break;
	}
	if (bytes_read == 0 && line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	free(buffer);
	return (line);
}

static char *init_buffer(void)
{
	char *buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	return (buffer);
}

static char *read_line(int fd, char *buffer)
{
	ssize_t bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	return (buffer);
}

static char *join_buffers(char *line, char *buffer)
{
	char *new_line = ft_strjoin(line, buffer);
	free(line);
	return (new_line);
}

static int has_newline(char *buffer)
{
	return (ft_strchr(buffer, '\n') != NULL);
}
