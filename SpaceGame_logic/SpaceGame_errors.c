/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpaceGame_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 22:17:10 by jklein            #+#    #+#             */
/*   Updated: 2022/08/30 19:58:11 by jklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../SpaceGame_headers/so_long.h"

		/* --
		This function will output a string incace of a error, 
		each string will give the return sequence of the error type -- */

static int	horizontalwall(t_complete *game)
{
	int	height;
	int	width;

	height = game->widthmap;
	width = 0;
	while (width < height)
	{
		if (game->map[0][height] == '1' && game->map
				[game->heightmap - 1][width] == '1')
			return (0);
		width++;
	}
	return (1);
}

static int	verticalwall(t_complete *game)
{
	int	height;
	int	width;

	height = 0;
	width = game->widthmap;
	while (height < game->heightmap)
	{
		if (!(game->map[height][0] == '1' && game->map
			[height][width - 1] == '1'))
			return (0);
		height++;
	}
	return (1);
}

static void	if_walls(t_complete *game)
{
	int	verticalwalls;
	int	horizontalwalls;

	verticalwalls = verticalwall(game);
	horizontalwalls = horizontalwall(game);
	if (!verticalwalls || !horizontalwalls)
	{
		printf("\e[31m\e[1mError\n THIS MAP IS MISSING THE WALLS\e[0m \n");
		ft_exit_location(game);
	}
}

static void	count_checker(t_complete *game, int height, int width)
{
	if (game->map[height][width] != '1' &&
		game->map[height][width] != '0' &&
		game->map[height][width] != 'P' &&
		game->map[height][width] != 'E' &&
		game->map[height][width] != 'C' &&
		game->map[height][width] != '\n')
	{
		printf("\e[31m\e[1mError\n ERROR HERE !!!%c\n", game->map[height][width]);
		ft_exit_location(game);
	}
	if (game->map[height][width] == 'C')
			game->columncount++;
	if (game->map[height][width] == 'P')
			game->playercount++;
	if (game->map[height][width] == 'E')
			game->exitcount++;
}

void	character_valid(t_complete *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->heightmap - 1)
	{
		width = 0;
		while (width <= game->widthmap)
		{
			count_checker(game, height, width);
			width++;
		}
		height++;
	}
	if (!(game->playercount == 1 && game->columncount > 1
			&& game->exitcount == 1))
	{
		printf("\e[31m\e[1mError\n SOMETHING IS WRONG,");
		printf(" EITHER PLAYER, EXIT OR COLLECTABLE ISSUE \e[0m \n");
		ft_exit_location(game);
	}
}

void	ft_error_checker(t_complete *game)
{
	if_walls(game);
	character_valid(game);
}
