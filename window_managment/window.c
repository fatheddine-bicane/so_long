/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:56:05 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/19 15:48:34 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_close()
{
	exit(1);
	return 0;
}

void	ft_open_win(t_game **game)
{
	int	width;
	int	height;

	(*game)->mlx_ptr = mlx_init();
	(*game)->win_ptr = mlx_new_window((*game)->mlx_ptr, (*game)->indexes_count * TILE_SIZE, (*game)->rows_count * TILE_SIZE, "so_long");
	(*game)->background = mlx_xpm_file_to_image((*game)->mlx_ptr, "./sprites/background_Town1.xpm", &width, &height);
	/*mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr, (*game)->background, 0, 0);*/
	ft_load_ground(game);
	ft_render_map(game);

	mlx_hook((*game)->win_ptr, 2, 1L << 0, ft_move_player, game);

	//close with x
	mlx_hook((*game)->win_ptr, 17, 0, ft_close, NULL);

	mlx_loop((*game)->mlx_ptr);
}
