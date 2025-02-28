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

#include "so_long_bonus.h"

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
	t_game	*game;

	(void)argc;
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	ft_parce_map(argv[1], &game);
	ft_open_win(&game);
}
