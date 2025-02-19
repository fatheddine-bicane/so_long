/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:41:56 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/19 12:34:26 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*background;
	int		height;
	int		width;

	/*(void)mlx_win;*/
	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 12 * 32, 5 * 32, "so_long");
	background = mlx_xpm_file_to_image(mlx_ptr, "./sprites/background_town1.xpm", &width, &height);
	mlx_put_image_to_window(mlx_ptr, mlx_win, background, 0, 0);
	mlx_loop(mlx_ptr);
}
