/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvment.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:12:51 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/24 17:26:20 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	is_valid_move(t_game **game, int x, int y)
{
	char	tile;

	if (x < 0 || y < 0 || x >= (*game)->indexes_count || y >= (*game)->rows_count)
		return (0);
	tile = (*game)->map[y][x];
	if (tile == 'C')
	{
		(*game)->coins_credit--;
		/*return ()*/
	}
	return (tile == '0' || tile == 'C' || tile == 'E' || tile == 'X');
}

void	move_player(t_game **game, int new_x, int new_y)
{
	/*data->count_move++;*/
	(*game)->map[(*game)->P_y_pos][(*game)->P_x_pos] = '0';
	(*game)->P_x_pos = new_x;
	(*game)->P_y_pos = new_y;
	(*game)->map[(*game)->P_y_pos][(*game)->P_x_pos] = 'P';
	(*game)->mouve_count++;
	ft_printf("Moves: %d\n", (*game)->mouve_count);
}

int	ft_move_player(int key_code, t_game **game)
{
	int	new_x_p;
	int	new_y_p;

	new_x_p = (*game)->P_x_pos;
	new_y_p = (*game)->P_y_pos;
	
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
		else if ((*game)->map[new_y_p][new_x_p] != 'E')
		{
			move_player(game, new_x_p, new_y_p);
			ft_render_map(game);
		}
	}
	return (0);
}



/*int	ft_move_player(int key_code, t_game **game)*/
/*{*/
/*	int	new_x_p;*/
/*	int	new_y_p;*/
/**/
/*	new_x_p = (*game)->P_x_pos;*/
/*	new_y_p = (*game)->P_y_pos;*/
/*	if (key_code == 119)*/
/*		(*game)->P_y_pos--;*/
/*	else if (key_code == 115)*/
/*		(*game)->P_y_pos++;*/
/*	else if (key_code == 97)*/
/*		(*game)->P_x_pos--;*/
/*	else if (key_code == 100)*/
/*		(*game)->P_x_pos++;*/
/*	if (!is_valid_move(game, new_x_p, new_y_p))*/
/*	{*/
/*		printf("dkhl hna\n");*/
/*		move_player(game, new_x_p, new_y_p);*/
/*		ft_render_map(game);*/
/*	}*/
/*	return (0);*/
/*}*/
