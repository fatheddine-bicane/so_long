/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:00:07 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/19 15:49:21 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//this function will check if the collectibles and the exit are all reachable
void	ft_check_points(t_game **game, char *argv)
{
	int		i;
	int		r;
	char	**map_copy;

	r = 0;
	map_copy = ft_read_map(argv, game);
	ft_flood_fill((*game), &map_copy, (*game)->p_x_pos, (*game)->p_y_pos);
	while (map_copy[r])
	{
		i = 0;
		while (map_copy[r][i])
		{
			if (map_copy[r][i] == 'E' || map_copy[r][i] == 'C')
			{
				ft_free(map_copy);
				ft_throw_error_2(7, game);
			}
			i++;
		}
		r++;
	}
	ft_free(map_copy);
}

//this function will set the player position and the number of rows and indexes
void	ft_set_p_position(t_game **game)
{
	int	i;
	int	r;

	r = 0;
	while ((*game)->map[r])
	{
		i = 0;
		while ((*game)->map[r][i])
		{
			if ((*game)->map[r][i] == 'P')
			{
				(*game)->p_x_pos = i;
				(*game)->p_y_pos = r;
			}
			i++;
		}
		r++;
	}
	(*game)->rows_count = r;
	(*game)->indexes_count = i;
}

void	ft_flood_fill(t_game *game, char ***map_copy, int p_x_pos, int p_y_pos)
{
	if (p_x_pos >= game->rows_count || p_y_pos >= game->indexes_count
		|| p_x_pos < 0 || p_y_pos < 0)
		return ;
	if ((*map_copy)[p_x_pos][p_y_pos] == '.' ||
		(*map_copy)[p_x_pos][p_y_pos] == '1' ||
		(*map_copy)[p_x_pos][p_y_pos] == 'X')
		return ;
	(*map_copy)[p_x_pos][p_y_pos] = '.';
	ft_flood_fill(game, map_copy, p_x_pos + 1, p_y_pos);
	ft_flood_fill(game, map_copy, p_x_pos - 1, p_y_pos);
	ft_flood_fill(game, map_copy, p_x_pos, p_y_pos + 1);
	ft_flood_fill(game, map_copy, p_x_pos, p_y_pos - 1);
}
