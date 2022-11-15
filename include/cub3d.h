/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:05:34 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/11/15 17:40:54 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <math.h>

# define NO "NO "
# define SO "SO "
# define WE "WE "
# define EA "EA "
# define C "C "
# define F "F "
# define SCAL 64
# define HEIGHT 1080
# define WIDTH 1920
# define PI 3.141592653589793238

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_file
{
	char	**the_map;
	void	*mlx;
	void	*mlx_win;
	float	x;
	float	y;
	int		a;
	int		count;
	t_img	imgs[3];
}	t_file;

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *src);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char*s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
#endif
