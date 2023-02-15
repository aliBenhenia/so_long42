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
// void fill2(char **map1, int width, int height) {
//     int i, j;

//     map1 = (char **) malloc(height * sizeof(char *));
//     for (i = 0; i < height; i++) {
//         map1[i] = (char *) malloc(width * sizeof(char));
//     }

//     for (i = 0; i < height; i++) {
//         for (j = 0; j < width; j++) {
//             map1[i][j] = '0';
//         }
//     }
// }
// int check_path(t_long *map, char **map2, int y, int x,int h, int w)
// {
// 	if (y < 0 || y >= h || x < 0 || x >= w)
// 	{
//         return 0;
//     }
// 	printf("pss\n");
//     if (map2[y][x] == '1')
//         return 0;
//     map2[y][x] = '1';
//      if (map->map[y][x] == 'E')
//         return 1;
//     if (map->map[y][x] == '1')
//         return 0;
//     if (check_path(map, map2, y, x + 1,h,w) == 1)
//         return 1;
//     if (check_path(map, map2, y + 1, x,h,w) == 1)
//         return 1;
//     if (check_path(map, map2, y, x - 1,h,w) == 1)
//         return 1;
//     if (check_path(map, map2, y - 1, x,h,w) == 1)
//         return 1;
//     return 0;
// }
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
}

void	parsing(char *s, t_long *data)
{
	check_extention(s);
	check_arrounded(s);
	check_wall_row(s);
	check_characters(s);
	check_rectangle(s);
	check_correct_char(s);
	count_width(s, data);
	count_height(s, data);
	count_collect(s, data);
	fill_map(s, data);
	// char **map = (char**) malloc(data->height * sizeof(char*));
	// fill2(map,data->width, data->height);
	// // printf("pss\n");
	// check_path(data,map,data->y,data->x, data->height,data->width);
}
