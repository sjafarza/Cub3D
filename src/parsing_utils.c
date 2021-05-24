/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saray <saray.jafarzade@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 23:44:36 by saray             #+#    #+#             */
/*   Updated: 2021/04/23 08:07:47 by saray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_strlen2(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '.')
		i++;
	while (s[i])
	{
		i++;
		j++;
	}
	return (j);
}

int	ft_charinstr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_depart(char c, t_recup *recup, int i, int j)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (recup->depart != 'x')
			recup->multiplayers = 1;
		recup->depart = c;
		recup->dx = i;
		recup->dy = j;
		return (1);
	}
	return (0);
}

int	ft_murs_util(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

void	ft_init(t_recup *recup)
{
	recup->rx = 0;
	recup->ry = 0;
	recup->i = 0;
	recup->f = -1;
	recup->c = -1;
	recup->no = NULL;
	recup->so = NULL;
	recup->we = NULL;
	recup->ea = NULL;
	recup->sp = NULL;
	recup->nblines = 0;
	recup->sizeline = 0;
	recup->map = NULL;
	recup->dx = 0;
	recup->dy = 0;
	recup->multiplayers = 0;
	recup->linevide = 0;
	recup->insidemap = 0;
	recup->count = 0;
	recup->sum = 0;
	recup->wrongcharmap = 0;
	ft_init_more(recup);
}
