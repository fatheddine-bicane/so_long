/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:49:27 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/15 10:32:19 by fbicane          ###   ########.fr       */
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

void	ft_free_game(t_game **game)
{
	if ((*game)->map)
		ft_free((*game)->map);
	free(*game);
	(*game) = NULL;
}

void	ft_throw_error_1(int error, char **map)
{
	if (error == 1)
		ft_perror("Error: Open system call faild\n");
	else if (error == 2)
	{
		ft_perror("Error: Wrong file format detected.");
		ft_perror(" Required format: *.ber (example: map.ber)\n");
	}
	else if (error == 3)
	{
		ft_perror("Error: Map is not rectangular! ");
		ft_perror("All rows must have the same length\n");
		ft_free(map);
	}
	else if (error == 4)
	{
		ft_perror("Error: Map must be surrounded by walls ('1')\n");
		ft_free(map);
	}
	else if (error == 6)
		ft_perror("Error: Cannot load map - Empty file detected\n");
	exit(1);
}

void	ft_throw_error_2(int error, t_game **game, char **map)
{
	if (error == 5)
	{
		ft_perror("Error: Invalid map components!\n");
		ft_perror("Required: At least 1 coin (C), exactly 1");
		ft_perror("player (P), and exactly 1 exit (E)\n");
		ft_free(map);
	}
	if (error == 7)
	{
		ft_perror("Error: Ensure there are valid paths ");
		ft_perror("to all collectibles and the exit\n");
		ft_free_game(game);
	}
	exit(1);
}
