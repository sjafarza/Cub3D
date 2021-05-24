/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color_resolution_texture.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saray <saray.jafarzade@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 06:31:27 by saray             #+#    #+#             */
/*   Updated: 2021/04/23 07:40:16 by saray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_atoi2(const char *s, t_recup *recup)
{
	int	sum;

	sum = 0;
	if (s[1] != ' ' || ft_charinstr((char *)s, ',') == 1)
		recup->erreur = 2;
	while (s[recup->i] == ' ' || s[recup->i] == '\t' || \
			s[recup->i] == ',' || s[recup->i] == '\n' \
			|| s[recup->i] == '\r' || s[recup->i] == \
			'\v' || s[recup->i] == '\f' || s[recup->i] == 'R')
		recup->i++;
	if (s[recup->i] == '-' || s[recup->i] == '+')
		recup->erreur = 2;
	while (s[recup->i] >= '0' && s[recup->i] <= '9')
	{
		if (sum > 21474636)
			break ;
		sum = (sum * 10) + (s[recup->i] - '0');
		recup->i++;
	}
	while (s[recup->i] && (s[recup->i] < '0' || s[recup->i] > '9'))
		recup->i++;
	return (sum);
}

int	ft_atoi3(const char *s, t_recup *recup)
{
	int	nb;

	nb = 0;
	recup->sum = 0;
	if (s[1] != ' ')
		recup->erreur = 2;
	ft_atoi3_check(s, recup);
	while (s[recup->i] == ' ' || s[recup->i] == '\t' || s[recup->i] == ',' || \
		s[recup->i] == '\n' || s[recup->i] == '\r' || s[recup->i] == '\v' \
		|| s[recup->i] == '\f' || s[recup->i] == 'C' || s[recup->i] == 'F')
	{
		recup->i++;
		nb = 0;
		if (s[recup->i] >= '0' && s[recup->i] <= '9')
			recup->indicateur2++;
		while (s[recup->i] >= '0' && s[recup->i] <= '9')
		{
			nb = (nb * 10) + s[recup->i] - '0';
			recup->sum = (recup->sum * 10) + (s[recup->i] - '0');
			recup->i++;
		}
		if (nb > 255 || nb < 0)
			recup->erreur = 2;
	}
	return (recup->sum);
}

int	ft_path_texture(char *s, char **texture, t_recup *recup, int j)
{
	recup->count2 = 0;
	if (*texture != NULL)
	{
		recup->erreur = 2;
		return (0);
	}
	if (!ft_charinstr(s, '.') || !ft_charinstr(s, '/') || ft_strlen2(s) <= 2)
		recup->erreur = 2;
	while (s[j] != '.')
	{
		if (s[j] != ' ' && s[j] != '.')
			recup->erreur = 2;
		j++;
	}
	*texture = (char *)(malloc(sizeof(char) * (ft_strlen2(s) + 1)));
	if (!(*texture))
		recup->erreur = 2;
	while (s[j])
	{
		(*texture)[recup->count2] = s[j];
		recup->count2++;
		j++;
	}
	(*texture)[recup->count2] = '\0';
	return (0);
}

void	ft_texture(char *str, t_recup *recup)
{
	int			i;
	static int	j;

	i = 0;
	j = 0;
	if (str[i] == 'S' && str[i + 1] == 'O')
		ft_path_texture(str, &recup->no, recup, 2);
	else if (str[i] == 'N' && str[i + 1] == 'O')
		ft_path_texture(str, &recup->so, recup, 2);
	else if (str[i] == 'E' && str[i + 1] == 'A')
		ft_path_texture(str, &recup->we, recup, 2);
	else if (str[i] == 'W' && str[i + 1] == 'E')
		ft_path_texture(str, &recup->ea, recup, 2);
	else if (str[i] == 'S' && str[i + 1] != 'O')
		ft_path_texture(str, &recup->sp, recup, 1);
	else if (str[0] != 'N' && str[0] != 'S' && str[0] \
		!= 'W' && str[0] != 'R' && str[0] != 'F' && \
		str[0] != 'C' && str[0] > 65 && str[0] < 122)
		recup->erreur = 2;
	j++;
}

void	ft_color_resolution(char **str, t_recup *recup, int r)
{
	int	i;

	i = 0;
	recup->i = i;
	if ((recup->sizeline > 0 && r == 0) && (recup->no == NULL || \
		recup->so == NULL || recup->we == NULL \
		|| recup->ea == NULL || recup->sp == NULL))
		recup->erreur = 2;
	if ((recup->no != NULL || recup->so != NULL || recup->we != \
		NULL || recup->ea != NULL || recup->sp \
		!= NULL) && (recup->rx == 0 || recup->ry == 0))
		recup->erreur = 2;
	if (*str[i] == 'R')
	{
		if (recup->rx != 0 && recup->ry != 0)
			recup->erreur = 2;
		recup->rx = ft_atoi2(*str, recup);
		recup->ry = ft_atoi2(*str, recup);
		if (ft_atoi2(*str, recup) > 0 || recup->rx == 0 || recup->ry == 0)
			recup->erreur = 2;
	}
	else if (*str[i] == 'F')
		recup->f = ft_atoi3(*str, recup);
	else if (*str[i] == 'C')
		recup->c = ft_atoi3(*str, recup);
}
