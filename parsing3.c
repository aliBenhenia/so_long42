/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:48:41 by abenheni          #+#    #+#             */
/*   Updated: 2023/02/15 13:48:44 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	line_contain_collect(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i++] == c)
			return (1);
	}
	return (0);
}

int	check_collect(char *s, char c)
{
	int		m;
	int		i;
	char	*line;

	i = open(s, O_RDONLY);
	line = get_next_line(i);
	if (!line)
		ft_error("error with opening\n");
	m = 0;
	while (line)
	{
		if (line_contain_collect(line, c))
		{
			m = 1;
			free(line);
			break ;
		}
		free(line);
		line = get_next_line(i);
	}
	close(i);
	if (m == 1)
		return (1);
	else
		return (0);
}

void	check_characters(char *s)
{
	if (check_one_chracter(s, 'E') == 0 || check_one_chracter(s, 'E') == -1)
		ft_error("you should put one exit only");
	if (!check_collect(s, 'C'))
		ft_error("must at least one collectable");
	if (!check_one_chracter(s, 'P') || check_one_chracter(s, 'P') == -1)
		ft_error("you should put one PLAYER only");
}

void	check_rectangle(char *s)
{
	int		i;
	int		len;
	int		len2;
	char	*line;

	i = open(s, O_RDONLY);
	line = get_next_line(i);
	if (line == NULL)
		ft_error("errour\n");
	len = ft_strlen1(line);
	if (line[len - 1] == '\n')
		len--;
	while (line)
	{
		len2 = ft_strlen1(line) - 1;
		if (line[len2] != '\n')
			len2 = len2 + 1;
		if (len != len2)
			ft_error("not rectangle\n");
		free(line);
		line = get_next_line(i);
	}
	close(i);
}
