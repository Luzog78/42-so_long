/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 06:59:39 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/22 13:30:41 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define BUFFER_SIZE 42

static char	*ft_get_final_line(char **buffer);
static int	ft_read_line(int fd, char **global_buffer, char **buff_line);
char		*gnl_ft_realloc_join(char *s1, char *s2);
char		*gnl_ft_realloc_skip(char *str, size_t n);

char	*get_next_line(int fd)
{
	static char	*global_buffer;
	char		*buff_line;
	size_t		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff_line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff_line)
		return (NULL);
	i = 0;
	while (i <= BUFFER_SIZE)
	{
		buff_line[i] = '\0';
		i++;
	}
	if (!ft_read_line(fd, &global_buffer, &buff_line) || !global_buffer)
		return (NULL);
	return (ft_get_final_line(&global_buffer));
}

static int	ft_read_line(int fd, char **global_buffer, char **buff_line)
{
	int	result;

	result = 1;
	while (!ft_str_contains(*global_buffer, '\n'))
	{
		result = read(fd, *buff_line, BUFFER_SIZE);
		if (result < 0)
		{
			free(*buff_line);
			if (*global_buffer)
				free(*global_buffer);
			return (0);
		}
		if (result == 0)
			break ;
		(*buff_line)[result] = '\0';
		*global_buffer = gnl_ft_realloc_join(*global_buffer, *buff_line);
	}
	free(*buff_line);
	return (1);
}

static char	*ft_get_final_line(char **buffer)
{
	char	*final_line;
	size_t	i;
	size_t	j;

	i = 0;
	while ((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	if ((*buffer)[i] == '\n')
		i++;
	final_line = malloc(sizeof(char) * (i + 1));
	if (!final_line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		final_line[j] = (*buffer)[j];
		j++;
	}
	final_line[j] = '\0';
	*buffer = gnl_ft_realloc_skip(*buffer, i);
	return (final_line);
}
