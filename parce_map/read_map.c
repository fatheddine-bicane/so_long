/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:48:14 by fbicane           #+#    #+#             */
/*   Updated: 2025/02/16 16:50:40 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
