/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saray <saray.jafarzade@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:38:35 by saray             #+#    #+#             */
/*   Updated: 2021/05/03 15:20:33 by saray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_chek_img(t_recup *recup)
{
	if (recup->texture[0].img && recup->texture[1].img && recup->texture[2].img \
	&& recup->texture[3].img && recup->texture[4].img)
		return (1);
	else
		return (0);
}

int	ft_del5(char **line, int *fd, char **fichier, t_recup *recup)
{
	*line = NULL;
	*fd = open(*fichier, O_RDONLY);
	recup->map = malloc(sizeof(char *) * recup->nblines);
	if (!recup->map)
		return (0);
	return (1);
}

void	ft_del5_parsing(char **line, int *fd, char **fichier, t_recup *recup)
{
	*line = NULL;
	*fd = open(*fichier, O_DIRECTORY);
	if (*fd != -1)
		ft_error(recup, "Directory is invalide\n");
	*fd = open(*fichier, O_RDONLY);
	if (*fd == -1)
		ft_error(recup, "foder .cub is invalide\n");
}

void	ft_norm3_init_r(t_recup *recup)
{
	if (recup->rx > recup->screenx)
		recup->rx = recup->screenx;
	if (recup->ry > recup->screeny)
		recup->ry = recup->screeny;
}

void	ft_norm3_s(t_recup *recup)
{
	recup->sxy = (t_sprxy *)malloc(sizeof(t_sprxy) * recup->s.nbspr);
	if (!recup->sxy)
		ft_error(recup, "Malloc sxy*");
	recup->s.order = (int *)malloc(sizeof(int) * recup->s.nbspr);
	if (!recup->s.order)
		ft_error(recup, "Mallloc s.order*");
	recup->s.dist = (double *)malloc(sizeof(double) * recup->s.nbspr);
	if (!recup->s.dist)
		ft_error(recup, "Malloc s.dist*");
}
