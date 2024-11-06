/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:02:39 by moritzknoll       #+#    #+#             */
/*   Updated: 2024/11/06 11:47:10 by mknoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*_fill_line_buffer(int fd, char *left_c, char *buffer)
{
	char		*tmp;
	ssize_t		bytes_read;

	bytes_read = 1;
	while (fd > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);

		if (bytes_read < 0)
		{
			free(left_c);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		if (!left_c)
			left_c = ft_strdup("");
		tmp = left_c;
		left_c = ft_strjoin(tmp, buffer);
		free (tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_c);
}

char	*get_next_line(int fd)
{
	
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		return (1);
	}
	char *line;
	line = get_next_line(fd);
	if (line)
	{
		printf("Gelesene zeichen: %s", line);
		free(line);
	}
	else
		printf("Keine zeile gelesen");
	close(fd);
	return(0);
}