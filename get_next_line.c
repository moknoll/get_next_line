/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:02:39 by moritzknoll       #+#    #+#             */
/*   Updated: 2024/11/06 09:41:16 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *_fill_line_buffer(int fd, char *left_c, char *buffer)
{
	char *line = NULL;
	ssize_t		bytes_read;

	buffer = BUFFER_SIZE + 1;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (buffer != '\n' || buffer != '\0')
		*left_c++ = bytes_read++;

}

char	*get_next_line(int fd)
{
	char	*buffer;
	char *line = NULL;
	ssize_t		bytes_read;

	buffer = BUFFER_SIZE + 1;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
		buffer[bytes_read] = '\0';
	if (bytes_read < 0)
		return (NULL);
	if (buffer == '\n')

}
