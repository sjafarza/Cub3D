/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saray <saray.jafarzade@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 10:56:19 by saray             #+#    #+#             */
/*   Updated: 2021/05/03 14:40:04 by saray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_verify_errors(t_recup *recup)
{
	if (ft_murs(recup) == 1)
		ft_error(recup, "Map non entouree de 1\n");
	if (recup->depart == 'x')
		ft_error(recup, "pas de joueur\n");
	if (recup->indicateur2 != 6)
		ft_error(recup, "Mauvaises donnees F ou C\n");
	if (recup->multiplayers == 1)
		ft_error(recup, "plus d'un player\n");
	if (recup->linevide == 1)
		ft_error(recup, "There is empty line in map\n");
	if (recup->wrongcharmap == 2)
		ft_error(recup, "Bad Caractere in map\n");
}

void	ft_error2(t_recup *recup)
{
	if (recup->map)
		free(recup->map);
	if (recup->s.order)
		free(recup->s.order);
	if (recup->s.dist)
		free(recup->s.dist);
	if (recup->sxy)
		free(recup->sxy);
	if (recup->s.zbuffer)
		free(recup->s.zbuffer);
	ft_exit(recup);
}

void	ft_error(t_recup *recup, char *str)
{
	int	i;

	i = -1;
	recup->indicateur3 = 1;
	write(1, "Error\n", 6);
	write(1, str, ft_strlen(str));
	if (recup->no)
		free(recup->no);
	if (recup->so)
		free(recup->so);
	if (recup->we)
		free(recup->we);
	if (recup->ea)
		free(recup->ea);
	if (recup->sp)
		free(recup->sp);
	if (recup->map)
	{
		while (++i < recup->nblines)
			free(recup->map[i]);
	}
	ft_error2(recup);
}

int	ft_exit(t_recup *recup)
{
	if (recup->indicateur3 == 0)
		ft_error(recup, "No, it's ok\n");
	if (recup->data.img)
		mlx_destroy_image(recup->data.mlx_ptr, recup->data.img);
	if (recup->data.img2 && recup->save != 1 && ft_chek_img(recup))
		mlx_destroy_image(recup->data.mlx_ptr, recup->data.img2);
	if (recup->texture[0].img)
		mlx_destroy_image(recup->data.mlx_ptr, recup->texture[0].img);
	if (recup->texture[1].img)
		mlx_destroy_image(recup->data.mlx_ptr, recup->texture[1].img);
	if (recup->texture[2].img)
		mlx_destroy_image(recup->data.mlx_ptr, recup->texture[2].img);
	if (recup->texture[3].img)
		mlx_destroy_image(recup->data.mlx_ptr, recup->texture[3].img);
	if (recup->texture[4].img)
		mlx_destroy_image(recup->data.mlx_ptr, recup->texture[4].img);
	if (recup->data.mlx_win)
		mlx_destroy_window(recup->data.mlx_ptr, recup->data.mlx_win);
	if (recup->data.mlx_ptr)
	{
		mlx_destroy_display(recup->data.mlx_ptr);
		free(recup->data.mlx_ptr);
	}	
	exit(0);
}
