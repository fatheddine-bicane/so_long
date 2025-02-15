/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:48:14 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/15 11:24:10 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//this function checks if the map file passed is in correct format
void	ft_check_extansion(char *argv)
{
	int		i;

	i = ft_strlen(argv) - 4;
	if (ft_strncmp(argv + i, ".ber", 4))
		ft_throw_error_1(2, NULL);
}

//this is a utility function for ft_read_map();
void	ft_open(char *map_name, int *map_fd)
{
	(*map_fd) = open(map_name, O_RDONLY);
	if ((*map_fd) == -1)
		ft_throw_error_1(1, NULL);
}

//this function reads the map to char **map so i can work with it later
char	**ft_read_map(char *argv)
{
	char	**map;
	int		map_file;
	char	*map_lines;
	char	*lines_join;
	char	*lines_join_m;

	ft_open(argv, &map_file);
	map_lines = get_next_line(map_file);
	if (!map_lines || !*map_lines)
		return (close(map_file), NULL);
	lines_join = ft_strdup("");
	while (map_lines)
	{
		lines_join_m = lines_join;
		lines_join = ft_strjoin(lines_join, map_lines);
		free(lines_join_m);
		free(map_lines);
		map_lines = get_next_line(map_file);
	}
	get_next_line(-1);
	map = ft_split(lines_join, '\n');
	free(lines_join);
	return (map);
}

//this function checks if the map is rectangular
void	ft_check_map_valid(char **map)
{
	int	len;
	int	i;

	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (len != (int)ft_strlen(map[i]))
			ft_throw_error_1(3, map);
		i++;
	}
}

//this function cheks if the map is well surounded by walls ('1')
void	ft_map_walls(char **map)
{
	int	i;
	int	r;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
			ft_throw_error_1(4, map);
		i++;
	}
	i = 1;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			ft_throw_error_1(4, map);
		i++;
	}
	r = i - 1;
	i = 0;
	while (map[r][i])
	{
		if (map[r][i] != '1')
			ft_throw_error_1(4, map);
		i++;
	}
}

//this function is a utility function for ft_map_components();
int	ft_map_components_utils(int *c_credit, int *p_credit,
							int *e_creadit, char *map_line)
{
	int	i;

	i = 0;
	while (map_line[i])
	{
		if (map_line[i] == 'P')
			(*p_credit) += 1;
		else if (map_line[i] == 'E')
			(*e_creadit) += 1;
		else if (map_line[i] == 'C')
			(*c_credit) += 1;
		else if (map_line[i] != '1' && map_line[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

//this is a function that cheks for the components of the map(P, C, E, 1, 0)
void	ft_map_components(char **map)
{
	int	i;
	int	r;
	int	c_credit;
	int	p_credit;
	int	e_credit;
	int	check;

	i = 0;
	r = 0;
	c_credit = 0;
	p_credit = 0;
	e_credit = 0;
	while (map[r])
	{
		check = ft_map_components_utils(&c_credit, &p_credit, &e_credit, map[r]);
		if (!check)
			ft_throw_error_2(5, NULL, map);
		r++;
	}
	if (c_credit < 1)
		ft_throw_error_2(5, NULL, map);
	if (p_credit != 1 || e_credit != 1)
		ft_throw_error_2(5, NULL, map);
}

//this function uses all the map utility functions to initialize the map
char	**ft_parce_map(char *argv)
{
	char	**map;

	ft_check_extansion(argv);
	map = ft_read_map(argv);
	if (!map)
		ft_throw_error_1(6, NULL);
	ft_check_map_valid(map);
	ft_map_walls(map);
	ft_map_components(map);
	return (map);
}
