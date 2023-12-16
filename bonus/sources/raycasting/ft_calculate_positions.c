/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_positions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:58:15 by akhellad          #+#    #+#             */
/*   Updated: 2023/12/16 17:28:42 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3Dbonus.h"

static int	ft_calculate_height(t_game *game)
{
	if (game->ray->boolean)
		game->ray->perp_wall_dist = \
			(game->ray->side_dist.x);
	else
		game->ray->perp_wall_dist = \
			(game->ray->side_dist.y);
	return ((int)(HEIGHT / game->ray->perp_wall_dist));
}

static void	ft_calculate_range(t_game *game, int line_height)
{
	game->ray->draw_start = -line_height / 2 + HEIGHT / 2;
	if (game->ray->draw_start < 0)
		game->ray->draw_start = 0;
	game->ray->draw_end = line_height / 2 + HEIGHT / 2;
	if (game->ray->draw_end >= HEIGHT)
		game->ray->draw_end = HEIGHT - 1;
}

static void	ft_calculate_textures(t_game *game, int line_height)
{
	double	wall_x;

	if (game->ray->boolean)
		wall_x = game->ray->pos.y + game->ray->perp_wall_dist * \
			game->ray->raydir.y;
	else
		wall_x = game->ray->pos.x + game->ray->perp_wall_dist * \
			game->ray->raydir.x;
	wall_x -= floor(wall_x);
	game->ray->tex.x = (int)(wall_x * game->image_height);
	if (game->ray->side <= 1 && game->ray->raydir.x > 0)
		game->ray->tex.x = game->image_height - game->ray->tex.x - 1;
	else if (game->ray->side >= 2 && game->ray->raydir.y < 0)
		game->ray->tex.x = game->image_height - game->ray->tex.x - 1;
	game->ray->step = 1.0 * game->image_height / line_height;
	game->ray->tex_pos = (game->ray->draw_start - HEIGHT / 2 + \
	line_height / 2) * game->ray->step;
}

void	ft_calculate_positions(t_game *game)
{
	int	line_height;

	line_height = ft_calculate_height(game);
	ft_calculate_range(game, line_height);
	ft_calculate_textures(game, line_height);
}
