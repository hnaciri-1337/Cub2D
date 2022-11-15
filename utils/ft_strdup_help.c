/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:28:39 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/06/09 17:12:43 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*ft_strdup_help(char *s)
{
	int	i;

	i = -1;
	if (!s)
		return (0);
	while (ft_strchr(" \t", s[i]))
		i++;
	s[ft_strlen(s) - 1] = 0;
	return (ft_strdup(s + i));
}
