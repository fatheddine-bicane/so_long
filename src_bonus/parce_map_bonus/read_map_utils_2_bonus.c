/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:47:30 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/25 15:47:56 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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

void	ft_map_components(t_game **game)
{
	int				r;
	int				check;
	t_comp_credit	comp_credit;

	r = 0;
	comp_credit.coin_credit = 0;
	comp_credit.player_credit = 0;
	comp_credit.exit_credit = 0;
	comp_credit.enemies_credit = 0;
	while ((*game)->map[r])
	{
		check = ft_map_components_utils(&comp_credit, (*game)->map[r]);
		if (!check)
			ft_throw_error_2(5, game);
		r++;
	}
	if (comp_credit.coin_credit < 1)
		ft_throw_error_2(5, game);
	if (comp_credit.enemies_credit < 1)
		ft_throw_error_2(5, game);
	if (comp_credit.player_credit != 1 || comp_credit.exit_credit != 1)
		ft_throw_error_2(5, game);
	(*game)->coins_credit = comp_credit.coin_credit;
}
