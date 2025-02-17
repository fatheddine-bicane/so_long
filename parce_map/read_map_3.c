/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:00:07 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/16 22:52:25 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//this function will check if the collectibles and the exit are all reachable
void	ft_check_points(t_game **game)
{
	int	i;
	int	r;
	char	**map_copy;

	i = 0;
	r = 0;
	map_copy = (*game)->map;
	ft_flood_fill((*game), &map_copy, (*game)->P_x_pos, (*game)->P_y_pos);
	while (map_copy[r])
	{
		while (map_copy[r][i])
		{
			if (map_copy[r][i] != '1' && map_copy[r][i] != '.')
				ft_throw_error_2(7, game, NULL);
			i++;
		}
		r++;
	}
}

//this function will set the player position and the number of rows and indexes
void	ft_set_P_position(t_game **game)
{
	int	i;
	int	r;

	i = 0;
	r = 1;

	while ((*game)->map[r])
	{
		while ((*game)->map[r][i])
		{
			if ((*game)->map[r][i] == 'P')
			{
				(*game)->P_x_pos = r;
				(*game)->P_y_pos = i;
			}
			i++;
		}
		r++;
	}
	(*game)->rows_count = r - 1;
	(*game)->indexes_count = i - 1;
}

/*void	ft_E_C_accebile(t_game **game)*/
/*{*/
/*	char	**map_copy;*/
/**/
/*	map_copy = (*game)->map;*/
/*	ft_flood_fill((*game), &map_copy, (*game)->P_x_pos, (*game)->P_y_pos);*/
/*	ft_check_points()*/
/*}*/

void	ft_flood_fill(t_game *game, char ***map_copy, int p_x_pos, int p_y_pos)
{
	/*printf("HELLO");*/
	 if (p_x_pos > game->rows_count || p_y_pos > game->indexes_count
		|| p_x_pos < 0 || p_y_pos < 0)
		return ;
	if ((*map_copy)[p_x_pos][p_y_pos] == '.' || (*map_copy)[p_x_pos][p_y_pos] == '1')
		return ;
	(*map_copy)[p_x_pos][p_y_pos] = '.';
	ft_flood_fill(game, map_copy, p_x_pos + 1, p_y_pos);
	ft_flood_fill(game, map_copy, p_x_pos - 1, p_y_pos);
	ft_flood_fill(game, map_copy, p_x_pos, p_y_pos + 1);
	ft_flood_fill(game, map_copy, p_x_pos, p_y_pos - 1);
}
