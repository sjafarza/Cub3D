/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saray <saray.jafarzade@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:51:06 by saray             #+#    #+#             */
/*   Updated: 2021/04/23 08:05:07 by saray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_murs(t_recup *recup)
{
	int	i;

	i = 0;
	while (i < recup->nblines)
	{
		if (recup->map[i][0] != '1')
			return (1);
		i++;
	}
	if (ft_murs_util(recup->map[0]) == 1)
		return (1);
	if (ft_murs_util(recup->map[recup->nblines - 1]) == 1)
		return (1);
	return (0);
}

int	ft_copy_map(char *str, t_recup *recup)
{
	static int	i;
	int			j;

	i = recup->count - 1;
	j = -1;
	recup->map[i] = NULL;
	recup->map[i] = malloc(sizeof(char) * recup->sizeline + 1);
	if (!recup->map[i])
		return (0);
	while (str[++j])
	{
		if (ft_depart(str[j], recup, i, j) == 1)
			recup->map[i][j] = '0';
		else if (str[j] == ' ')
			recup->map[i][j] = '1';
		else
			recup->map[i][j] = str[j];
	}
	while (j <= (recup->sizeline - 1))
		recup->map[i][j++] = '1';
	recup->map[i][j] = '\0';
	i++;
	return (0);
}

int	ft_is_map(char *str, t_recup *recup)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (ft_charinstr(str, '1') == 1 || ft_charinstr(str, '0') == 1)
	{
		while (str[i])
		{
			if (str[i] != ' ' && str[i] != '0' && str[i] != '1' \
					&& str[i] != '2' && str[i] != 'N' && str[i] \
					!= 'S' && str[i] != 'E' && str[i] != 'W' \
					&& str[i] != '\t' && str[i] != '\n')
			{
				if (recup->insidemap == 1)
					recup->wrongcharmap = 2;
				return (0);
			}
			i++;
		}
		return (1);
	}
	return (0);
}

void	ft_map(char *str, t_recup *recup, int r)
{
	int			i;
	static int	snblines;
	static int	ssizeline;

	i = 0;
	if (ft_is_map(str, recup) == 1)
	{
		if (recup->f == -1 || recup->c == -1 || recup->no == NULL \
			|| recup->so == NULL || recup->we == NULL || \
			recup->ea == NULL || recup->sp == NULL)
			if (r == 0)
				recup->erreur = 2;
		i = ft_strlen(str);
		if (i > ssizeline)
			ssizeline = i;
		snblines = snblines + 1;
	}
	recup->nblines = snblines;
	recup->sizeline = ssizeline;
}
