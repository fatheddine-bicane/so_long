/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:22:42 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/19 15:47:18 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_file(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_throw_error_1(1, NULL);
	close(fd);
}

int	main(int argc, char **argv)
{
	/*char	**map;*/
	/*int		i;*/
	t_game	*game;

	(void)argc;
	/*ft_check_file(argv[1]);*/
	game = malloc(sizeof(t_game));
	if (!game)
		return(1);
	ft_parce_map(argv[1], &game);
	ft_open_win(&game);
	/*i = 0;*/
	/*while (game->map[i])*/
	/*{*/
	/*	ft_printf(game->map[i]);*/
	/*	ft_printf("\n");*/
	/*	i++;*/
	/*}*/
	/*ft_free_game(&game);*/
	/*printf("\n\n\n\n\n\n\n\n\n");*/
	/*char	**map_copy = map;*/
	/*ft_flood_fill(game, &map_copy, 3, 1);*/
	/*i = 0;*/
	/*while (map[i])*/
	/*{*/
	/*	ft_printf(map[i]);*/
	/*	ft_printf("\n");*/
	/*	i++;*/
	/*}*/
	/////////////////////////
	/*game = malloc(sizeof(t_game*));*/
	/*if (!game)*/
	/*	return (1);*/
	/*map = ft_parce_map(argv[1], &game);*/
	/*i = 0;*/
	/*while (map[i])*/
	/*{*/
	/*	ft_printf(map[i]);*/
	/*	ft_printf("\n");*/
	/*	i++;*/
	/*}*/
	/*ft_free(map);*/
	/*printf("\n\n\n\n\n\n%d", game->P_y_pos);*/
}
