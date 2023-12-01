#include "cub3D.h"

int	ft_init_window(t_game *game)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		ft_error_msg(ERR_MALLOC, game);
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		ft_error_msg(ERR_MALLOC, game);
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "Cub3D");
	if (!mlx->win)
		ft_error_msg(ERR_MALLOC, game);
	game->mlx = mlx;
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		ft_error_msg(ERR_ARG, &game);
	ft_init_struct(&game);
	ft_parsing(&game, argv[1]);
	ft_init_window(&game);
	ft_raycasting(&game);
	return (0);
}
