#include "cub3D.h"

static unsigned int	ft_get_color(t_img *data, int x, int y)
{
	int		color;
	char	*dst;

	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	dst = data->addr + (y % IMG_SIZE * data->line_length + x % IMG_SIZE * \
		(data->bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

void	ft_draw_line(t_game *game, t_img *img, int x)
{
	int		y;
	int		color;

	y = 0;
	while (y <= HEIGHT)
	{
		if (y < game->ray->draw_start)
			ft_mlx_pixel_put(img, x, y, game->ceiling_color);
		else if (y > game->ray->draw_end)
			ft_mlx_pixel_put(img, x, y, game->floor_color);
		else
		{
			game->ray->tex.y = (int)game->ray->tex_pos & 255;
			game->ray->tex_pos += game->ray->step;
			color = ft_get_color(&game->texture[game->ray->side], \
				game->ray->tex.x, game->ray->tex.y);
			ft_mlx_pixel_put(img, x, y, color);
		}
		y++;
	}
}
