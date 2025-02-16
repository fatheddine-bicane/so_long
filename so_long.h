/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:29:18 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/16 22:52:21 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./librarys/minilibx-linux/mlx.h"
# include "./librarys/my_library/my_library.h"

//struct for the game component
typedef struct s_comp_credit
{
	int	coin_credit;
	int	player_credit;
	int	enemies_credit;
	int	exit_credit;
}	t_comp_credit;

typedef struct s_game
{
	char	**map;
	int		player_x_position;
	int		player_y_position;

}	t_game;

//map parsing functions
char	**ft_read_map(char *argv);
void	ft_check_extansion(char *argv);
char	**ft_parce_map(char *argv);
void	ft_check_map_valid(char **map);
void	ft_map_walls(char **map);

//error hamdling functions
void	ft_throw_error_1(int error, char **map);
void	ft_throw_error_2(int error, char *argv, char **map);
void	ft_free(char **arr_s);

#endif
