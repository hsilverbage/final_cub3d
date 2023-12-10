/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmedkhelladipro <ahmedkhelladipro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:50:51 by ahmedkhella       #+#    #+#             */
/*   Updated: 2023/12/10 15:50:53 by ahmedkhella      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_put_all_pixel(t_img *img, int x, int y, int color)
{
	ft_mlx_pixel_put(img, x, y, color);
	ft_mlx_pixel_put(img, x + 1, y + 1, color);
	ft_mlx_pixel_put(img, x - 1, y - 1, color);
	ft_mlx_pixel_put(img, x + 1, y - 1, color);
	ft_mlx_pixel_put(img, x - 1, y + 1, color);
	ft_mlx_pixel_put(img, x, y + 1, color);
	ft_mlx_pixel_put(img, x, y - 1, color);
	ft_mlx_pixel_put(img, x + 1, y, color);
	ft_mlx_pixel_put(img, x + 1, y, color);
}

static void	ft_print_border(t_game *game, int x, int y, int color)
{
	t_img	*img;
	int		dx;
	int		dy;

	img = &game->mlx->img;
	dx = abs(x - P_OFFSET);
	dy = abs(y - P_OFFSET);
	if (sqrt(dx * dx + dy * dy) < 150)
		ft_put_all_pixel(img, x, y, color);
}

void	ft_print_line(t_game *game, t_point p1, t_point p2, int color)
{
	double	delta_x;
	double	delta_y;
	int		pixels;
	double	pixel_x;
	double	pixel_y;

	delta_x = p2.x - p1.x;
	delta_y = p2.y - p1.y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = p1.x;
	pixel_y = p1.y;
	while (pixels--)
	{
		ft_print_border(game, pixel_x, pixel_y, color);
		pixel_x += delta_x;
		pixel_y += delta_y;
	}
}
