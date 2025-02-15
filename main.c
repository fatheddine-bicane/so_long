/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:22:42 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/15 11:11:15 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	int		i;

	(void)argc;
	map = ft_parce_map(argv[1]);
	i = 0;
	while (map[i])
	{
		ft_printf(map[i]);
		ft_printf("\n");
		i++;
	}
	ft_free(map);
}
