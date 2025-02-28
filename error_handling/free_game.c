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

void	ft_free(char **arr_s)
{
	int	i;

	i = 0;
	if (!arr_s)
		return ;
	while (arr_s[i] != 0)
	{
		free(arr_s[i]);
		i++;
	}
	free (arr_s);
}

static void	ft_free_game_utils(t_game **game)
{
	if ((*game)->map)
		ft_free((*game)->map);
	if ((*game)->door)
		mlx_destroy_image((*game)->mlx_ptr, (*game)->door);
	if ((*game)->ground)
		mlx_destroy_image((*game)->mlx_ptr, (*game)->ground);
}

static void	ft_free_game_utils_2(t_game **game)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if ((*game)->boarder[i])
			mlx_destroy_image((*game)->mlx_ptr, (*game)->boarder[i]);
		i++;
	}
	mlx_clear_window((*game)->mlx_ptr, (*game)->win_ptr);
	mlx_destroy_window((*game)->mlx_ptr, (*game)->win_ptr);
	mlx_destroy_display((*game)->mlx_ptr);
	free((*game)->mlx_ptr);
	free(*game);
	(*game) = NULL;
}

void	ft_free_game(t_game **game)
{
	int	i;

	i = 0;
	ft_free_game_utils(game);
	if ((*game)->trees)
		mlx_destroy_image((*game)->mlx_ptr, (*game)->trees);
	if ((*game)->skeleton)
		mlx_destroy_image((*game)->mlx_ptr, (*game)->skeleton);
	if ((*game)->walo)
		mlx_destroy_image((*game)->mlx_ptr, (*game)->walo);
	while (i < 4)
	{
		if ((*game)->coin[i])
			mlx_destroy_image((*game)->mlx_ptr, (*game)->coin[i]);
		if ((*game)->idle_r[i])
			mlx_destroy_image((*game)->mlx_ptr, (*game)->idle_r[i]);
		i++;
	}
	ft_free_game_utils_2(game);
	/*i = 0;*/
	/*while (i < 3)*/
	/*{*/
	/*	if ((*game)->boarder[i])*/
	/*		mlx_destroy_image((*game)->mlx_ptr, (*game)->boarder[i]);*/
	/*	i++;*/
	/*}*/
	/*mlx_clear_window((*game)->mlx_ptr, (*game)->win_ptr);*/
	/*mlx_destroy_window((*game)->mlx_ptr, (*game)->win_ptr);*/
	/*mlx_destroy_display((*game)->mlx_ptr);*/
	/*free((*game)->mlx_ptr);*/
	/*free(*game);*/
	/*(*game) = NULL;*/
}

void	ft_free_game_2(t_game **game)
{
	if ((*game)->map)
		ft_free((*game)->map);
	free(*game);
	(*game) = NULL;
}
