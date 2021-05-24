/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saray <saray.jafarzade@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 00:16:47 by saray             #+#    #+#             */
/*   Updated: 2021/04/22 11:27:31 by saray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_init_more(t_recup *recup)
{
	recup->depart = 'x';
	recup->indicateur2 = 0;
	recup->indicateur3 = 0;
	recup->data.img = NULL;
	recup->texture[0].img = NULL;
	recup->texture[1].img = NULL;
	recup->texture[2].img = NULL;
	recup->texture[3].img = NULL;
	recup->texture[4].img = NULL;
	recup->data.mlx_win = NULL;
	recup->map = NULL;
	recup->s.order = NULL;
	recup->s.dist = NULL;
	recup->s.zbuffer = NULL;
	recup->sxy = NULL;
}

void	ft_init_dir(t_recup *recup)
{
	if (recup->depart == 'N')
		recup->ray.dirx = -1;
	if (recup->depart == 'S')
		recup->ray.dirx = 1;
	if (recup->depart == 'E')
		recup->ray.diry = 1;
	if (recup->depart == 'W')
		recup->ray.diry = -1;
	if (recup->depart == 'N')
		recup->ray.plany = 0.66;
	if (recup->depart == 'S')
		recup->ray.plany = -0.66;
	if (recup->depart == 'E')
		recup->ray.planx = 0.66;
	if (recup->depart == 'W')
		recup->ray.planx = -0.66;
}

void	ft_init_more3(t_recup *recup)
{
	if (recup->ray.raydiry == 0)
		recup->ray.deltadistx = 0;
	else if (recup->ray.raydirx == 0)
		recup->ray.deltadistx = 1;
	else
		recup->ray.deltadistx = sqrt(1 \
			+ (recup->ray.raydiry * \
			recup->ray.raydiry) / (recup->\
			ray.raydirx * recup->ray.raydirx));
	if (recup->ray.raydirx == 0)
		recup->ray.deltadisty = 0;
	else if (recup->ray.raydiry == 0)
		recup->ray.deltadisty = 1;
	else
		recup->ray.deltadisty = sqrt(1 + (recup->\
		ray.raydirx * recup->ray.raydirx) / (\
		recup->ray.raydiry * recup->ray.raydiry));
}

void	ft_atoi3_check(const char *str, t_recup *recup)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != ',')
		i++;
	if (str[i] == ',')
		j = 1;
	i++;
	while (str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while ((str[i] < '0' || str[i] > '9') && str[i])
	{
		if (str[i] == ',')
			j++;
		i++;
	}
	if (j != 2)
		recup->erreur = 2;
	if (ft_nb_virgule(str) != 2)
		recup->erreur = 2;
}

int	ft_linevide(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '\t' && s[i] != ' ' \
		&& s[i] != '\0' && s[i] != '\n' \
		&& s[i] != '\r' && s[i] != '\v' \
		&& s[i] != '\f')
			return (1);
		i++;
	}
	return (0);
}
