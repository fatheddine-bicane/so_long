/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:29:18 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/25 16:03:10 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "../librarys/my_library/my_library.h"

# define TILE_SIZE 32

//struct for the game component
typedef struct s_comp_credit
{
	int	coin_credit;
	int	player_credit;
	int	exit_credit;
}	t_comp_credit;

typedef struct s_game
{
	char	**map;
	int		p_x_pos;
	int		p_y_pos;
	int		rows_count;
	int		indexes_count;
	int		coins_credit;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*ground;
	int		height;
	void	*trees;
	void	*boarder[3];
	int		width;
	void	*door;
	void	*idle;
	void	*coin;
	int		ignore_exit;
	int		mouve_count;
}	t_game;

//map parsing functions
void	ft_parce_map(char *argv, t_game **game);
char	**ft_read_map(char *argv, t_game **game);
void	ft_check_extansion(char *argv, t_game **game);
void	ft_check_map_valid(t_game **game);
void	ft_map_walls(t_game **game);
void	ft_flood_fill(t_game *game, char ***map_copy, int p_x_pos, int p_y_pos);
void	ft_set_p_position(t_game **game);
void	ft_check_points(t_game **game, char *argv);
void	ft_map_components(t_game **game);

//error handling functions
void	ft_free(char **arr_s);
void	ft_free_game(t_game **game);
void	ft_free_game_2(t_game **game);
void	ft_throw_error_1(int error, t_game **game);
void	ft_throw_error_2(int error, t_game **game);

//window managent
void	ft_open_win(t_game **game);
void	ft_render_map(t_game **game);

int		ft_move_player(int key_code, t_game **game);
int		ft_close(t_game **game);
void	ft_load_ground(t_game **game);
int		pick_tree(void);

#endif
