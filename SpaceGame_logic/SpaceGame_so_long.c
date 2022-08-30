/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpaceGame_so_long.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 22:18:51 by jklein            #+#    #+#             */
/*   Updated: 2022/08/30 20:15:50 by jklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../SpaceGame_headers/so_long.h"

		/* --
		This code needs this function to compile the SpaceGame, the main
		links all the functions to compile the platform SpaceGame -- */

static void	*ft_memset(void *b, int c, size_t length)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (length--)
		*ptr++ = (unsigned char)c;
	return (b);
}

int	ft_exit_location(t_complete *game)
{
	int	line;

	line = 0;
	if (game->winpointer)
		mlx_destroy_window(game->mlxpointer, game->winpointer);
	free(game->mlxpointer);
	while (line < game->heightmap - 1)
		free(game->map[line++]);
	free(game->map);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_complete	game;

	if (argc != 2)
		return (0);
	ft_memset(&game, 0, sizeof(t_complete));
	ft_map_setup(&game, argv);
	ft_error_checker(&game);
	game.mlxpointer = mlx_init();
	game.winpointer = mlx_new_window(game.mlxpointer, (game.widthmap * 80),
			(game.heightmap * 80), "solong");
	ft_load_images(&game);
	ft_directions(&game);
	ft_make_graphics(&game);
	mlx_key_hook(game.winpointer, ft_start_controls, &game);
	mlx_hook(game.winpointer, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlxpointer);
}
