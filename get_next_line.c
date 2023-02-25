/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:51:11 by abenheni          #+#    #+#             */
/*   Updated: 2022/11/07 15:51:15 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*ft_rest(char *saved)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (!saved[i])
	{
		free(saved);
		return (NULL);
	}
	rest = (char *)malloc(ft_strlen(saved) - i + 1);
	if (!rest)
		return (free(saved), NULL);
	i++;
	j = 0;
	while (saved[i])
		rest[j++] = saved[i++];
	free(saved);
	rest[j] = '\0';
	return (rest);
}

static char	*split_line(char *saved)
{
	int		i;
	char	*line;

	if (!*saved || !saved)
		return (NULL);
	i = 0;
	while (saved[i] && saved[i] != '\n')
	{
		i++;
	}
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (saved[i] && saved[i] != '\n')
	{
		line[i] = saved[i];
		i++;
	}
	if (saved[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	int			rd;
	char		*line;
	static char	*saved;
	char		*b;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	b = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!b)
		return (NULL);
	rd = 1;
	while (check_line(saved) && rd)
	{
		rd = read(fd, b, BUFFER_SIZE);
		if (rd == -1)
			return (free(b), NULL);
		b[rd] = '\0';
		saved = ft_strjoin(saved, b);
	}
	free(b);
	line = split_line(saved);
	saved = ft_rest(saved);
	return (line);
}
