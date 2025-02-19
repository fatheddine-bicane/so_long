/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:37:52 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/19 15:50:43 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_game(t_game **game)
{
	if ((*game)->map)
		ft_free((*game)->map);
	free(*game);
	(*game) = NULL;
}
