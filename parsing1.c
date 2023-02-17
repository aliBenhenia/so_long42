/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:24:03 by abenheni          #+#    #+#             */
/*   Updated: 2023/02/14 15:24:06 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	check_first_line(t_long *data)
{
	int	j;

	j = 0;
	while (data->map[0][j] && data->map[0][j] != '\n')
	{
		if (data->map[0][j] != '1')
		{
			ft_error("should all walls \n");
		}
		j++;
	}
}
void	check_last_line(t_long *data)
{
	int	j;

	j = 0;
	while (data->map[data->height - 1][j])
	{
		if (data->map[data->height - 1][j] != '1' && data->map[data->height - 1][j] != '\n')
		{
			ft_error("should all walls in last \n");
		}
		j++;
	}
}
void	count_height(char *s, t_long *data)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(s, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		data->height++;
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	free(line);
	close(fd);
}

void	fill_map(char *s, t_long *data)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(s, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	data->map = (char **) malloc(data->height * sizeof(char *));
	while (line)
	{
		data->map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	close(i);
}

int	count_line_collect(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s == NULL)
	{
		return (0);
	}
	while (s[i])
	{
		if (s[i] == 'C')
			j++;
		i++;
	}
	return (j);
}

void	count_collect(char *s, t_long *data)
{
	int		fd;
	char	*line;

	fd = open(s, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		data->coins += count_line_collect(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	parsing(char *s, t_long *data)
{
	char	**map2;

	map2 = NULL;
	check_extention(s);
	check_arrounded(s);
	check_characters(s);
	check_rectangle(s);
	check_correct_char(s);
	count_width(s, data);
	count_height(s, data);
	count_collect(s, data);
	fill_map(s, data);
	check_first_line(data);
	check_last_line(data);
	fill_map2(s, data);
	if_valid_map(data->map2, data->height, data->width);
}
