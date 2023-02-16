/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:09:43 by abenheni          #+#    #+#             */
/*   Updated: 2023/02/15 14:09:45 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#ifndef SO_LONG_H
# define  SO_LONG_H
# include <stdlib.h>
# include <mlx.h>
# include <unistd.h>
# include<fcntl.h>
# include<stdio.h>
# include<string.h>
# include "./get_next_line42/get_next_line.h"

typedef struct t_long
{
	void	*mlx;
	void	*wind;
	void	**pic;
	void	**img;
	void	**paths;
	char	**map;
	void	*wall;
	void	*player;
	int		width;
	int		height;
	int		x;
	int		y;
	int		coins;
	int		moves;
}t_long;

typedef struct t_help{
	int	fx;
	int	fy;
}t_help;

void	ft_error(char *s);
void	parsing(char *s, t_long *data);
void	check_extention(char *s);
void	check_arrounded(char *s);
int		line_contain(char *s, char c);
void	check_characters(char *s);
void	check_rectangle(char *s);
void	check_correct_char(char *s);
void	count_width(char *s, t_long *data);
void	render_map(t_long *data, t_help *dt);
int		move(int keycode, t_long *vars, t_help *dt);
void	check_wall_row(char *s);
void	ft_free(char *p[]);
void	ft_putstr(char *s);
void	ft_putnbr_fd(int n, int fd);
void if_valid_map(char **map2, int h, int w);
char	**fill_map2(char **map, int size, char *s);
#endif