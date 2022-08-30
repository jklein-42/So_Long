/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:44:29 by jklein            #+#    #+#             */
/*   Updated: 2022/08/29 17:18:52 by jklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "get_next_line.h"
# include "../mlx_SpaceGame/mlx.h"

typedef struct t_start
{
	int		fd;
	int		heightmap;
	int		widthmap;
	int		playercount;
	int		columncount;
	int		exitcount;
	int		playerfirst;
	int		playersecond;
	int		counter;
	int		collectables;

	char	**map;

	void	*Black;
	void	*SpaceRock;
	void	*SpaceCraft;
	void	*Planet;
	void	*SpaceCrate;
	void	*mlxpointer;
	void	*winpointer;

}	t_complete;

int		ft_exit_location(t_complete *game);
int		ft_map_setup(t_complete *game, char **argv);
int		ft_start_controls(int command, t_complete *game);
void	ft_make_graphics(t_complete *game);
void	ft_load_images(t_complete *game);
void	ft_directions(t_complete *game);
void	ft_error_checker(t_complete *game);

#endif
