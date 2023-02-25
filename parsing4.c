/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:56:14 by abenheni          #+#    #+#             */
/*   Updated: 2023/02/15 13:56:18 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	containe_other(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '0' && s[i] != '1' && s[i] != 'C'
			&& s[i] != 'E' && s[i] != 'P' && s[i] != '\n' && s[i] != '\0')
			return (1);
		i++;
	}
	return (0);
}

void	check_correct_char(char *s)
{
	int		i;
	char	*line;

	i = open(s, O_RDONLY);
	line = get_next_line(i);
	if (line == NULL)
		ft_error("error\n");
	while (line)
	{
		if (containe_other(line))
			ft_error("other character\n");
		free(line);
		line = get_next_line(i);
	}
	close(i);
}

void	count_width(char *s, t_long *data)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(s, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
	{
		ft_error("error\n");
	}
	i = 0;
	while (line[i] && line[i++] != '\n')
		data->width++;
	free(line);
	close(fd);
}
