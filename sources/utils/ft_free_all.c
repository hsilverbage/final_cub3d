#include "cub3D.h"

void	tab_free(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	ft_free_all(t_game *game)
{
	int	i;

	i = 0;
	if (game->file)
	{
		while (game->file[i])
			free(game->file[i++]);
		free(game->file);
	}
	if (game->mlx->mlx)
		free(game->mlx->mlx);
	if (game->mlx)
		free(game->mlx);
	if (game->ray)
		free(game->ray);
}

void	ft_free_mlx(t_game *game)
{
	mlx_clear_window(game->mlx->mlx, game->mlx->win);
	mlx_destroy_window(game->mlx->mlx, game->mlx->win);
	mlx_destroy_display(game->mlx->mlx);
}

int	ft_exit(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->texture[i].img)
			mlx_destroy_image(game->mlx->mlx, game->texture[i].img);
		i++;
	}
	mlx_destroy_image(game->mlx->mlx, game->mlx->img.img);
	ft_free_mlx(game);
	ft_free_all(game);
	exit(EXIT_SUCCESS);
	return (0);
}
