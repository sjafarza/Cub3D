/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saray <saray.jafarzade@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 20:29:47 by saray             #+#    #+#             */
/*   Updated: 2021/04/28 08:24:01 by saray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_parsing_map(char *fichier, t_recup *recup)
{
	int		fd;
	int		r;
	char	*line;

	r = 1;
	if (!ft_del5(&line, &fd, &fichier, recup))
		return (0);
	while (r != 0)
	{
		r = get_next_line(fd, &line, recup);
		if (recup->insidemap == 1 && ft_linevide(line) == 0 \
					&& recup->count < recup->nblines)
			recup->linevide = 1;
		recup->insidemap = ft_is_map(line, recup);
		if (recup->insidemap == 1)
		{
			recup->count++;
			ft_copy_map(line, recup);
		}
		free(line);
	}
	close(fd);
	ft_init_sprite(recup);
	return (0);
}

void	ft_parsing(char *fichier, t_recup *recup)
{
	int		r;
	int		fd;
	char	*line;

	r = 1;
	line = NULL;
	ft_del5_parsing(&line, &fd, &fichier, recup);
	recup->erreur = 0;
	while (r != 0)
	{
		r = get_next_line(fd, &line, recup);
		if (recup->erreur == 2)
			ft_error(recup, "There is un error in parsing\n");
		ft_color_resolution(&line, recup, r);
		ft_texture(line, recup);
		ft_map(line, recup, r);
		free(line);
	}
	close(fd);
	if (recup->sizeline == 0 || recup->nblines == 0)
		ft_error(recup, "Map is  absent\n");
	ft_parsing_map(fichier, recup);
}

int	ft_cub(char *str, t_recup *recup)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (str[i] != '.')
	{
		--i;
		if (i == 0)
		{
			ft_error(recup, "Name of map is invalide\n");
			return (0);
		}
	}
	if (str[i + 1] == 'c' && str[i + 2] == 'u' && str[i + 3] == 'b')
		ft_parsing(str, recup);
	else
		ft_error(recup, "Name of map is invalide\n");
	return (0);
}

int	main(int ac, char **av)
{
	t_recup		recup;

	recup.save = 0;
	ft_init(&recup);
	if (ac == 2 || (ac == 3 && ft_chek_save(av[2]) == 1))
	{
		if (ac == 3)
			recup.save = 1;
		ft_cub(av[1], &recup);
	}
	else
		write(1, "Error\nArguments invalides\n", 30);
	return (0);
}
