/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saray <saray.jafarzade@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 20:11:24 by saray             #+#    #+#             */
/*   Updated: 2021/05/03 15:46:01 by saray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include<string.h>
# include<sys/types.h>
# include<sys/stat.h>
# include<fcntl.h>
# include<math.h>
# include"../mlx_linux/mlx.h"

# define BUFFER_SIZE 42

# define ROTATE_LEFT	65361
# define ROTATE_RIGHT	65363
# define FORWARD_W_Z	119
# define BACK_S_S	115
# define RIGHT_D_D	100
# define LEFT_A_Q	97

typedef struct s_sprxy
{
	double		x;
	double		y;
}			t_sprxy;

typedef struct s_sprite
{
	int		nbspr;
	int		*order;
	double	*dist;
	double	spritex;
	double	spritey;
	double	invdet;
	double	transformx;
	double	transformy;
	int		spritescreenx;
	int		spriteheight;
	int		drawstartx;
	int		drawstarty;
	int		drawendy;
	int		drawendx;
	int		spritewidth;
	double	*zbuffer;
}	t_sprite;

typedef struct s_texture
{
	int		texdir;
	double	wallx;
	int		texx;
	int		texy;
	double	step;
	double	texpos;
}	t_texture;

typedef struct s_ray
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planx;
	double		plany;
	double		raydirx;
	double		raydiry;
	double		camerax;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	double		perpwalldist;
	int			lineheight;
	int			drawstart;
	int			drawend;
	double		movespeed;
	double		rotspeed;
	int			x;
	int			texture;
}				t_ray;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		forward;
	int		back;
	int		left;
	int		right;
	int		rotate_left;
	int		rotate_right;
	int		minimapechelle;
	int		width;
	int		height;
	void	*img2;
	int		*addr2;
}		t_data;

typedef struct s_recup
{
	int			save;
	int			rx;
	int			ry;
	int			i;
	int			f;
	int			c;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*sp;
	int			erreur;
	int			sizeline;
	int			nblines;
	int			sum;
	int			indicateur;
	int			indicateur2;
	int			indicateur3;
	int			count;
	int			count2;
	int			insidemap;
	int			wrongcharmap;
	char		**map;
	int			linevide;
	int			multiplayers;
	char		depart;
	int			dx;
	int			dy;
	double		perpwalldist;
	int			screenx;
	int			screeny;
	t_sprite	s;
	t_sprxy		*sxy;
	t_ray		ray;
	t_data		data;
	t_data		texture[5];
	t_texture	t;

}				t_recup;

int		ft_chek_img(t_recup *recup);
void	ft_init(t_recup	*recup);
void	ft_init2(t_recup *recup);
void	ft_init_dir(t_recup *recup);
void	ft_init_more(t_recup *recup);
void	ft_init_more3(t_recup *recup);
int		ft_chek_save(char *str);
int		ft_cub(char *str, t_recup *recup);
void	ft_error(t_recup *recup, char	*str);
void	ft_error2(t_recup *recup);
void	ft_verify_errors(t_recup *recup);
int		ft_murs(t_recup	*recup);
int		ft_murs_util(char *str);
void	ft_parsing(char	*fichier, t_recup *recup);
int		get_next_line(int fd, char **line, t_recup *recup);
int		ft_free_buf(char **str, t_recup *recup);
void	ft_color_resolution(char **str, t_recup *recup, int r);
void	ft_map(char *str, t_recup *recup, int r);
int		ft_is_map(char *str, t_recup *recup);
int		ft_copy_map(char *str, t_recup *recup);
int		ft_depart(char c, t_recup *recup, int i, int j);
int		ft_parsing_map(char *fichier, t_recup *recup);
int		ft_strlen2(char *s);
int		ft_strlen(char *s);
char	*get_line(char *str, char **line, int r);
char	*read_line(char *str, int fd, int *r);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char*s);
char	*ft_strchr(const char *str, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_color_resolution(char **str, t_recup *recup, int r);
int		ft_atoi2(const char *str, t_recup *recup);
void	ft_atoi3_check(const char *str, t_recup *recup);
int		ft_nb_virgule(const char *str);
int		ft_charinstr(char *str, char c);
void	ft_texture(char *str, t_recup *recup);
int		ft_path_texture(char *str, char	**texture, t_recup *recup, int j);
void	ft_int_sprite2(t_recup *recup, int i, int j, int v);
void	ft_init_sprite(t_recup *recup);
int		ft_linevide(char *s);
void	ft_init2(t_recup *recup);
void	ft_init3(t_recup *recup);
int		ft_mlx(t_recup *recup);
int		ft_raycasting(t_recup *recup);
void	ft_swap(t_recup *recup);
void	ft_drawstartend(t_recup *recup);
void	ft_incrementray(t_recup *recup);
void	ft_stepsidedist(t_recup *recup);
int		ft_color_column(t_recup *recup);
void	ft_save(t_recup *recup);
int		ft_exit(t_recup	*recup);
void	ft_sprite(t_recup *recup);
void	ft_draw_spr(t_recup *recup, int y, int texx, int stripe);
void	ft_calculs(t_recup *recup, int i);
void	ft_dist_order(t_recup *recup);
void	ft_dist_order2(t_recup *recup);
int		ft_key_press(int keycode, t_recup *recup);
int		ft_key_release(int keycode, t_recup *recup);
void	ft_rotate_left(t_recup *recup, double olddirx);
void	ft_rotate_right_left(t_recup *recup);
void	ft_left_right(t_recup *recup);
void	ft_forward_back(t_recup *recup);
void	ft_draw_texture(t_recup *recup, int x, int y);
void	ft_init_texture(t_recup *recup);
int		ft_del5(char **line, int *fd, char **fichie, t_recup *recup);
void	ft_del5_parsing(char **lin, int *fd, char **fichier, t_recup *recup);
void	ft_norm3_init_r(t_recup	*recup);
void	ft_norm3_s(t_recup *recup);

#endif
