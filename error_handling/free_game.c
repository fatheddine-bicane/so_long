/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:37:52 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/25 16:14:01 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_game(t_game **game)
{
	int i = 0;

	if ((*game)->map)
		ft_free((*game)->map);
	if ((*game)->door)
		mlx_destroy_image((*game)->mlx_ptr, (*game)->door);
	if ((*game)->idle)
		mlx_destroy_image((*game)->mlx_ptr, (*game)->idle);
	if ((*game)->coin)
		mlx_destroy_image((*game)->mlx_ptr, (*game)->coin);
	while(i < 2)
	{
		if ((*game)->trees[i])
			mlx_destroy_image((*game)->mlx_ptr, (*game)->trees[i]);
		i++;
	}
	mlx_clear_window((*game)->mlx_ptr, (*game)->win_ptr);
	mlx_destroy_window((*game)->mlx_ptr, (*game)->win_ptr);
	mlx_destroy_display((*game)->mlx_ptr);
	free((*game)->mlx_ptr);
	/*if ((*game)->mlx_ptr)*/
	/*	free((*game)->mlx_ptr);*/
	/*if ((*game)->win_ptr)*/
	/*	free((*game)->win_ptr);*/
	free(*game);
	(*game) = NULL;
}
 /*mlx_destroy_image((*game)->mlx_ptr, (*game)->ground[i]);*/
