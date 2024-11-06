/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:02:50 by moritzknoll       #+#    #+#             */
/*   Updated: 2024/11/06 10:44:07 by mknoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

#define BUFFER_SIZE 10

char	*get_next_line(int fd);
int		ft_strlen(const char *str);
void	ft_strcat(char *dest, char *src);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t nitems, size_t size);
char	*ft_strrchr(const char *s, int c);
char	*ft_strdup(char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);


#endif
