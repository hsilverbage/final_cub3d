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

int	apply_fog(int original_color, double distance)
{
	double	fog_intensity;
	int		fog_color;
	int		r, g, b;
	double	fog_density;

	fog_color = 0x808B96;
	fog_density = 0.5;
	fog_intensity = distance * fog_density;
	fog_intensity = fog_intensity > 1.0 ? 1.0 : fog_intensity;
	r = (original_color >> 16) & 0xFF;
	g = (original_color >> 8) & 0xFF;
	b = original_color & 0xFF;
	r = (int)((1 - fog_intensity) * r + fog_intensity * ((fog_color >> 16) & 0xFF));
	g = (int)((1 - fog_intensity) * g + fog_intensity * ((fog_color >> 8) & 0xFF));
	b = (int)((1 - fog_intensity) * b + fog_intensity * (fog_color & 0xFF));

	return (r << 16 | g << 8 | b);
}



void	ft_draw_line(t_game *game, t_img *img, int x)
{
	int		y;
	int		color;
	double	dist;

	y = 0;
	while (y <= HEIGHT)
	{
		if (y < game->ray->draw_start)
		{
			dist = (HEIGHT / 2.0) / (HEIGHT / 2.0 - y);
			color = apply_fog(game->ceiling_color, dist);
			ft_mlx_pixel_put(img, x, y, color);
		}
		else if (y > game->ray->draw_end)
		{
			dist = (HEIGHT / 2.0) / (y - HEIGHT / 2.0);
			color = apply_fog(game->floor_color, dist);
			ft_mlx_pixel_put(img, x, y, color);
		}
		else
		{
			game->ray->tex.y = (int)game->ray->tex_pos & 255;
			game->ray->tex_pos += game->ray->step;
			color = ft_get_color(&game->texture[game->ray->side], game->ray->tex.x, game->ray->tex.y);
			color = apply_fog(color, game->ray->perp_wall_dist);
			ft_mlx_pixel_put(img, x, y, color);
		}
		y++;
	}
}

