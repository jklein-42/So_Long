/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpaceGame_graphics.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 22:17:53 by jklein            #+#    #+#             */
/*   Updated: 2022/08/30 20:09:19 by jklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../SpaceGame_headers/so_long.h"

		/* --
		The SpaceCraft game graphics is controlled here,
		The size of the images is set to 80 pixels -- */

void	ft_place_player(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->SpaceCraft, width * 80, height * 80);
	game->playersecond = height;
	game->playerfirst = width;
}

void	place_collectable(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->SpaceCrate, width * 80, height * 80);
	game->collectables++;
}

		/* --
		This code will compile the graphics of the platform game,
		The exit point the walls the cellectables and the background -- */

void	ft_load_images(t_complete *game)
{
	int	image_01;
	int	image_02;

	game->Black = mlx_xpm_file_to_image(game->mlxpointer,
			"SpaceGame_images/Black.xpm", &image_01, &image_02);
	game->SpaceRock = mlx_xpm_file_to_image(game->mlxpointer,
			"SpaceGame_images/SpaceRock.xpm", &image_01, &image_02);
	game->Planet = mlx_xpm_file_to_image(game->mlxpointer,
			"SpaceGame_images/Planet.xpm", &image_01, &image_02);
	game->SpaceCrate = mlx_xpm_file_to_image(game->mlxpointer,
			"SpaceGame_images/SpaceCrate.xpm", &image_01, &image_02);
}

		/* --
		This function output is the derection of the SpaceCraft
		You use the derection keys to move the SpaceCraft -- */

void	ft_directions(t_complete *game)
{
	int	image_01;
	int	image_02;

	game->SpaceCraft = mlx_xpm_file_to_image(game->mlxpointer,
			"SpaceGame_images/SpaceCraft/Up.xpm", &image_01, &image_02);
	game->SpaceCraft = mlx_xpm_file_to_image(game->mlxpointer,
			"SpaceGame_images/SpaceCraft/Down.xpm", &image_01, &image_02);
	game->SpaceCraft = mlx_xpm_file_to_image(game->mlxpointer,
			"SpaceGame_images/SpaceCraft/Left.xpm", &image_01, &image_02);
	game->SpaceCraft = mlx_xpm_file_to_image(game->mlxpointer,
			"SpaceGame_images/SpaceCraft/Right.xpm", &image_01, &image_02);
}	

		/* --
		This function creates the graphics by compiling the images into
	   	The platform SpaceGame	-- */

void	ft_make_graphics(t_complete *game)
{
	int	height;
	int	width;

	game->collectables = 0;
	height = 0;
	while (height < game->heightmap)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == '1')
				mlx_put_image_to_window(game->mlxpointer,
					game->winpointer, game->SpaceRock, width * 80, height * 80);
			if (game->map[height][width] == 'C')
				place_collectable(game, height, width);
			if (game->map[height][width] == 'P')
				ft_place_player(game, height, width);
			if (game->map[height][width] == 'E')
				mlx_put_image_to_window(game->mlxpointer,
					game->winpointer, game->Planet, width * 80, height * 80);
			if (game->map[height][width] == '0')
				mlx_put_image_to_window(game->mlxpointer,
					game->winpointer, game->Black, width * 80, height * 80);
			width++;
		}
		height++;
	}
}
