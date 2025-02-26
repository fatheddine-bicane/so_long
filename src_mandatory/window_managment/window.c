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

int	ft_close(t_game **game)
{
	ft_free_game(game);
	exit(1);
}

void	ft_open_win(t_game **game)
{
	(*game)->mlx_ptr = mlx_init();
	(*game)->win_ptr = mlx_new_window((*game)->mlx_ptr,
			(*game)->indexes_count * TILE_SIZE,
			(*game)->rows_count * TILE_SIZE, "so_long");
	ft_load_ground(game);
	ft_render_map(game);
	mlx_hook((*game)->win_ptr, 2, 1L << 0, ft_move_player, game);
	mlx_hook((*game)->win_ptr, 17, 0, ft_close, game);
	mlx_loop((*game)->mlx_ptr);
}
