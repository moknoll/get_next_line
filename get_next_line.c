/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:59:34 by moritzknoll       #+#    #+#             */
/*   Updated: 2024/11/12 09:58:48 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char	*ft_strchr(char *s, int c);
char	*read_bytes(int fd, char  *new_line, char	*buffer);

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = (char *)malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free(line);
		return (NULL);
	}
	line = read_bytes(fd, line, buffer);
	free(buffer);
	return (line);
}

char	*read_bytes(int fd, char	*new_line, char *buffer)
{
	char	*temp;
	ssize_t	bytes_r;

	bytes_r = read(fd, buffer, BUFFER_SIZE);
	while (bytes_r > 0)
	{
		buffer[bytes_r] = '\0';
		temp = ft_strjoin(new_line, buffer);
		free(new_line);
		new_line = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
		bytes_r = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_r == -1 || (bytes_r == 0 && new_line[0] == '\0'))
	{
		free(new_line);
		new_line = NULL;
	}
	return (new_line);
}

char	*ft_strchr(char *s, int c)
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

int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *result = get_next_line(fd);

	if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

	if (result)
	{
		printf("%s", result);
		free (result);
	}
	else
		printf("Failed");
	close(fd);
	return (0);
}
