/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:15:04 by moritzknoll       #+#    #+#             */
/*   Updated: 2024/11/06 10:59:51 by mknoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	while (dest[i])
	{
		i++;
	}
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*new_string;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_string = (char *)malloc(len_s1 + len_s2 + 1);
	if (!new_string)
		return (NULL);
	new_string[0] = '\0';
	ft_strcat(new_string, (char *)s1);
	ft_strcat(new_string, (char *)s2);
	return (new_string);
}

static void	*ft_calloc(size_t nitems, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = malloc(nitems * size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (i < nitems * size)
		ptr[i++] = 0;
	return (ptr);
}

static char	*ft_strdup(char *s)
{
	int		i;
	int		len;
	char	*copy;

	i = 0;
	len = 0;
	while (s[len])
	{
		len++;
	}
	copy = (char *) malloc(len + 1);
	if (copy == NULL)
		return (NULL);
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub_string;

	i = 0;
	if (!s)
	{
		return (NULL);
	}
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
	{
		len = ft_strlen(s) - start;
	}
	sub_string = ft_calloc(len + 1, sizeof(char));
	if (!sub_string)
		return (NULL);
	while (i < len)
	{
		sub_string[i] = s[start + i];
		i++;
	}
	return (sub_string);
}

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
