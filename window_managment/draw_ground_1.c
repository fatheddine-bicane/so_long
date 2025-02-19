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
			"./sprites/ground/L_T_corner_1.xpm",
			&(*game)->width, &(*game)->height);
	(*game)->ground[4] = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/ground/L_T_corner_2.xpm",
			&(*game)->width, &(*game)->height);
	(*game)->ground[5] = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/ground/L_T_corner_3.xpm",
			&(*game)->width, &(*game)->height);
	(*game)->ground[6] = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/ground/L_T_corner_4.xpm",
			&(*game)->width, &(*game)->height);
	(*game)->ground[7] = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/ground/left_wall.xpm",
			&(*game)->width, &(*game)->height);
}
void	ft_load_ground(t_game **game)
{
	ft_load_ground_utils(game);
	(*game)->ground[8] = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/ground/R_D_corner.xpm",
			&(*game)->width, &(*game)->height);
	(*game)->ground[9] = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/ground/R_T_corner_1.xpm",
			&(*game)->width, &(*game)->height);
	(*game)->ground[10] = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/ground/R_T_corner_2.xpm",
			&(*game)->width, &(*game)->height);
	(*game)->ground[11] = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/ground/R_T_corner_3.xpm",
			&(*game)->width, &(*game)->height);
	(*game)->ground[12] = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/ground/R_T_corner_4.xpm",
			&(*game)->width, &(*game)->height);
	(*game)->ground[13] = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./sprites/ground/Right_wall.xpm",
			&(*game)->width, &(*game)->height);
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
			if (r == 0 && i == 0)
				mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr, (*game)->ground[3], i * (*game)->width, r * (*game)->height);
		}
		break ;
	}
	/*mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr, (*game)->ground, 4 * (*game)->width, 1 * (*game)->height);*/
}

