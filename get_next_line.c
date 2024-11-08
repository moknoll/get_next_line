/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:59:34 by moritzknoll       #+#    #+#             */
/*   Updated: 2024/11/08 12:38:10 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char	*ft_strchr(char *s, int c);

char	*get_next_line(int fd)
{
	char	*buffer;
	ssize_t	bytes_read;
	char	*line;
	char	*temp;

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

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(line, buffer);
		free(line);
		line = temp;
		if (ft_strchr(buffer, '\n'))
			break;
	}
	if (bytes_read == -1 || (bytes_read == 0 && line[0] == '\0'))
	{
		free(line);
		line = NULL;
	}
	free(buffer);
	return (line);
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
		printf("\n%s", result);
		free (result);
	}
	else
		printf("Failed");
	close(fd);
	return (0);
}
