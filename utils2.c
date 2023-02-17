/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:27:00 by abenheni          #+#    #+#             */
/*   Updated: 2023/02/16 20:27:01 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_norm(int m, int i)
{
	close(i);
	if (m == 1)
		return (1);
	else if (m == 0)
		return (0);
	else
		return (-1);
}

void	handle_norm1(char *line)
{
	if (!line)
		ft_error("error with opening\n");
}

int	check_one_chracter(char *s, char c)
{
	int		f;
	int		m;
	int		i;
	char	*line;

	i = open(s, O_RDONLY);
	f = 0;
	line = get_next_line(i);
	handle_norm1(line);
	while (line)
	{
		if (line_contain(line, c) && f == 0)
		{
			f = 1;
			m = 1;
		}
		else if (line_contain(line, c) && f == 1)
		{
			m = 0;
			break ;
		}
		free(line);
		line = get_next_line(i);
	}
	return (handle_norm(m, i));
}
