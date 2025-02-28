/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enem_mouvment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:59:56 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/28 16:01:13 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	ft_enem_utils_1(char **mp, int *dr, int *i, int *r)
{
	if (mp[(*r)][(*i)] == 'X' && mp[(*r)][(*i) + 1] == 'P' && (*dr) == 1)
	{
		ft_printf("Game Over: You touched an enemy and lost!\n");
		(*dr) = 3;
		return ;
	}
	if (mp[(*r)][(*i)] == 'X' && mp[(*r)][(*i) + 1] == '0' && (*dr) == 1)
	{
		(*dr) = +1;
		mp[(*r)][(*i)] = '0';
		mp[(*r)][(*i) + 1] = 'X';
		(*i) += 2;
		(*dr) = 5;
		return ;
	}
	if (mp[(*r)][(*i)] == 'X')
		(*dr) = -1;
}

static void	ft_enem_utils_2(char **mp, int *dr, int *i, int *r)
{
	if (mp[(*r)][(*i)] == 'X' && mp[(*r)][(*i) - 1] == 'P' && (*dr) == 1)
	{
		ft_printf("Game Over: You touched an enemy and lost!\n");
		(*dr) = 3;
		return ;
	}
	if (mp[(*r)][(*i)] == 'X' && mp[(*r)][(*i) - 1] == '0' && (*dr) == -1)
	{
		(*dr) = -1;
		mp[(*r)][(*i)] = '0';
		mp[(*r)][(*i) - 1] = 'X';
		(*i)++;
		(*dr) = 5;
		return ;
	}
	if (mp[(*r)][(*i)] == 'X')
		(*dr) = +1;
}

static void	ft_move_enem_utils(char **mp, int *dr, int *i, int *r)
{
	(*i) = 0;
	while (mp[(*r)][(*i)])
	{
		ft_enem_utils_1(mp, dr, i, r);
		if ((*dr) == 3)
			return ;
		if ((*dr) == 5)
		{
			(*dr) = 1;
			continue ;
		}
		ft_enem_utils_2(mp, dr, i, r);
		if ((*dr) == 3)
			return ;
		if ((*dr) == 5)
		{
			(*dr) = 1;
			continue ;
		}
		(*i)++;
	}
}

void	ft_move_enem(t_game **game)
{
	int			i;
	int			r;
	static int	direction = 1;
	static int	delay;
	char		**mp;

	delay++;
	mp = (*game)->map;
	if (delay % 100 == 0)
	{
		delay = 0;
		r = 0;
		while (mp[r])
		{
			ft_move_enem_utils(mp, &direction, &i, &r);
			if (direction == 3)
				ft_close(game);
			r++;
		}
	}
}
