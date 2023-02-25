/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:16:52 by abenheni          #+#    #+#             */
/*   Updated: 2023/02/15 14:16:55 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_handle1(t_long *vars, t_help *dt)
{
	if (vars->coins > 0 && vars->map[vars->y / 30][(vars->x - 30) / 30] == 'E')
		return ;
	vars->moves++;
	ft_putstr("moves : ");
	ft_putnbr_fd(vars->moves, 1);
	ft_putstr("\n");
	if (vars->coins == 0 && vars->map[vars->y / 30][(vars->x - 30) / 30] == 'E')
		exit(0);
	vars->x -= 30;
	if (vars->map[vars->y / 30][(vars->x) / 30] == 'C')
	{
		vars->coins--;
		vars->map[vars->y / 30][(vars->x) / 30] = '0';
	}
	mlx_clear_window(vars->mlx, vars->wind);
	render_map(vars, dt);
	mlx_put_image_to_window(vars->mlx,
		vars->wind, vars->img[2], vars->x, vars->y);
}

static void	move_handle2(t_long *vars, t_help *dt)
{
	if (vars->coins > 0 && vars->map[vars->y / 30][(vars->x + 30) / 30] == 'E')
		return ;
	vars->moves++;
	ft_putstr("moves : ");
	ft_putnbr_fd(vars->moves, 1);
	ft_putstr("\n");
	if (vars->coins == 0 && vars->map[vars->y / 30][(vars->x + 30) / 30] == 'E')
		exit(0);
	vars->x += 30;
	if (vars->map[vars->y / 30][(vars->x) / 30] == 'C')
	{
		vars->map[vars->y / 30][(vars->x) / 30] = '0';
		vars->coins--;
	}
	mlx_clear_window(vars->mlx, vars->wind);
	render_map(vars, dt);
	mlx_put_image_to_window(vars->mlx,
		vars->wind, vars->img[2], vars->x, vars->y);
}

static void	move_handle3(t_long *vars, t_help *dt)
{
	if (vars->coins > 0
		&& vars->map[(vars->y - 30) / 30][(vars->x) / 30] == 'E')
		return ;
	vars->moves++;
	ft_putstr("moves : ");
	ft_putnbr_fd(vars->moves, 1);
	ft_putstr("\n");
	if (vars->coins == 0
		&& vars->map[(vars->y - 30) / 30][(vars->x) / 30] == 'E')
		exit(0);
	vars->y -= 30;
	if (vars->map[vars->y / 30][(vars->x) / 30] == 'C')
	{
		vars->map[vars->y / 30][(vars->x) / 30] = '0';
		vars->coins--;
	}
	mlx_clear_window(vars->mlx, vars->wind);
	render_map(vars, dt);
	mlx_put_image_to_window(vars->mlx,
		vars->wind, vars->img[2], vars->x, vars->y);
}

static void	move_handle4(t_long *vars, t_help *dt)
{
	if (vars->coins > 0
		&& vars->map[(vars->y + 30) / 30][(vars->x) / 30] == 'E')
		return ;
	vars->moves++;
	ft_putstr("moves : ");
	ft_putnbr_fd(vars->moves, 1);
	ft_putstr("\n");
	if (vars->coins == 0
		&& vars->map[(vars->y + 30) / 30][(vars->x) / 30] == 'E')
		exit(0);
	vars->y += 30;
	if (vars->map[vars->y / 30][(vars->x) / 30] == 'C')
	{
		vars->map[vars->y / 30][(vars->x) / 30] = '0';
		vars->coins--;
	}
	mlx_clear_window(vars->mlx, vars->wind);
	render_map(vars, dt);
	mlx_put_image_to_window(vars->mlx,
		vars->wind, vars->img[2], vars->x, vars->y);
}

int	move(int keycode, t_long *vars, t_help *dt)
{
	if (keycode == 53)
	{
		exit(0);
	}
	if (vars->map[vars->y / 30][(vars->x) / 30] == 'E' && vars->coins == 0)
	{
		ft_free(vars->map);
		exit(0);
	}
	if (keycode == 0 && vars->map[vars->y / 30][(vars->x - 30) / 30] != '1')
		move_handle1(vars, dt);
	if (keycode == 2 && vars->map[vars->y / 30][(vars->x + 30) / 30] != '1')
		move_handle2(vars, dt);
	if (keycode == 13 && vars->map[(vars->y - 30) / 30][(vars->x) / 30] != '1')
		move_handle3(vars, dt);
	if (keycode == 1 && vars->map[(vars->y + 30) / 30][(vars->x) / 30] != '1')
		move_handle4(vars, dt);
	return (0);
}
