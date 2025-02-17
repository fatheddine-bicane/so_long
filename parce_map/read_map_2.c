/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:47:30 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/16 16:47:59 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//this function is a utility function for ft_map_components();
int	ft_map_components_utils(t_comp_credit *comp_credit, char *map_line)
{
	int	i;

	i = 0;
	while (map_line[i])
	{
		if (map_line[i] == 'P')
			comp_credit->player_credit += 1;
		else if (map_line[i] == 'E')
			comp_credit->exit_credit += 1;
		else if (map_line[i] == 'C')
			comp_credit->coin_credit += 1;
		else if (map_line[i] == 'X')
			comp_credit->enemies_credit += 1;
		else if (map_line[i] != '1' && map_line[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

//this is a function that cheks for the components of the map(P, C, E, 1, 0)
void	ft_map_components(char **map)
{
	int				i;
	int				r;
	int				check;
	t_comp_credit	comp_credit;

	i = 0;
	r = 0;
	comp_credit.coin_credit = 0;
	comp_credit.player_credit = 0;
	comp_credit.exit_credit = 0;
	comp_credit.enemies_credit = 0;
	while (map[r])
	{
		check = ft_map_components_utils(&comp_credit, map[r]);
		if (!check)
			ft_throw_error_2(5, NULL, map);
		r++;
	}
	if (comp_credit.coin_credit < 1)
		ft_throw_error_2(5, NULL, map);
	if (comp_credit.enemies_credit < 1)
		ft_throw_error_2(5, NULL, map);
	if (comp_credit.player_credit != 1 || comp_credit.exit_credit != 1)
		ft_throw_error_2(5, NULL, map);
}

//this function uses all the map utility functions to initialize the map
char	**ft_parce_map(char *argv)
{
	char	**map;
	t_game	*game;

	ft_check_extansion(argv);
	map = ft_read_map(argv);
	if (!map)
		ft_throw_error_1(6, NULL);
	ft_check_map_valid(map);
	ft_map_walls(map);
	ft_map_components(map);
	game = malloc(sizeof(t_game));
	if (!game)
		return (ft_free(map), NULL);
	game->map = map;
	/*ft_free(map);*/
	ft_set_P_position(&game);
	ft_check_points(&game);
	return (map);
}
