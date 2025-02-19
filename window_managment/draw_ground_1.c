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

/*void	ft_load_ground(t_game **game)*/
/*{*/
/**/
/*}*/

void	ft_render_map(t_game **game)
{
	(*game)->ground = mlx_xpm_file_to_image((*game)->mlx_ptr, "./sprites/ground/ground_map.xpm", &(*game)->width, &(*game)->height);
	mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr, (*game)->ground, 4 * (*game)->width, 1 * (*game)->height);
}

