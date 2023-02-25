/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:54:58 by abenheni          #+#    #+#             */
/*   Updated: 2022/11/07 15:55:08 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	check_line(char *s)
{
	while (s && *s)
	{
		if (*s == '\n')
			return (0);
		s++;
	}
	return (1);
}

static char	*ft_strcpy(char *dst, const char *src)
{
	while (*src)
	{
		*dst++ = *src++;
	}
	*dst = '\0';
	return (dst);
}

static char	*ft_strcat(char *s1, const char *s2)
{
	s1 = s1 + ft_strlen(s1);
	while (*s2)
	{
		*s1++ = *s2++;
	}
	*s1 = '\0';
	return (s1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		if (!s1)
			return (NULL);
		*s1 = '\0';
	}
	p = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (p == NULL)
		return (NULL);
	ft_strcpy(p, s1);
	ft_strcat(p, s2);
	free(s1);
	return (p);
}
