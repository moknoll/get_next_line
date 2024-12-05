/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:06:10 by moritzknoll       #+#    #+#             */
/*   Updated: 2024/12/05 08:50:16 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c);
static char *seperate_line(char *line_buffer);
static char	*fill_line(int fd, char *stat_char, char *buffer);

char *get_next_line(int fd)
{
	static char	*stat_char;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFERSIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFERSIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stat_char);
		free(buffer);
		stat_char = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = fill_line(fd, stat_char, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	stat_char = seperate_line(line);
	return (line);
}

static char *seperate_line(char *line_buffer)
{
	char *stat_char;
	int i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == 0 || line_buffer[1] == 0)
		return (NULL);
	stat_char = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (*stat_char == 0)
	{
		free(stat_char);
		stat_char = NULL;
	}
	line_buffer[i + 1] = 0;
	return (stat_char);
}

static char	*fill_line(int fd, char *stat_char, char *buffer)
{
	ssize_t bytesread;
	char *temp;

	bytesread = 1;
	while(bytesread > 0)
	{
		bytesread = read(fd, buffer, BUFFERSIZE);
		if (bytesread == -1)
		{
			free(stat_char);
			return (NULL);
		}
		else if (bytesread == 0)
			break ;
		buffer[bytesread] = 0;
		if (!stat_char)
			stat_char = ft_strdup("");
		temp = stat_char;
		stat_char = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return(stat_char);
}


char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (s[i] == (char)c)
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}
