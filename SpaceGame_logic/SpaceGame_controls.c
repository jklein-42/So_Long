/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpaceGame_controls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 22:16:35 by jklein            #+#    #+#             */
/*   Updated: 2022/08/30 19:49:42 by jklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../SpaceGame_headers/so_long.h"

		/* --  
		The sorce code controlls the data of the movement of the 
		SpaceCraft

		This program moves the SpaceCraft up & down, also Left & Right -- */

static int	right_move(t_complete *game, int i, int j);

		/* --
		This code uses the a & d keys to move the SpaceCraft
        Left & Right -- */

static	int	keyboard_a_d(t_complete *game, int movement)
{
	int	data_01;
	int	data_02;
	int	data_03;

	data_01 = game->playerfirst;
	data_02 = game->playersecond;
	if (movement == 0)
	{
		data_01--;
		if (game->map[data_02][data_01] == '1')
			return (0);
		data_03 = right_move(game, data_01, data_02);
		if (!data_03)
			return (0);
		game->map[data_02][data_01 + 1] = '0';
	}
	else if (movement == 2)
	{
		data_01++;
		if (game->map[data_02][data_01] == '1')
			return (0);
		data_03 = right_move(game, data_01, data_02);
		if (!data_03)
			return (0);
		game->map[data_02][data_01 - 1] = '0';
	}
	printf("MOVES TAKEN: %i\n", game->counter);
	printf("SPACECRATES REMAINING: %i\n", game->collectables);
	return (1);
}
		/* -- 
		This code uses the w & s keys to move the SpaceCraft
		up & down -- */

static	int	keyboard_w_s(t_complete *game, int movement)
{
	int	data_01;
	int	data_02;
	int	data_03;

	data_01 = game->playerfirst;
	data_02 = game->playersecond;
	if (movement == 13)
	{
		data_02--;
		if (game->map[data_02][data_01] == '1')
			return (0);
		data_03 = right_move(game, data_01, data_02);
		if (!data_03)
			return (0);
		game->map[data_02 + 1][data_01] = '0';
	}
	else if (movement == 1)
	{
		data_02++;
		if (game->map[data_02][data_01] == '1')
			return (0);
		data_03 = right_move(game, data_01, data_02);
		if (!data_03)
			return (0);
		game->map[data_02 - 1][data_01] = '0';
	}
	printf("MOVES TAKEN: %i\n", game->counter);
	printf("SPACECRATES REMAINING: %i\n", game->collectables);
	return (1);
}

	/* -- 
	This function will return the string you have won once you have
	finished the game -- */

static int	right_move(t_complete *game, int i, int j)
{
	if (game->map[j][i] == 'E')
	{
		if (game->collectables != 0)
			return (0);
		printf("\e[31m\e[1m\nYOU HAVE WON, CONGRATS !!! \e[0m \n");
		ft_exit_location(game);
	}
	if (game->map[j][i] == '0')
	{
		game->map[j][i] = 'P';
		game->playerfirst = i;
		game->playersecond = j;
		game->counter++;
	}
	if (game->map[j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->playerfirst = i;
		game->playersecond = j;
		game->collectables--;
		game->counter++;
	}
	return (1);
}
		/* --
		This statment will compile the controlls to active,
		The images that rotate the SpaceCraft are decleared here -- */

int	ft_start_controls(int command, t_complete *game)
{
	int	image_01;
	int	image_02;
	int	controls_on;

	if (command == 53)
		ft_exit_location(game);
	if (command == 13)
	{
		game->SpaceCraft = mlx_xpm_file_to_image(game->mlxpointer,
				"SpaceGame_images/SpaceCraft/Up.xpm", &image_01, &image_02);
	}
		controls_on = keyboard_w_s(game, command);
	if (command == 1)
	{
		game->SpaceCraft = mlx_xpm_file_to_image(game->mlxpointer,
				"SpaceGame_images/SpaceCraft/Down.xpm", &image_01, &image_02);
	}
		controls_on = keyboard_w_s(game, command);
	if (controls_on)
		ft_make_graphics(game);
	if (command == 0)
	{
		game->SpaceCraft = mlx_xpm_file_to_image(game->mlxpointer,
				"SpaceGame_images/SpaceCraft/Left.xpm", &image_01, &image_02);
	}
		controls_on = keyboard_a_d(game, command);
	if (command == 2)
	{
		game->SpaceCraft = mlx_xpm_file_to_image(game->mlxpointer,
				"SpaceGame_images/SpaceCraft/Right.xpm", &image_01, &image_02);
	}
		controls_on = keyboard_a_d(game, command);
	if (controls_on)
		ft_make_graphics(game);
	return (1);
}
