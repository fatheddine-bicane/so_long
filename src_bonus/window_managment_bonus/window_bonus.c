/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:56:05 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/28 16:02:55 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	ft_render_map_utils_2(t_game **game, int r, int i)
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
			(*game)->trees, i * (*game)->width, r * (*game)->height);
	else if ((*game)->map[r][i] == '0')
		mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
			(*game)->ground, i * (*game)->width, r * (*game)->height);
	else if ((*game)->map[r][i] == 'X')
		mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
			(*game)->skeleton, i * (*game)->width, r * (*game)->height);
}

void	ft_mouve_count(t_game **game)
{
	char	*moves;

	moves = ft_itoa((*game)->mouve_count);
	mlx_set_font((*game)->mlx_ptr, (*game)->win_ptr, "rk24");
	mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
		(*game)->walo, 60, (*game)->rows_count * TILE_SIZE);
	mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
		(*game)->walo, 92, (*game)->rows_count * TILE_SIZE);
	mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
		(*game)->walo, 124, (*game)->rows_count * TILE_SIZE);
	mlx_string_put((*game)->mlx_ptr, (*game)->win_ptr, 2,
		(*game)->rows_count * TILE_SIZE + 30, 0x557D55, "Move: ");
	mlx_string_put((*game)->mlx_ptr, (*game)->win_ptr, 60,
		(*game)->rows_count * TILE_SIZE + 30, 0x557D55, moves);
	free(moves);
}

static void	ft_frames(int *frame, int *index)
{
	(*frame)++;
	if ((*frame) % 10 == 0)
		(*index)++;
	if ((*index) == 4)
		(*index) = 0;
}

int	ft_render_map_2(t_game **game)
{
	int			i;
	static int	frame;
	static int	j;

	ft_frames(&frame, &j);
	int (r) = -1;
	ft_move_enem(game);
	while ((*game)->map[++r])
	{
		i = -1;
		while ((*game)->map[r][++i])
		{
			ft_render_map_utils_2(game, r, i);
			if ((*game)->map[r][i] == 'E')
				mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
					(*game)->door, i * (*game)->width, r * (*game)->height);
			else if ((*game)->map[r][i] == 'P')
				mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
					(*game)->idle[j], i * (*game)->width, r * (*game)->height);
			else if ((*game)->map[r][i] == 'C')
				mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
					(*game)->coin[j], i * (*game)->width, r * (*game)->height);
		}
	}
	return (ft_mouve_count(game), 0);
}

void	ft_open_win(t_game **game)
{
	(*game)->mlx_ptr = mlx_init();
	(*game)->win_ptr = mlx_new_window((*game)->mlx_ptr,
			(*game)->indexes_count * TILE_SIZE,
			(*game)->rows_count * TILE_SIZE + 32, "so_long");
	ft_load_ground(game);
	mlx_hook((*game)->win_ptr, 2, 1L << 0, ft_move_player, game);
	mlx_hook((*game)->win_ptr, 17, 0, ft_close, game);
	mlx_loop_hook((*game)->mlx_ptr, ft_render_map_2, game);
	mlx_loop((*game)->mlx_ptr);
}
