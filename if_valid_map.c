/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:12:34 by abenheni          #+#    #+#             */
/*   Updated: 2023/02/16 14:12:36 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_if_valid(char **map2, int h, int w)
{
	int	y;
	int	x;

	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			if (map2[y][x] == 'E')
			{
				if (map2[y][x + 1] == 'P')
					return (1);
				if (map2[y][x - 1] == 'P')
					return (1);
				if (map2[y + 1][x] == 'P')
					return (1);
				if (map2[y - 1][x] == 'P')
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
int	check_if_valid2(char **map2, int h, int w)
{
	int	y;
	int	x;

	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			if (map2[y][x] == 'C')
			{
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	check_if_arounded_p(char **map2, int x, int y)
{
	int	flag;

	flag = 0;
	if (map2[y][x + 1] == '0' || map2[y][x + 1] == 'C')
	{
		map2[y][x + 1] = 'P';
		flag = 1;
	}
	if (map2[y][x - 1] == '0' || map2[y][x - 1] == 'C')
	{
		map2[y][x - 1] = 'P';
		flag = 1;
	}
	if (map2[y + 1][x] == '0' || map2[y + 1][x] == 'C')
	{
		map2[y + 1][x] = 'P';
		flag = 1;
	}
	if (map2[y - 1][x] == '0' || map2[y -1][x] == 'C')
	{
		map2[y - 1][x] = 'P';
		flag = 1;
	}
	return (flag);
}

void	if_valid_map(char **map2, int h, int w)
{
	int	y;
	int	x;

	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			if (map2[y][x] == 'P')
			{
				if (check_if_arounded_p(map2, x, y) == 1)
				{
					y = 0;
					x = 0;
				}
			}
			x++;
		}
		y++;
	}
	if (check_if_valid(map2, h, w) == 0)
		ft_error("invalid path for player\n");
	if (check_if_valid2(map2, h, w))
		ft_error("invalid path for collectable\n");
}
