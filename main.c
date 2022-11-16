/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:47:31 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/11/16 14:13:00 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

char	**get_file(t_file *data, int fd, char *file_name)
{
	char	*line;
	int		i;
	char	**map;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free (line);
		line = get_next_line(fd);
	}
	close(fd);
	fd = open (file_name, O_RDONLY);
	map = malloc (sizeof(char *) * (i + 1));
	line = get_next_line(fd);
	i = -1;
	while (line)
	{
		map[++i] = line;
		line = get_next_line(fd);
	}
	data->count = i;
	map[++i] = 0;
	close(fd);
	return (map);
}

void dda(t_file *data,int X0, int Y0, int X1, int Y1)
{
    int dx = X1 - X0;
    int dy = Y1 - Y0;
 
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
 
    float X = X0;
    float Y = Y0;
    while (1)
	{
		mlx_pixel_put(data->mlx, data->mlx_win, (int)round(X), (int)round(Y), 150);
        X += Xinc;
        Y += Yinc;
		if ((int)(Y / SCAL) < 0 || (int)(Y / SCAL) > data->count || (int)(X / SCAL) < 0 || (int)(X / SCAL) > ft_strlen(data->the_map[(int)(Y / 64)]))
			break ;
		if (data->the_map[(int)(Y / 64)][(int)(X / 64)] != '0')
			break;
    }
}

void	draw(t_file *data)
{
	int i, j;
	i = -1;
	while (data->the_map[++i])
	{
		j = -1;
		while (data->the_map[i][++j])
		{
			if (data->the_map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgs[0].img, j * SCAL, i * SCAL);
			else
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgs[1].img, j * SCAL, i * SCAL);
		}
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgs[2].img, data->x * SCAL, data->y * SCAL);
	i = -65;
	while (i <= 65)
	{
		dda(data, (int)(data->x * SCAL), (int)(data->y * SCAL), (int)((data->x * SCAL) + (200 * cos(((data->a + i) * PI) / 180))), (int)((data->y * SCAL) + (200 * sin(((data->a + i) * PI) / 180))));
		i++;
	}
}

void	draw_window(t_file *data)
{
	int	i = -1, j;
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "CUB2D");
	while (data->the_map[++i])
	{
		j = -1;
		while (data->the_map[i][++j])
			if (ft_strchr("WSEN", data->the_map[i][j]))
			{
				if (data->the_map[i][j] == 'E')
					data->a = 0;
				else if (data->the_map[i][j] == 'N')
					data->a = 270;
				else if (data->the_map[i][j] == 'W')
					data->a = 180;
				else if (data->the_map[i][j] == 'S')
					data->a = 90;
				data->x = j + 0.4;
				data->y = i + 0.4;
				data->the_map[i][j] = '0';
				break ;
			}
	}
	data->imgs[0].img = mlx_xpm_file_to_image(data->mlx, "pics/redbrick_1.xpm", &data->imgs[0].width, &data->imgs[0].height);
	data->imgs[0].addr = mlx_get_data_addr(data->imgs[0].img, &data->imgs[0].bits_per_pixel, &data->imgs[0].line_length, &data->imgs[0].endian);
	data->imgs[1].img = mlx_xpm_file_to_image(data->mlx, "pics/black.xpm", &data->imgs[1].width, &data->imgs[1].height);
	data->imgs[1].addr = mlx_get_data_addr(data->imgs[1].img, &data->imgs[1].bits_per_pixel, &data->imgs[1].line_length, &data->imgs[1].endian);
	data->imgs[2].img = mlx_xpm_file_to_image(data->mlx, "pics/player.xpm", &data->imgs[2].width, &data->imgs[2].height);
	data->imgs[2].addr = mlx_get_data_addr(data->imgs[2].img, &data->imgs[2].bits_per_pixel, &data->imgs[2].line_length, &data->imgs[2].endian);
	draw(data);
}

int	move(int key, void *_f)
{
	t_file *data;

	data = _f;
	if (key == 123)
		data->a -= 5;
	else if (key == 124)
		data->a += 5;
	else if (key == 126)
	{
		float	x = (((data->x * SCAL) + (5 * cos(((data->a) * PI) / 180))) / SCAL);
		float	y = (((data->y * SCAL) + (5 * sin(((data->a) * PI) / 180))) / SCAL);
		if (data->the_map[(int)y][(int)x] == '0')
		{
			data->x = x;
			data->y = y;
		}
	}
	else if (key == 125)
	{
		float	x = (((data->x * SCAL) - (5 * cos(((data->a) * PI) / 180))) / SCAL);
		float	y = (((data->y * SCAL) - (5 * sin(((data->a) * PI) / 180))) / SCAL);
		if (data->the_map[(int)y][(int)x] == '0')
		{
			data->x = x;
			data->y = y;
		}
	}
	data->a %= 360;
	draw(data);
	return (0);
}

int	main(int ac, char **av)
{
	char	*exe;
	int		fd;
	t_file	data;

	if (ac != 2)
		return (0);
	exe = ft_substr(av[1], ft_strlen(av[1]) - 4, 4);
	if (ft_strncmp(exe, ".cub", 4))
		return (0);
	free (exe);
	fd = open (av[1], O_RDONLY);
	if (fd == -1)
		return (0);
	data.the_map = get_file(&data, fd, av[1]);
	draw_window(&data);
	mlx_key_hook(data.mlx_win, move, &data);
	mlx_loop(data.mlx);
}
