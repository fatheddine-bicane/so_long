/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ground_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:13:04 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/19 15:52:25 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_load_ground_utils(t_game **game)
{
	(*game)->ground[0] = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/ground/ground.xpm", &(*game)->width, &(*game)->height);
	(*game)->ground[1] = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/ground/ground_map.xpm",
			&(*game)->width, &(*game)->height);
	(*game)->ground[2] = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/ground/L_D_corner.xpm",
			&(*game)->width, &(*game)->height);
	(*game)->ground[3] = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/ground/L_top_corner.xpm",
			&(*game)->width, &(*game)->height);
	(*game)->ground[4] = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/ground/left_wall.xpm",
			&(*game)->width, &(*game)->height);
}
void	ft_load_ground(t_game **game)
{
	ft_load_ground_utils(game);
	(*game)->ground[5] = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/ground/R_D_corner.xpm",
			&(*game)->width, &(*game)->height);
	(*game)->ground[6] = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/ground/R_top_corner.xpm",
			&(*game)->width, &(*game)->height);
	(*game)->ground[7] = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/ground/Right_wall.xpm",
			&(*game)->width, &(*game)->height);
	(*game)->ground[8] = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/ground/T_ground.xpm",
			&(*game)->width, &(*game)->height);
	(*game)->door = mlx_xpm_file_to_image((*game)->mlx_ptr, "./sprites/door.xpm", &(*game)->width, &(*game)->height);
	(*game)->background_1 = mlx_xpm_file_to_image((*game)->mlx_ptr, "./sprites/background_1.xpm", &(*game)->width, &(*game)->height);
	(*game)->idle = mlx_xpm_file_to_image((*game)->mlx_ptr, "./sprites/Idle.xpm", &(*game)->width, &(*game)->height);
	(*game)->scroll = mlx_xpm_file_to_image((*game)->mlx_ptr, "./sprites/scroll.xpm", &(*game)->width, &(*game)->height);
}

void	ft_render_map(t_game **game)
{
	int	r;
	int	i;

	r = 0;
	ft_load_ground(game);
	while ((*game)->map[r])
	{
		i = 0;
		while ((*game)->map[r][i])
		{
			if (r == 0 && i == 0)
				mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr, (*game)->ground[3], i * (*game)->width, r * (*game)->height);
			else if (r == 0 && (i == (*game)->indexes_count - 1 ))
				mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr, (*game)->ground[6], i * (*game)->width, r * (*game)->height);
			else if (r == 0 && (*game)->map[r][i] == '1')
				mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr, (*game)->ground[8], i * (*game)->width, r * (*game)->height);
			else if (r == (*game)->rows_count - 1 && i == 0 && (*game)->map[r][i] == '1')
				mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr, (*game)->ground[2], i * (*game)->width, r * (*game)->height);
			else if (r == (*game)->rows_count - 1 && i == (*game)->indexes_count - 1 && (*game)->map[r][i] == '1')
				mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr, (*game)->ground[5], i * (*game)->width, r * (*game)->height);
			else if (i == (*game)->indexes_count - 1 && (*game)->map[r][i] == '1')
				mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr, (*game)->ground[7], i * (*game)->width, r * (*game)->height);
			else if (r == (*game)->rows_count - 1 && (*game)->map[r][i] == '1')
				mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr, (*game)->ground[0], i * (*game)->width, r * (*game)->height);
			else if (i == 0 && (*game)->map[r][i] == '1')
				mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr, (*game)->ground[4], i * (*game)->width, r * (*game)->height);
			else if ((*game)->map[r][i] == '1')
				mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr, (*game)->ground[1], i * (*game)->width, r * (*game)->height);
			else if ((*game)->map[r][i] == 'E')
				mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr, (*game)->door, i * (*game)->width, r * (*game)->height);
			else if ((*game)->map[r][i] == '0')
				mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr, (*game)->background_1, i * (*game)->width, r * (*game)->height);
			else if ((*game)->map[r][i] == 'P')
				mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr, (*game)->idle, i * (*game)->width, r * (*game)->height);
			else if ((*game)->map[r][i] == 'C')
					mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr, (*game)->scroll, i * (*game)->width, r * (*game)->height);
			i++;
		}
		r++;
	}
	/*mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr, (*game)->ground, 4 * (*game)->width, 1 * (*game)->height);*/
}

