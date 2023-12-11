#include "cub3D.h"

static void	ft_init_values(t_game *game, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)WIDTH - 1;
	game->ray->raydir.x = game->ray->dir.x + game->ray->plane.x * camera_x;
	game->ray->raydir.y = game->ray->dir.y + game->ray->plane.y * camera_x;
	game->ray->map.x = (int)game->ray->pos.x;
	game->ray->map.y = (int)game->ray->pos.y;
	game->ray->delta_dist.x = 1 / game->ray->raydir.x;
	game->ray->delta_dist.y = 1 / game->ray->raydir.y;
	if (game->ray->delta_dist.x < 0)
		game->ray->delta_dist.x *= -1;
	if (game->ray->delta_dist.y < 0)
		game->ray->delta_dist.y *= -1;
}

static void	ft_calculate_side_dist(t_game *game)
{
	if (game->ray->raydir.x < 0)
	{
		game->ray->step_pos.x = -1;
		game->ray->side_dist.x = (game->ray->pos.x - game->ray->map.x) \
			* game->ray->delta_dist.x;
	}
	else
	{
		game->ray->step_pos.x = 1;
		game->ray->side_dist.x = (game->ray->map.x + 1.0 - game->ray->pos.x) \
			* game->ray->delta_dist.x;
	}
	if (game->ray->raydir.y < 0)
	{
		game->ray->step_pos.y = -1;
		game->ray->side_dist.y = (game->ray->pos.y - game->ray->map.y) \
			* game->ray->delta_dist.y;
	}
	else
	{
		game->ray->step_pos.y = 1;
		game->ray->side_dist.y = (game->ray->map.y + 1.0 - game->ray->pos.y) \
			* game->ray->delta_dist.y;
	}
}

void	draw_player_on_minimap(t_game *game)
{
    int player_minimap_x = (int)(game->ray->pos.y * ((float)MINIMAP_WIDTH / (game->map_width + 1)));
    int player_minimap_y = (int)(game->ray->pos.x * ((float)MINIMAP_HEIGHT / (game->map_height + 1)));
    int half_size = PLAYER_SIZE / 2; // La moitié de la taille du joueur pour centrer le carré

    for (int y = -half_size; y <= half_size; y++)
    {
        for (int x = -half_size; x <= half_size; x++)
        {
            int px = player_minimap_x + x;
            int py = player_minimap_y + y;

            if (px >= 0 && px < MINIMAP_WIDTH && py >= 0 && py < MINIMAP_HEIGHT)
            {
                ft_mlx_pixel_put(&game->minimap, px, py, 0x0000FF);
            }
        }
    }
}

void	draw_minimap(t_game *game)
{
	int x, y;
	int map_x, map_y;

	for (y = 0; y < MINIMAP_HEIGHT; y++)
	{	
		for (x = 0; x < MINIMAP_WIDTH; x++)
		{
			map_x = (int)(x * ((float)(game->map_width + 1) / MINIMAP_WIDTH));
			map_y = (int)(y * ((float)(game->map_height + 1) / MINIMAP_HEIGHT));

			if (map_x >= 0 && map_x < (game->map_width + 1) && map_y >= 0 && map_y < (game->map_height + 1))
			{
				int color = game->map[map_y][map_x] == '1' ? 0x000000 : 0x808B96;
				ft_mlx_pixel_put(&game->minimap, x, y, color);
			}
		}
	}

}

// Fonction pour afficher la minimap
void	display_minimap(t_game *game)
{
	// Mettre à jour la minimap
	draw_minimap(game);
	draw_player_on_minimap(game);
	// Afficher la minimap sur la fenêtre
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, game->minimap.img, 0, 0);
}

int	ft_loop(t_game *game)
{
	int		x;

	ft_move(game);
	x = 0;
	while (x++ < WIDTH)
	{
		ft_init_values(game, x);
		ft_calculate_side_dist(game);
		ft_cast_ray(game);
		ft_calculate_positions(game);
		ft_draw_line(game, &game->mlx->img, x);
	}
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, \
		game->mlx->img.img, 0, 0);
	display_minimap(game);
	return (0);
}
