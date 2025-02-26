/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ground_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:13:04 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/25 16:14:41 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_load_ground_utils(t_game **game)
{
	(*game)->ground = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/ground.xpm", &(*game)->width, &(*game)->height);
	(*game)->trees[0] = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/tree_3.xpm",
			&(*game)->width, &(*game)->height);
	(*game)->trees[1] = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/tree_4.xpm",
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
}

void	ft_load_ground(t_game **game)
{
	ft_load_ground_utils(game);
	(*game)->door = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/exit.xpm", &(*game)->width, &(*game)->height);
	(*game)->idle = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/player.xpm", &(*game)->width, &(*game)->height);
	(*game)->coin = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/coin.xpm", &(*game)->width, &(*game)->height);
}

int	pick_tree(void)
{
	static int	i;

	i = (i + 1) % 2;
	return (i);
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
			(*game)->trees[pick_tree()],
			i * (*game)->width, r * (*game)->height);
	else if ((*game)->map[r][i] == '0')
		mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
			(*game)->ground, i * (*game)->width, r * (*game)->height);
}

void	ft_render_map(t_game **game)
{
	int	r;
	int	i;

	r = 0;
	while ((*game)->map[r])
	{
		i = 0;
		while ((*game)->map[r][i])
		{
			ft_render_map_utils(game, r, i);
			if ((*game)->map[r][i] == 'E')
				mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
					(*game)->door, i * (*game)->width, r * (*game)->height);
			else if ((*game)->map[r][i] == 'P')
				mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
					(*game)->idle, i * (*game)->width, r * (*game)->height);
			else if ((*game)->map[r][i] == 'C')
				mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
					(*game)->coin, i * (*game)->width, r * (*game)->height);
			i++;
		}
		r++;
	}
}
