/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:43:18 by abenheni          #+#    #+#             */
/*   Updated: 2023/02/15 13:43:26 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
	exit(1);
}

void	check_extention(char *s)
{
	int	i;

	i = ft_strlen1(s);
	if (s[i - 1] == 'r' && s[i - 2] == 'e' && s[i - 3] == 'b'
		&& s[i - 4] == '.' && s[i -5])
	{
		i = open(s, O_RDONLY);
		if (i == -1)
		{
			ft_error("error with opening file or not exist\n");
			close(i);
		}
		else
			close(i);
	}
	else
		ft_error("file not ending with .ber\n");
}

static int	check_end_of_map(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (s[i - 1] != '\n')
	{
		if (s[i - 1] != '1')
			return (1);
	}
	else if (s[i - 2] != '1')
		return (1);
	return (0);
}

void	check_arrounded(char *s)
{
	int		i;
	char	*line;

	i = open(s, O_RDONLY);
	line = get_next_line(i);
	if (line == NULL)
		ft_error("file is empty or not found\n");
	while (line)
	{
		if (line[0] != '1' || check_end_of_map(line))
		{
			free(line);
			ft_error("error map not ended with walls\n");
		}
		free(line);
		line = get_next_line(i);
	}
	close(i);
}

int	line_contain(char *s, char c)
{
	int	i;
	int	f;
	int	r;

	i = 0;
	f = 0;
	r = -1;
	while (s[i])
	{
		if (s[i] == c && f == 0)
		{
			f = 1;
			r = 1;
		}
		else if (s[i] == c && f == 1)
		{
			r = 0;
			break ;
		}
		i++;
	}
	if (r == 0)
		ft_error("line contain more then one character\n");
	else if (r == 1)
		return (1);
	return (0);
}
