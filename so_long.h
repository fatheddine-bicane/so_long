/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:29:18 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/15 11:10:32 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx.h"
# include "./my_library/my_library.h"


//map parsing functions
char	**ft_read_map(char *argv);
void	ft_check_extansion(char *argv);
char	**ft_parce_map(char *argv);

//error hamdling functions
void	ft_throw_error_1(int error, char **map);
void	ft_throw_error_2(int error, char *argv, char **map);
void	ft_free(char **arr_s);

#endif
