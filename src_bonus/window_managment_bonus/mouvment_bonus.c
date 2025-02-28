/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvment.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:12:51 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/27 10:58:17 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

char	is_valid_move(t_game **game, int x, int y)
{
	char	tile;

	tile = (*game)->map[y][x];
	if (tile == 'C')
		(*game)->coins_credit--;
	return (tile == '0' || tile == 'C' || tile == 'E' || tile == 'X');
}

void	move_player(t_game **game, int new_x, int new_y)
{
	(*game)->map[(*game)->p_y_pos][(*game)->p_x_pos] = '0';
	(*game)->p_x_pos = new_x;
	(*game)->p_y_pos = new_y;
	(*game)->map[(*game)->p_y_pos][(*game)->p_x_pos] = 'P';
	(*game)->mouve_count++;
	ft_printf("Moves: %d\n", (*game)->mouve_count);
}

void	ft_move_player_utils(t_game **game, int new_x_p, int new_y_p)
{
	if ((*game)->map[new_y_p][new_x_p] == 'E')
	{
		if ((*game)->coins_credit == 0)
		{
			move_player(game, new_x_p, new_y_p);
			ft_render_map(game);
			ft_close(game);
		}
	}
	else if ((*game)->map[new_y_p][new_x_p] == 'X')
	{
		ft_printf("Game Over: You touched an enemy and lost!\n");
		ft_close(game);
	}
	else if ((*game)->map[new_y_p][new_x_p] != 'E')
	{
		move_player(game, new_x_p, new_y_p);
		ft_render_map(game);
	}
}

int	ft_move_player(int key_code, t_game **game)
{
	int	new_x_p;
	int	new_y_p;

	new_x_p = (*game)->p_x_pos;
	new_y_p = (*game)->p_y_pos;
	if (key_code == 65307)
	{
		ft_close(game);
	}
	else if (key_code == 119)
	{
		new_y_p--;
	}
	else if (key_code == 115)
		new_y_p++;
	else if (key_code == 97)
		new_x_p--;
	else if (key_code == 100)
		new_x_p++;
	if (is_valid_move(game, new_x_p, new_y_p))
		ft_move_player_utils(game, new_x_p, new_y_p);
	return (0);
}
