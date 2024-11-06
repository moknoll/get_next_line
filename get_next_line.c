/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:02:39 by moritzknoll       #+#    #+#             */
/*   Updated: 2024/11/06 12:25:24 by mknoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	len;

	len = 0;
	while (s[len])
	{
		if (s[len] == (char)c)
		{
			return ((char *)&s[len]);
		}
		len++;
	}
	if (s[len] == (char)c)
	{
		return ((char *)&s[len]);
	}
	return (NULL);
}

static char	*_fill_line_buffer(int fd, char *left_c, char *buffer)
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
	static char	*left_c;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc(sizeof (char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0))
	{
		free(left_c);
		free(buffer);
		left_c = NULL;
		buffer = NULL;
		return (NULL);
	}
	line = _fill_line_buffer(fd, left_c, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	//left_c = setline
	return (line);
}

static char	*setline(int fd, char *left_c, char *buffer)
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