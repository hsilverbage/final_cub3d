/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:50:41 by ahmedkhella       #+#    #+#             */
/*   Updated: 2023/12/16 16:42:27 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_rot_left(t_game *game)
{
	game->ray->angle -= ROT_SPEED;
	game->ray->dir.x = cos(game->ray->angle);
	game->ray->dir.y = sin(game->ray->angle);
	game->ray->plane.x = -game->ray->dir.y * 0.60;
	game->ray->plane.y = game->ray->dir.x * 0.60;
}

void	ft_rot_right(t_game *game)
{
	game->ray->angle += ROT_SPEED;
	game->ray->dir.x = cos(game->ray->angle);
	game->ray->dir.y = sin(game->ray->angle);
	game->ray->plane.x = -game->ray->dir.y * 0.60;
	game->ray->plane.y = game->ray->dir.x * 0.60;
}
