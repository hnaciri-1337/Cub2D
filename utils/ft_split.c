/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 12:27:52 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/06/22 19:24:42 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_alloc(char const *str, char c)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			counter++;
		i++;
	}
	return (counter + 1);
}

static char	*ft_alloc_char(char const *s, char c, int p)
{
	int		i;
	char	*a;

	while (s[p] && s[p] == c)
		p++;
	i = 0;
	while (s[p + i] && s[p + i] != c)
		i++;
	a = malloc (sizeof(char) * i + 1);
	if (!a)
		return (0);
	i = 0;
	while (s[p + i] && s[p + i] != c)
	{
		a[i] = s[p + i];
		i++;
	}
	a[i] = 0;
	return (a);
}

static int	ft_move(char const *s, int p, char c)
{
	while (s[p] && s[p] == c)
		p++;
	while (s[p] && s[p] != c)
		p++;
	while (s[p] && s[p] == c)
		p++;
	return (p);
}

static char	**ft_fill(char const *s, char c, char **table)
{
	int	i;
	int	p;
	int	j;

	j = ft_alloc(s, c);
	i = -1;
	p = 0;
	while (++i < j - 1)
	{	
		table[i] = ft_alloc_char(s, c, p);
		if (!table[i])
		{
			while (i--)
				free(table[i]);
			free (table);
			return (0);
		}
		p = ft_move(s, p, c);
	}
	table[j - 1] = 0;
	return (table);
}

char	**ft_split(char const *str, char c)
{
	char	**array;

	array = malloc (sizeof(char *) * ft_alloc(str, c));
	if (!str || !array)
		return (0);
	array = ft_fill(str, c, array);
	return (array);
}
