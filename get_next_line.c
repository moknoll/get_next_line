/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:03:39 by mknoll            #+#    #+#             */
/*   Updated: 2024/12/06 15:14:23 by mknoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char *get_next_line(int fd)
{
	int		bytes_r;
	char	*buffer;

	buffer = ft_calloc((3 + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_r = read(fd, buffer, 3);
	return(buffer);
}