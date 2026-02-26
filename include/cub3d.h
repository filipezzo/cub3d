/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 10:59:17 by fsousa            #+#    #+#             */
/*   Updated: 2026/02/26 13:46:02 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/mlx/mlx.h"
# include "libft.h"
# include <math.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <fcntl.h>
# include <unistd.h>

# define KEY_ESC 65307
# define KEY_ARROW_LEFT 65361
# define KEY_ARROW_RIGHT 65363
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define TEX_N 0
# define TEX_S 1
# define TEX_W 2
# define TEX_E 3
# define TEX_COUNT 4
# define TEX_SIZE 64
# define GAME_WIDTH 720
# define GAME_HEIGHT 400
# define TILE 8
# define MOVE_SPEED 0.013
# define ROT_SPEED 0.0050
# define COL_PAD 0.15

# define NORTH_TGT "NO "
# define SOUTH_TGT "SO "
# define WEST_TGT "WE "
# define EAST_TGT "EA "
# define CEIL_TGT "C "
# define FLOOR_TGT "F "

typedef struct s_world		t_world;
typedef struct s_data		t_data;
typedef struct s_engine		t_engine;

typedef struct s_world
{
	char		**grid;
	int			w;
	int			h;
	double		px;
	double		py;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		fov;
	uint32_t	floor_rgb;
	uint32_t	ceil_rgb;
	uint32_t	wall_rgb;
	char		*tex_path[TEX_COUNT];
	int			__side_tmp;
	int			__tex_tmp;
}				t_world;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			w;
	int			h;
}				t_data;

typedef struct s_engine
{
	void		*mlx;
	void		*win;
	int			win_w;
	int			win_h;
	t_data		frame;
	t_bool		running;
}				t_engine;

typedef struct s_input
{
	t_bool		w;
	t_bool		a;
	t_bool		s;
	t_bool		d;
	t_bool		left;
	t_bool		right;
}				t_input;

typedef struct s_tex
{
	t_data		img;
}				t_tex;

typedef struct s_rect
{
	int			x;
	int			y;
	int			w;
	int			h;
	uint32_t	color;
}				t_rect;

typedef struct s_line
{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	uint32_t	color;
}				t_line;

typedef struct s_dda
{
	double		dx;
	double		dy;
	double		steps;
	double		x;
	double		y;
	double		x_inc;
	double		y_inc;
}				t_dda;

typedef struct s_mm
{
	int			x;
	int			y;
	int			px;
	int			py;
}				t_mm;

typedef struct s_ray
{
	int			x;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			side;
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	double		delta_x;
	double		delta_y;
	double		side_x;
	double		side_y;
	double		perp;
	int			line_h;
	int			draw0;
	int			draw1;
	int			tex_id;
	int			tex_x;
	double		tex_step;
	double		tex_pos;
}				t_ray;

typedef struct s_game
{
	t_engine	eng;
	t_world		world;
	t_input		in;
	t_tex		tex[TEX_COUNT];
}				t_game;

void			world_fake(t_world *out);
void			put_pixel(t_data *img, int x, int y, uint32_t color);
int				engine_init(t_engine *e, int w, int h, const char *title);
int				engine_tick(void *param);
void			engine_shutdown(t_engine *e);
void			engine_register_hooks(t_game *game);
int				on_key_press(int keycode, void *param);
int				on_key_release(int keycode, void *param);
int				on_destroy(void *param);
void			player_update(t_game *game);
void			render_frame(t_game *g);
void			draw_floor_ceil(t_engine *e, t_world *w);
void			raycast_walls(t_game *g);
int				textures_load(t_game *g);
void			textures_destroy(t_game *g);
uint32_t		tex_get_pixel(t_data *img, int x, int y);
int				ray_tex_id(t_ray *r);
void			ray_init(t_ray *r, t_game *g, int x);
int				ray_dda(t_ray *r, t_world *w);
void			ray_project(t_ray *r, t_game *g);
void			ray_draw_column(t_game *g, t_ray *r);
void			game_shutdown(t_game *g);
void			build_move_vec(double v[2], t_world *w, t_input *in);
void			render_minimap(t_game *game);

void			draw_rect(t_data *img, t_rect r);
void			draw_line(t_data *img, t_line l);
int				clamp_int(int v, int lo, int hi);

void			parse(char *fpath, t_world *world);
t_bool			analize_map(t_world *world);
t_bnode			*get_start_map(t_dlist *lines);
void			count_map_size(t_world *world, t_bnode *node);
void			new_rawmap(t_world *world, t_bnode *node);
char			**dupmap(t_world *world);
void			set_player_pos(t_world *world, int y);
void			set_player_dir(t_world *world, char tgt);
t_bool			load_color(uint32_t *color, const char *str);
t_bool			load_texture(t_world *world, int tgt, char *path);
int				validate_fpath(char *fpath, char *ext);
void			set_vec2(double x, double y, double *tx, double *ty);

void			safe_close_fd(int fd);
void			destroy_cmtx_rev(char **cmtx, int i);
void			pinfo(const char *msg);
void			perr(const char *msg);
void			perr_exit(const char *msg, int status_code);
t_bool			perr_failed(const char *msg);

#endif