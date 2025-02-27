/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ground_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:13:04 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/27 10:41:59 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_load_ground_utils(t_game **game)
{
	(*game)->ground = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/ground.xpm", &(*game)->width, &(*game)->height);
	(*game)->trees = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/tree.xpm",
			&(*game)->width, &(*game)->height);
	(*game)->boarder[0] = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/swamp_1.xpm",
			&(*game)->width, &(*game)->height);
	(*game)->boarder[1] = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/swamp_2.xpm",
			&(*game)->width, &(*game)->height);
	(*game)->boarder[2] = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/swamp_3.xpm",
			&(*game)->width, &(*game)->height);
	(*game)->skeleton = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/skeleton.xpm",
			&(*game)->width, &(*game)->height);
	(*game)->walo = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/walo.xpm",
			&(*game)->width, &(*game)->height);
}

void	ft_load_ground(t_game **game)
{
	ft_load_ground_utils(game);
	(*game)->door = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/exit.xpm", &(*game)->width, &(*game)->height);
	(*game)->idle_r[0] = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/knigt_1.xpm", &(*game)->width, &(*game)->height);
	(*game)->idle_r[1] = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/knigt_2.xpm", &(*game)->width, &(*game)->height);
	(*game)->idle_r[2] = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/knigt_3.xpm", &(*game)->width, &(*game)->height);
	(*game)->idle_r[3] = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/knigt_4.xpm", &(*game)->width, &(*game)->height);
	(*game)->coin[0] = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/coin_1.xpm", &(*game)->width, &(*game)->height);
	(*game)->coin[1] = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/coin_2.xpm", &(*game)->width, &(*game)->height);
	(*game)->coin[2] = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/coin_3.xpm", &(*game)->width, &(*game)->height);
	(*game)->coin[3] = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/coin_4.xpm", &(*game)->width, &(*game)->height);
}

void	ft_render_map_utils(t_game **game, int r, int i)
{
	int	rl;
	int	il;

	rl = (*game)->rows_count - 1;
	il = (*game)->indexes_count - 1;
	if ((r == 0 && i == 0) || (r == rl && i == 0)
		|| (r == 0 && i == il) || (r == rl && i == il))
		mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
			(*game)->boarder[2], i * (*game)->width, r * (*game)->height);
	else if (r == 0 || r == rl)
		mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
			(*game)->boarder[1], i * (*game)->width, r * (*game)->height);
	else if (i == 0 || i == il)
		mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
			(*game)->boarder[0], i * (*game)->width, r * (*game)->height);
	else if ((*game)->map[r][i] == '1')
		mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
			(*game)->trees,
			i * (*game)->width, r * (*game)->height);
	else if ((*game)->map[r][i] == '0')
		mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
			(*game)->ground, i * (*game)->width, r * (*game)->height);
}

void	ft_render_map(t_game **game)
{
	int	i;

	int (r) = 0;
	while ((*game)->map[r])
	{
		i = -1;
		while ((*game)->map[r][++i])
		{
			ft_render_map_utils(game, r, i);
			if ((*game)->map[r][i] == 'E')
				mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
					(*game)->door, i * (*game)->width, r * (*game)->height);
			else if ((*game)->map[r][i] == 'P')
				mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
					(*game)->idle_r[1], i * (*game)->width,
					r * (*game)->height);
			else if ((*game)->map[r][i] == 'C')
				mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
					(*game)->coin[0], i * (*game)->width, r * (*game)->height);
			else if ((*game)->map[r][i] == 'X')
				mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
					(*game)->skeleton, i * (*game)->width, r * (*game)->height);
		}
		r++;
	}
}
