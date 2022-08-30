/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpaceGame_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 22:18:26 by jklein            #+#    #+#             */
/*   Updated: 2022/08/30 20:12:55 by jklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../SpaceGame_headers/so_long.h"

		/* --
		The map is built by using the source code form this function,
		It also creates the maps -- */

static int	width_of_map(char *string)
{
	int	width;

	width = 0;
	while (string[width] != '\0')
		width++;
	if (string[width - 1] == '\n')
		width--;
	return (width);
}

static int	add_line(t_complete *game, char *line)
{
	char	**temporary;
	int		in;

	if (!line)
		return (0);
	in = 0;
	game->heightmap++;
	temporary = (char **)malloc(sizeof(char *) * (game->heightmap + 1));
	temporary[game->heightmap] = NULL;
	while (in < game->heightmap - 1)
	{
		temporary[in] = game->map[in];
		in++;
	}
	temporary[in] = line;
	if (game->map)
		free(game->map);
	game->map = temporary;
	return (1);
}

int	ft_map_setup(t_complete *game, char **argv)
{
	char	*readmap;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	while (1)
	{
		readmap = get_next_line(game->fd);
		if (!add_line(game, readmap))
			break ;
	}
	close (game->fd);
	game->widthmap = width_of_map(game->map[0]);
	return (1);
}
