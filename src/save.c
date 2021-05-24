/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saray <saray.jafarzade@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 00:04:25 by saray             #+#    #+#             */
/*   Updated: 2021/04/28 08:37:55 by saray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_header(t_recup *recup, int fd)
{
	int	tmp;

	write(fd, "BM", 2);
	tmp = 14 + 40 + 4 * recup->rx * recup->ry;
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 2);
	write(fd, &tmp, 2);
	tmp = 54;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	write(fd, &recup->rx, 4);
	write(fd, &recup->ry, 4);
	tmp = 1;
	write(fd, &tmp, 2);
	write(fd, &recup->data.bits_per_pixel, 2);
	tmp = 0;
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
}

int	ft_chek_save(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] == 'e' && str[i - 2] == 'v' && \
		str[i - 3] == 'a' && str[i - 4] == 's' \
		&& str[i - 5] == '-' && str[i - 6] == \
		'-' && (i < 7))
		return (1);
	else
		return (0);
}

void	ft_save(t_recup *recup)
{
	int	fd;
	int	x;
	int	y;

	y = recup->ry;
	fd = open("./image.bmp", O_CREAT | O_RDWR);
	if (fd == -1)
		ft_error(recup, "impossible de creer .bmp\n");
	ft_header(recup, fd);
	while (y >= 0)
	{
		x = 0;
		while (x < recup->rx)
		{
			write(fd, &recup->data.addr[y * \
			recup->data.line_length / 4 + x], 4);
			x++;
		}
		y--;
	}
	system("chmod 777 image.bmp");
	ft_error(recup, "No, any error. --save ok \n");
}

int	ft_nb_virgule(const char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == ',')
			j++;
	}
	return (j);
}
