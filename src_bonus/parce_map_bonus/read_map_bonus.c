/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:44:06 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/25 15:44:38 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_parce_map(char *argv, t_game **game)
{
	ft_check_extansion(argv, game);
	(*game)->map = ft_read_map(argv, game);
	if (!(*game)->map)
		ft_throw_error_1(6, game);
	ft_check_map_valid(game);
	ft_map_walls(game);
	ft_map_components(game);
	ft_set_p_position(game);
	ft_check_points(game, argv);
	(*game)->mouve_count = 0;
}
